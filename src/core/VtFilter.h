#pragma once

#include <QByteArray>
#include <QColor>
#include <QString>

class VtFilter
{
public:
    QString feed(const QByteArray &data);
    QColor currentFg() const { return m_fg; }
    QColor currentBg() const { return m_bg; }
    bool takeClearRequest();

private:
    enum State { Normal, Escape, Csi, Osc, OscEscape };

    void processChar(QChar ch, QString &html);
    void applySgr(const QString &params);
    void appendStyled(QChar ch, QString &html);

    State m_state = Normal;
    QByteArray m_csi;
    QByteArray m_pendingUtf8;
    QColor m_fg;
    QColor m_bg;
    bool m_bold = false;
    bool m_underline = false;
    bool m_clearRequested = false;
    bool m_spanOpen = false;
    QString m_openStyle;
};
