#include "ThemeIcons.h"

#include <QBitmap>
#include <QColor>
#include <QIconEngine>
#include <QList>
#include <QPainter>
#include <QPixmap>
#include <QSize>

namespace {

// FUN_00639200(98B):SvgIconEngine ctor 转写 —— QIconEngine 基 +
// 名字引用 @+8 + scale 1.0 @+0x10 + 三清零域(@+0x18/20/28)。
// paint/render 体语料另处(引擎视觉输出面;cited — wave-2):
// 本引擎对 QIcon 为不透明载体(缓存命中路径不触发绘制)。
class SvgIconEngine : public QIconEngine {
public:
	explicit SvgIconEngine(const QString &name)
		: m_name(name)
		, m_scale(1.0)   // 语料 0x3ff0000000000000
	{
	}
	// QIconEngine 纯虚/虚覆盖 — cited — wave-2(绘制体未转写;
	// 引擎为缓存载体,命中路径不触发绘制)
	void paint(QPainter *, const QRect &, QIcon::Mode,
	           QIcon::State) override
	{
	}
	QIconEngine *clone() const override
	{
		return new SvgIconEngine(m_name);
	}
	QPixmap pixmap(const QSize &size, QIcon::Mode, QIcon::State) override
	{
		return QPixmap(size);
	}
	QSize actualSize(const QSize &size, QIcon::Mode,
	                 QIcon::State) override
	{
		return size;
	}

private:
	QString m_name;        // +8(引用计数复制)
	double m_scale;        // +0x10 = 1.0
	quint64 m_f1 = 0;      // +0x18
	quint64 m_f2 = 0;      // +0x20
	quint64 m_f3 = 0;      // +0x28
};

// iconCache_lookupEntry(005df09e,1006B):sorted 名→QIcon 查/插。
// 语料深层 = 自定义节点结构(0x20 头/{ref,used,cap,count} +
// +0x100 子表 + FUN_005de1a4 节点插)—— cited — wave-2(容器内部
// 表示);行为面 = 排序查得直返/未查得插默认(QMap 承载)。
QIcon &iconCache_lookupEntry(const QByteArray &name)
{
	static QMap<QByteArray, QIcon> s_cache;   // DAT_011c1ce0→+0x38 表
	return s_cache[name];
}

// FUN_00756b68(331B):着色循环转写 —— availableSizes → 每尺寸:
//   pixmap → createMaskFromColor(color,MaskOutColor) → fill(color)
//   → setMask → addPixmap
QIcon recolorIcon(const QIcon &src, const QColor &color)
{
	QIcon out;
	const auto sizes = src.availableSizes();
	for (const QSize &sz : sizes) {
		QPixmap pm = src.pixmap(sz);
		const QBitmap mask =
		    pm.createMaskFromColor(color, Qt::MaskOutColor);
		pm.fill(color);
		pm.setMask(mask);
		out.addPixmap(pm);
	}
	return out;
}

} // namespace

namespace ThemeIcons {

// 00756cd6(1272B)语料转写
QIcon loadSvg(const QString &name, const QString &recolor)
{
	QIcon icon;                                    // 语料 QIcon(out)
	if (name.isEmpty())
		return icon;                               // 语料空名短路
	// iconCache 查得 → 取条目 QIcon(语料二分 + operator= 路径)
	QIcon &cached = iconCache_lookupEntry(name.toUtf8());
	if (!cached.isNull()) {
		icon = cached;
		return icon;                               // 语料命中直返
	}
	// 未命中:名含 "::" 或 toLower().endsWith(".svg") →
	//   SvgIconEngine(name) 包装(00666xxx 区调用点/FUN_00639200)
	const bool svgPath = name.contains(QStringLiteral("::"))
	                     || name.toLower().endsWith(
	                         QStringLiteral(".svg"));
	if (svgPath) {
		icon = QIcon(new SvgIconEngine(name));     // FUN_00639200
	}
	// iconCache_lookupEntry 入缓存(00669xxx 区)
	QIcon &slot = iconCache_lookupEntry(name.toUtf8());
	if (slot.isNull())
		slot = icon;
	// 非空 && recolor 有效色名 → FUN_00756b68 着色(00669b8a 区)
	if (!icon.isNull() && QColor::isValidColor(recolor)) {
		icon = recolorIcon(icon, QColor(recolor));
	}
	return icon;
}

} // namespace ThemeIcons
