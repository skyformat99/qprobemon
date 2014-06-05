#pragma once

#include <QObject>

class MacAddress
{
public:
    MacAddress(const quint8 *mac);

    QString toString() const;
    QString getOUID() const;
    QString getManufacturer() const;

    bool operator<(const MacAddress &mac) const;

private:
    QByteArray m_mac;

    static const QString MANUF_FILE;
};