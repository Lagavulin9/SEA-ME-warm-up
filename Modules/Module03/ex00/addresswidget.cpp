/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "addresswidget.h"
#include "adddialog.h"
#include <QDebug>

#include <QtWidgets>

//! [0]
AddressWidget::AddressWidget(QWidget *parent)
    : QTabWidget(parent),
      findTab(new FindTab(this)),
      table(new TableModel(this))
{
    setContactTab();

    addTab(findTab, tr("Search"));
}
//! [0]

//! [2]
void AddressWidget::showAddEntryDialog()
{
    AddDialog aDialog;

    if (aDialog.exec())
        addEntry(aDialog.name(), \
                 aDialog.address(), \
                 aDialog.email(), \
                 aDialog.phonenumber());
}
//! [2]

//! [3]
void AddressWidget::addEntry(const QString &name, \
                             const QString &address, \
                             const QString &email, \
                             const QString &phonenumber)
{
    table->insertRows(0, 1, QModelIndex());

    QModelIndex index = table->index(0, 0, QModelIndex());
    table->setData(index, name, Qt::EditRole);
    index = table->index(0, 1, QModelIndex());
    table->setData(index, address, Qt::EditRole);
    index = table->index(0, 2, QModelIndex());
    table->setData(index, email, Qt::EditRole);
    index = table->index(0, 3, QModelIndex());
    table->setData(index, phonenumber, Qt::EditRole);

    findTab->testTable->insertRows(0, 1, QModelIndex());
    QModelIndex testIndex = findTab->testTable->index(0, 0, QModelIndex());
    findTab->testTable->setData(testIndex, name, Qt::EditRole);
    testIndex = findTab->testTable->index(0, 1, QModelIndex());
    findTab->testTable->setData(testIndex, address, Qt::EditRole);
    testIndex = findTab->testTable->index(0, 2, QModelIndex());
    findTab->testTable->setData(testIndex, email, Qt::EditRole);
    testIndex = findTab->testTable->index(0, 3, QModelIndex());
    findTab->testTable->setData(testIndex, phonenumber, Qt::EditRole);
}
//! [3]

//! [4a]
void AddressWidget::editEntry()
{
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    const QModelIndexList indexes = selectionModel->selectedRows();
    QString name;
    QString address;
    QString email;
    QString phonenumber;
    int row = -1;

    for (const QModelIndex &index : indexes) {
        row = proxy->mapToSource(index).row();
        QModelIndex nameIndex = table->index(row, 0, QModelIndex());
        QVariant varName = table->data(nameIndex, Qt::DisplayRole);
        name = varName.toString();

        QModelIndex addressIndex = table->index(row, 1, QModelIndex());
        QVariant varAddr = table->data(addressIndex, Qt::DisplayRole);
        address = varAddr.toString();

        QModelIndex emailIndex = table->index(row, 2, QModelIndex());
        QVariant varEmail = table->data(emailIndex, Qt::DisplayRole);
        email = varEmail.toString();

        QModelIndex phonenumberIndex = table->index(row, 3, QModelIndex());
        QVariant varPhoneNumber = table->data(phonenumberIndex, Qt::DisplayRole);
        phonenumber = varPhoneNumber.toString();
    }
//! [4a]

//! [4b]
    AddDialog aDialog;
    aDialog.setWindowTitle(tr("Edit a Contact"));
    aDialog.editAddress(name, address, email, phonenumber);

    if (aDialog.exec()) {
        const QString newAddress = aDialog.address();
        const QString newEmail = aDialog.email();
        const QString newPhonenumber = aDialog.phonenumber();

        QModelIndex index = table->index(row, 1, QModelIndex());
        table->setData(index, newAddress, Qt::EditRole);
        findTab->testTable->setData(index, newAddress, Qt::EditRole);

        index = table->index(row, 2, QModelIndex());
        table->setData(index, newEmail, Qt::EditRole);
        findTab->testTable->setData(index, newEmail, Qt::EditRole);

        index = table->index(row, 3, QModelIndex());
        table->setData(index, newPhonenumber, Qt::EditRole);
        findTab->testTable->setData(index, newPhonenumber, Qt::EditRole);
    }
}
//! [4b]

//! [5]
void AddressWidget::removeEntry()
{
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    const QModelIndexList indexes = selectionModel->selectedRows();

    for (QModelIndex index : indexes) {
        int row = proxy->mapToSource(index).row();
        table->removeRows(row, 1, QModelIndex());
        findTab->testTable->removeRows(row, 1, QModelIndex());
    }
}
//! [5]

//! [1]
void AddressWidget::setContactTab()
{
    auto proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(table);
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
            this, &AddressWidget::selectionChanged);

    connect(this, &QTabWidget::currentChanged, this, [this, tableView](int tabIndex) {
        if (widget(tabIndex) == tableView)
            emit selectionChanged(tableView->selectionModel()->selection());
    });

    addTab(tableView, "Contacts");
}
//! [1]

//! [7]
void AddressWidget::readFromFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }

    QVector<Contact> contacts;
    QDataStream in(&file);
    in >> contacts;

    if (contacts.isEmpty()) {
        QMessageBox::information(this, tr("No contacts in file"),
                                 tr("The file you are attempting to open contains no contacts."));
    } else {
        for (const auto &contact: qAsConst(contacts))
            addEntry(contact.getName(), contact.getAddress(), contact.getEmail(), contact.getPhoneNumber());
    }
}
//! [7]

//! [6]
void AddressWidget::writeToFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }

    QDataStream out(&file);
    out << table->getContacts();
}
//! [6]
