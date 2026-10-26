// KingIcons — 复刻原版图标工厂（FUN_00755c86 加载器 + FUN_007572ac 工厂，docs/phase12-findings.md）
// 机制：king.svg 精灵表（302 命名元素，id 即 king:: 名）+ icon.theme CSS 注入
//      + QSvgRenderer elementExists→boundsOnElement→render（与原版同 API 同源文件）。
// 经 dlopen 调 libQt5Svg.so.5（QtSvg 开发头缺失的折衷，符号经 nm 验证一致）。
// 注意：构造函数 ABI 为隐含 this（RDI）——须预分配对象内存并显式传 this。
#pragma once
#include <QByteArray>
#include <QFile>
#include <QIcon>
#include <QImage>
#include <QPainter>
#include <QPixmap>
#include <QRectF>
#include <QString>
#include <dlfcn.h>

#include "core/Assets.h"

namespace KingIcons {

namespace detail {
// C++ 成员函数 ABI：this 为首参（RDI）；构造函数无返回值
using RendererNew = void (*)(void *, const QByteArray &, void *); // (this, contents, parent)
using RendererDel = void (*)(void *);                              // (this)
using IsValid = bool (*)(void *);                                  // (this)
using ElementExists = bool (*)(void *, const QString &);           // (this, id)
using BoundsOnElement = QRectF (*)(void *, const QString &);       // (this, id)
using RenderElem = void (*)(void *, QPainter *, const QString &, const QRectF &); // (this, painter, id, bounds)

inline constexpr int kRendererBytes = 256; // QSvgRenderer 实际约 ~88B，冗余分配

inline void *lib() {
    static void *h = dlopen("libQt5Svg.so.5", RTLD_LAZY | RTLD_GLOBAL);
    return h;
}
template <typename T> T sym(const char *n) {
    return reinterpret_cast<T>(dlsym(lib(), n));
}
} // namespace detail

inline QString readText(const QString &path) {
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly))
        return QString();
    return QString::fromUtf8(f.readAll());
}

// 按元素名渲染图标（任意分辨率矢量，主题色由 icon.theme CSS 决定）
inline QIcon icon(const QString &element, const QString &theme, int px = 32) {
    using namespace detail;
    QString svg = readText(Assets::dir() + QStringLiteral("/themes/default/images/king.svg"));
    if (svg.isEmpty())
        return QIcon();
    QString css = readText(Assets::dir() + QStringLiteral("/themes/%1/icon.theme").arg(theme));
    if (css.isEmpty())
        css = readText(Assets::dir() + QStringLiteral("/themes/default/images/icon.theme"));
    if (!css.isEmpty()) {
        // 原版 svg 头的 <?xml-stylesheet href="icon.theme"?> 由加载器实现；QtSvg 不支持外链，改为注入 <style>
        const int ins = svg.indexOf(QLatin1Char('>'), svg.indexOf(QStringLiteral("<svg"))) + 1;
        svg.insert(ins, QStringLiteral("<style type=\"text/css\">") + css + QStringLiteral("</style>"));
    }
    auto New = sym<RendererNew>("_ZN12QSvgRendererC1ERK10QByteArrayP7QObject");
    auto Del = sym<RendererDel>("_ZN12QSvgRendererD1Ev");
    auto Valid = sym<IsValid>("_ZNK12QSvgRenderer7isValidEv");
    auto Exists = sym<ElementExists>("_ZNK12QSvgRenderer13elementExistsERK7QString");
    auto Bounds = sym<BoundsOnElement>("_ZNK12QSvgRenderer15boundsOnElementERK7QString");
    auto Render = sym<RenderElem>("_ZN12QSvgRenderer6renderEP8QPainterRK7QStringRK6QRectF");
    if (!New || !Del || !Valid || !Exists || !Bounds || !Render)
        return QIcon();

    const QByteArray data = svg.toUtf8();
    void *mem = aligned_alloc(alignof(void *), kRendererBytes);
    New(mem, data, nullptr);
    QIcon result;
    if (Valid(mem) && Exists(mem, element)) {
        const QRectF b = Bounds(mem, element);
        if (b.width() > 0 && b.height() > 0) {
            QImage img(px, px, QImage::Format_ARGB32_Premultiplied);
            img.fill(Qt::transparent);
            QPainter p(&img);
            p.setRenderHint(QPainter::Antialiasing);
            const qreal s = qMin(px / b.width(), px / b.height());
            const QRectF target((px - b.width() * s) / 2.0, (px - b.height() * s) / 2.0,
                                b.width() * s, b.height() * s);
            Render(mem, &p, element, target);
            p.end();
            result = QIcon(QPixmap::fromImage(img));
        }
    }
    Del(mem);
    free(mem);
    return result;
}

} // namespace KingIcons
