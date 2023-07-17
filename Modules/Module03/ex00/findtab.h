#ifndef FINDTAB_H
#define FINDTAB_H

#include "tablemodel.h"

#include <QItemSelection>
#include <QTabWidget>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QVBoxLayout;
class QItemSelectionModel;
class QSortFilterProxyModel;
QT_END_NAMESPACE

//! [0]
class FindTab : public QTabWidget
{
    Q_OBJECT

public:
    FindTab(QWidget *parent = nullptr);
    TableModel *getTable();

public slots:
    void findEntry();

private:
    QSortFilterProxyModel *proxyModel;
    TableModel *findTable;

signals:
    void sendArg(const QString &arg);
    void selectionChanged (const QItemSelection &selected);

};
//! [0]

#endif
