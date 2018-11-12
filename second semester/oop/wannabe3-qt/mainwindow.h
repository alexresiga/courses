#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <controller.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qgridlayout.h>
#include <qlineedit.h>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Controller& c, QWidget *parent = 0);
    ~MainWindow();

private:
    Controller& ctrl;
    QListWidget* qlist;
    QGridLayout* main_zone;
    QLineEdit* id;
    QLineEdit* text;
    QLineEdit* correct;
    QLineEdit* score;
    QPushButton* add_button;
public slots:
    void populate();
    void handleAdd();

signals:
    void refresh();

};

#endif // MAINWINDOW_H
