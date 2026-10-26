#pragma once

#include <QByteArray>
#include <QString>

class ScreenModel;

class VtParser
{
public:
    explicit VtParser(ScreenModel *screen);

    void feed(const QByteArray &data);

private:
    enum State { Normal, Escape, Csi, Osc, OscEscape, Dcs, DcsEscape };

    void processChar(QChar ch);
    void dispatchCsi(QChar finalChar);

    ScreenModel *m_screen;
    State m_state = Normal;
    QByteArray m_pendingUtf8;
    QString m_csi;
};
