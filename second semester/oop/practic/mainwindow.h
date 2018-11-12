#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "controller.h"
#include "qlineedit.h"
#include "qgridlayout.h"
#include "QListWidget"
#include "observer.h"

class MainWindow : public QWidget, public Observer
{
    Q_OBJECT

public:
    explicit MainWindow(Controller ctrl, QWidget *parent = 0);
    void update() override;
    ~MainWindow();

private:
    Controller ctrl;
    QLineEdit* input;
    QListWidget* results;
    QGridLayout* main_zone;

public slots:
    void handleSearch(QString);

signals:
    void refresh();

};

#endif // MAINWINDOW_H
