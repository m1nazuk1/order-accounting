#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    private slots:
        void actionOpenFile();
    void actionSaveFile();
    void actionExit();
    void actionAdd();
    void actionEdit();
    void actionSortAsc();
    void actionSortDesc();
    void actionSearch();
    void actionFilter();
    void actionAbout();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QSortFilterProxyModel *proxy;

    void loadData(const QString &path);
    void saveData(const QString &path);
};

#endif