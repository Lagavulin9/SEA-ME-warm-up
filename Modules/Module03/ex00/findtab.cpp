#include "findtab.h"
#include "finddialog.h"

#include <QtWidgets>
#include <QTabWidget>

//! [0]
FindTab::FindTab(QWidget *parent):
    QTabWidget(parent),
    proxyModel(new QSortFilterProxyModel(this)),
    findTable(new TableModel(this))
{
    auto mainLayout = new QVBoxLayout;
    proxyModel->setSourceModel(findTable);
    proxyModel->setFilterKeyColumn(0);

    QTableView *tableView = new QTableView;
    tableView->setModel(proxyModel);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->verticalHeader()->hide();
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->setSortingEnabled(true);

    connect(tableView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &FindTab::selectionChanged);

    connect(this, &QTabWidget::currentChanged, this, [this, tableView](int tabIndex) {
        if (widget(tabIndex) == tableView)
            emit selectionChanged(tableView->selectionModel()->selection());
    });
    mainLayout->addWidget(tableView);

    auto descriptionLabel = new QLabel(tr("Search contact by name\n"));
    auto addButton = new QPushButton(tr("Find"));
    connect(addButton, &QAbstractButton::clicked, this, &FindTab::findEntry);

    mainLayout->addWidget(descriptionLabel, 0, Qt::AlignCenter);
    mainLayout->addWidget(addButton, 0, Qt::AlignCenter);

    setLayout(mainLayout);
}
//! [0]

//! [1]
void FindTab::findEntry()
{
    FindDialog findDialog;

    if (findDialog.exec())
    {
        QString toFind = findDialog.getFindText();
        proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
        proxyModel->setFilterFixedString(toFind);
    }
}
//! [1]

TableModel* FindTab::getTable()
{
    return findTable;
}
