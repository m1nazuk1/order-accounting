#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adddialog.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QInputDialog>
#include <QMenuBar>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // это параша вроде прокси-модель называется хз
    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels(
        QStringList() << "Номер заказа"
                      << "Покупатель"
                      << "Товар"
                      << "Скидка"
                      << "Доставка"
    );

    proxy = new QSortFilterProxyModel(this);
    proxy->setSourceModel(model);
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy->setFilterKeyColumn(-1);
    ui->tableView->setModel(proxy);

    // тут короче настройка менюхи
    QMenu *fileMenu = menuBar()->addMenu("Файл");
    QAction *openAct = fileMenu->addAction("Открыть");
    QAction *saveAct = fileMenu->addAction("Сохранить");
    QAction *exitAct = fileMenu->addAction("Выход");

    QMenu *actionsMenu = menuBar()->addMenu("Действия");
    QAction *addAct = actionsMenu->addAction("Добавить");
    QAction *editAct = actionsMenu->addAction("Редактировать");
    QAction *sortAscAct = actionsMenu->addAction("Сортировка по возрастанию");
    QAction *sortDescAct = actionsMenu->addAction("Сортировка по убыванию");
    QAction *searchAct = actionsMenu->addAction("Поиск");
    QAction *filterAct = actionsMenu->addAction("Фильтрация");

    QMenu *helpMenu = menuBar()->addMenu("Справка");
    QAction *aboutAct = helpMenu->addAction("О программе");

    // коннекты, возможно чет не так сделал, но я уже не помню как оно пишется
    connect(openAct, &QAction::triggered, this, &MainWindow::actionOpenFile);
    connect(saveAct, &QAction::triggered, this, &MainWindow::actionSaveFile);
    connect(exitAct, &QAction::triggered, this, &MainWindow::actionExit);

    connect(addAct, &QAction::triggered, this, &MainWindow::actionAdd);
    connect(editAct, &QAction::triggered, this, &MainWindow::actionEdit);
    connect(sortAscAct, &QAction::triggered, this, &MainWindow::actionSortAsc);
    connect(sortDescAct, &QAction::triggered, this, &MainWindow::actionSortDesc);
    connect(searchAct, &QAction::triggered, this, &MainWindow::actionSearch);
    connect(filterAct, &QAction::triggered, this, &MainWindow::actionFilter);

    connect(aboutAct, &QAction::triggered, this, &MainWindow::actionAbout);

    // у нас есть базовый orders.csv и при загрузке проги он сразу подгружается чтобы не начинать всегда по новой если вдруг забыл сохранить, но если что можно еще один файлик сохранить условно
    loadData("orders.csv");
}

MainWindow::~MainWindow() {
    // тут мы записываем в этот ордерс при выходе из проги чтобы когда потом зашли уже были наши введенные данные
    saveData("orders.csv");
    delete ui;
}

void MainWindow::actionOpenFile() {
    QString path = QFileDialog::getOpenFileName(
        this,
        "Открыть файл",
        "",
        "CSV Files (*.csv);;All Files (*.*)"
    );
    if(path.isEmpty()) return;

    model->removeRows(0, model->rowCount());
    loadData(path);
}

void MainWindow::actionSaveFile() {
    QString path = QFileDialog::getSaveFileName(
        this,
        "Сохранить файл",
        "",
        "CSV Files (*.csv);;All Files (*.*)"
    );
    if(path.isEmpty()) return;

    saveData(path);
}

void MainWindow::actionExit() {
    close();
}

void MainWindow::actionAdd() {
    AddDialog dlg(this);
    if(dlg.exec() == QDialog::Accepted) {
        QList<QStandardItem*> items;
        items << new QStandardItem(dlg.orderNumber())
              << new QStandardItem(dlg.customer())
              << new QStandardItem(dlg.product())
              << new QStandardItem(dlg.discount() ? "Да" : "Нет")
              << new QStandardItem(dlg.shipping() ? "Да" : "Нет");
        model->appendRow(items);
    }
}

void MainWindow::actionEdit() {
    QModelIndex index = ui->tableView->currentIndex();
    if(!index.isValid()) return;

    int row = proxy->mapToSource(index).row();
    QString number = model->item(row,0)->text();
    QString cust   = model->item(row,1)->text();
    QString prod   = model->item(row,2)->text();
    bool disc      = (model->item(row,3)->text() == "Да");
    bool ship      = (model->item(row,4)->text() == "Да");

    AddDialog dlg(this);
    dlg.setOrderNumber(number);
    dlg.setCustomer(cust);
    dlg.setProduct(prod);
    dlg.setDiscount(disc);
    dlg.setShipping(ship);

    if(dlg.exec() == QDialog::Accepted) {
        model->setItem(row,0,new QStandardItem(dlg.orderNumber()));
        model->setItem(row,1,new QStandardItem(dlg.customer()));
        model->setItem(row,2,new QStandardItem(dlg.product()));
        model->setItem(row,3,new QStandardItem(dlg.discount() ? "Да":"Нет"));
        model->setItem(row,4,new QStandardItem(dlg.shipping() ? "Да":"Нет"));
    }
}

void MainWindow::actionSortAsc() {
    proxy->sort(0, Qt::AscendingOrder);
}

void MainWindow::actionSortDesc() {
    proxy->sort(0, Qt::DescendingOrder);
}

void MainWindow::actionSearch() {
    bool ok;
    QString text = QInputDialog::getText(
        this, "Поиск", "Введите строку:",
        QLineEdit::Normal, "", &ok
    );
    if(!ok || text.isEmpty()) return;

    for(int r=0; r<model->rowCount(); r++) {
        for(int c=0; c<model->columnCount(); c++) {
            QString val = model->item(r,c)->text();
            if(val.contains(text, Qt::CaseInsensitive)) {
                ui->tableView->selectRow(
                    proxy->mapFromSource(model->index(r,c)).row()
                );
                return;
            }
        }
    }
    QMessageBox::information(this,"Поиск","Ничего не найдено");
}

void MainWindow::actionFilter() {
    bool ok;
    QString text = QInputDialog::getText(
        this, "Фильтрация", "Введите строку:",
        QLineEdit::Normal, "", &ok
    );
    if(!ok) return;
    proxy->setFilterRegExp(text);
}

void MainWindow::actionAbout() {
    QMessageBox::information(
        this,
        "О программе",
        "Приложение для учёта выполненных заказов.\n"
        "Борисов Д. С., Афанасьева Ю. Р."
    );
}


void MainWindow::loadData(const QString &path) {
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if(line.isEmpty()) continue;

        QStringList parts = line.split(";");
        if(parts.size() < 5) continue;

        QList<QStandardItem*> row;
        for(const QString &p : parts) {
            row << new QStandardItem(p);
        }
        model->appendRow(row);
    }
    file.close();
}


void MainWindow::saveData(const QString &path) {
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    QTextStream out(&file);
    for(int r=0; r < model->rowCount(); r++) {
        QStringList parts;
        for(int c=0; c < model->columnCount(); c++) {
            parts << model->item(r,c)->text().replace(';',',');
        }
        out << parts.join(";") << "\n";
    }
    file.close();
}