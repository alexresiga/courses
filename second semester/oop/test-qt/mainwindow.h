#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller.h"
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Controller c,QWidget *parent = 0);
    ~MainWindow();

private:
    Controller ctrl;
    QListWidget* elements;
    QLineEdit* search_query;
    QPushButton* showBest;
public slots:
    void populate();
    void handleSearch(QString);
    void handleBestMatch();


signals:
    void refresh();
};

#endif // MAINWINDOW_H
