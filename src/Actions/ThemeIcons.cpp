#include "ThemeIcons.h"

#include <QBitmap>
#include <QColor>
#include <QDir>
#include <QFile>
#include <QIconEngine>
#include <QList>
#include <QPainter>
#include <QPixmap>
#include <QSize>
#include <QSvgRenderer>

// 主题目录(语料 DAT_011c1ce0 主题容器面;主题系统装配期设置)
static QString g_themeDir;

namespace {

// FUN_00639200(98B):SvgIconEngine ctor 转写 —— QIconEngine 基 +
// 名字引用 @+8 + scale 1.0 @+0x10 + 三清零域(@+0x18/20/28)。
// 渲染 = QSvgRenderer 委托(语料 QtSvg 符号族实证:0001.c
// QSvgRenderer::render/isValid;混合架构边界,同 libssh 策略)。
// pixmap 缓存 = +0x18/+0x20/+0x28 QList((mode<<4|state) 打包键,
// FUN_0063a000 504B 扩容/插入语料)。
class SvgIconEngine : public QIconEngine {
public:
	explicit SvgIconEngine(const QString &name)
		: m_name(name)
		, m_scale(1.0)   // 语料 0x3ff0000000000000
	{
	}

	QIconEngine *clone() const override   // 语料 SvgIconEngine_vt8(366B)
	{
		return new SvgIconEngine(m_name);
	}

	// 语料 SvgIconEngine_h6393e6(619B):缓存查(mode<<4|state 键)
	// → 未命中渲染(FUN_0063a000 插入 + QSvgRenderer 委托)
	QPixmap pixmap(const QSize &size, QIcon::Mode mode,
	               QIcon::State state) override
	{
		const int key = ((int)mode << 4) | (int)state;
		for (const auto &e : m_cache) {
			if (e.key == key && !e.pm.isNull())
				return e.pm;
		}
		QPixmap pm = render(size);   // FUN_0063a000 插入位
		CacheEntry e;
		e.key = key;
		e.pm = pm;
		m_cache.append(e);           // 语料扩容/插入(0x28 步长条目)
		return pm;
	}

	QSize actualSize(const QSize &size, QIcon::Mode,
	                 QIcon::State) override
	{
		return size;
	}

	void paint(QPainter *painter, const QRect &rect, QIcon::Mode mode,
	           QIcon::State state) override
	{
		const QPixmap pm = pixmap(rect.size(), mode, state);
		if (!pm.isNull())
			painter->drawPixmap(rect, pm);
	}

private:
	struct CacheEntry
	{
		int key = 0;
		QPixmap pm;
	};
	QPixmap render(const QSize &size) const
	{
		if (g_themeDir.isEmpty() || m_name.isEmpty())
			return QPixmap();
		// 主题 SVG 文件:themeDir/name(.svg 后缀语义见
		// theme_icon_load_svg 的 .endsWith 门)
		QString base = m_name;
		if (!base.endsWith(QStringLiteral(".svg"), Qt::CaseInsensitive))
			base += QStringLiteral(".svg");
		const QString path = g_themeDir + QLatin1Char('/') + base;
		QFile f(path);
		if (!f.open(QIODevice::ReadOnly))
			return QPixmap();
		QSvgRenderer renderer(f.readAll());
		if (!renderer.isValid())
			return QPixmap();
		QPixmap pm(size);
		pm.fill(Qt::transparent);
		QPainter p(&pm);
		renderer.render(&p, QRectF(pm.rect()));
		return pm;
	}

	QString m_name;             // +8(引用计数复制)
	double m_scale = 1.0;       // +0x10 = 1.0
	quint64 m_f1 = 0;           // +0x18(缓存表语料 +0x18/20/28 区)
	QList<CacheEntry> m_cache;  // 语料 pixmap 缓存(FUN_0063a000)
};

// iconCache_lookupEntry(005df09e,1006B):sorted 名→QIcon 查/插。
// 语料深层 = 自定义节点结构(0x20 头/{ref,used,cap,count} +
// +0x100 子表 + FUN_005de1a4 节点插)—— 容器内部表示(行为面 =
// 排序查得直返/未查得插默认,QMap 承载;节点表示非行为面)
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

void setThemeDir(const QString &dir) { g_themeDir = dir; }

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
	//   SvgIconEngine(name) 包装(00639200)
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
