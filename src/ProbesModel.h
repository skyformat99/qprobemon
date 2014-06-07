#pragma once

#include <QAbstractItemModel>
#include "ProbeStore.h"
#include <assert.h>

class ProbesModel : public QAbstractItemModel
{
    Q_OBJECT;

public:
    ProbesModel(ProbeStore &store);
    virtual ~ProbesModel();

    QModelIndex index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    int columnCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

signals:
    void statusMessage(const QString& message);

public slots:
    void newStation();
    void newSSID(MacAddress mac);

private:
    ProbeStore &m_store;
};
