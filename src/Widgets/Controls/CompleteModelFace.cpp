#include "Widgets/Controls/CompleteModelFace.h"

CompleteModelFace::CompleteModelFace(QObject *parent)
    : QAbstractListModel(parent)
{
}

// CompleteModel_dtor(0x00955856,1282B)— cited:逐行释放三层容器。
CompleteModelFace::~CompleteModelFace() = default;

// CompleteModel_vt15(0x00955d70,85B)rowCount 真身(asn 0x955d70-0x955dc4 全读):
//   门:index 有效(row>=0 && col>=0 && internal!=0)→ 返回 0
//       (即只有「根」这一层有行;子层恒 0)
//   +0x18 为空 → 0
//   否则:
//     n1 = ([+0x50] - [+0x58]) >> 3
//     n2 = ([+0x68] - [+0x48]) >> 3
//     n3 = ([+0x40] - [+0x30]) >> 3
//     return n1 + (n2 - 1) * 0x40 + n3
//   (0x40 = 64,每组 64 行;三组控件分别是「前段/中段/后段」,
//    中段占 (n2-1) 个整组 —— 与补全列表「候选分页」相符)
int CompleteModelFace::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid())
		return 0; // 子层无行
	auto *c = static_cast<const char *>(m_holder18);
	if (c == nullptr)
		return 0;
	const qint64 n1 = (*reinterpret_cast<const qint64 *>(c + 0x50)
	                   - *reinterpret_cast<const qint64 *>(c + 0x58)) >> 3;
	const qint64 n2 = (*reinterpret_cast<const qint64 *>(c + 0x68)
	                   - *reinterpret_cast<const qint64 *>(c + 0x48)) >> 3;
	const qint64 n3 = (*reinterpret_cast<const qint64 *>(c + 0x40)
	                   - *reinterpret_cast<const qint64 *>(c + 0x30)) >> 3;
	return int(n1 + (n2 - 1) * 0x40 + n3);
}
