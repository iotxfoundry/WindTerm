#include <QVariant>
#include <QList>
#include <QMap>
#include <QString>
#include <QStringList>
#include <yaml-cpp/yaml.h>

#include <cstdio>

// WindTerm 配置桥 —— 逆向自 0x00a7ecde yaml_toQVariant(1302B)。
//
// 二进制形态:FUN_00aee9d0(5B)直读 node+8 的预解析类型字节
// (WindTerm 对 yaml-cpp Node 的包装已把标量解析成 8 类:
//  0 null / 1 int64 / 2 uint64 / 3 double / 4 string / 5 bool /
//  6 sequence / 7 map),再按类构造 QVariant;序列与映射递归,
// 映射分支与 TextView::setProperty 同款 QMap createNode(0x30 节点,
// key@+0x18 引用计数复制,value@+0x20)。
//
// 本文件用 vendored src/yaml-cpp(0.6.3)写等价真实现;标量类型
// 判定顺序(int → uint → double → bool → string 兜底)对应包装层
// 的预解析语义。

QVariant yamlToQVariant(const YAML::Node &node)
{
	switch (node.Type()) {
	case YAML::NodeType::Null:
	case YAML::NodeType::Undefined:
		return QVariant();
	case YAML::NodeType::Scalar: {
		// 8 类标签中的 1/2/3/5/4 依序尝试(逆向序)
		try { return QVariant(node.as<long long>()); }
		catch (const YAML::BadConversion &) {}
		try { return QVariant(node.as<unsigned long long>()); }
		catch (const YAML::BadConversion &) {}
		try { return QVariant(node.as<double>()); }
		catch (const YAML::BadConversion &) {}
		try { return QVariant(node.as<bool>()); }
		catch (const YAML::BadConversion &) {}
		return QVariant(QString::fromUtf8(node.Scalar().c_str()));
	}
	case YAML::NodeType::Sequence: {
		QVariantList list;
		for (const auto &item : node)
			list.append(yamlToQVariant(item));
		return QVariant(list);
	}
	case YAML::NodeType::Map: {
		QVariantMap map;
		for (const auto &kv : node)
			map.insert(QString::fromUtf8(kv.first.Scalar().c_str()),
			           yamlToQVariant(kv.second));
		return QVariant(map);
	}
	}
	return QVariant();
}

// yaml_loadFile(0x00a7fbc8)/yaml_readFile(0x00a9367e)的同族便捷入口:
// wind.config / wind.variables 读取路径
QVariant yamlLoadToVariant(const QString &path)
{
	try {
		return yamlToQVariant(YAML::LoadFile(path.toUtf8().constData()));
	} catch (const YAML::Exception &) {
		return QVariant();
	}
}
