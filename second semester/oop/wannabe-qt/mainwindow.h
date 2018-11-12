#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller.h"
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Controller c, QWidget *parent = 0);
    ~MainWindow();

private:
    Controller ctrl;
    QPushButton* add_button;
    QPushButton* filter_button;
    QPushButton* remove_button;
    QLineEdit* get_id;
    QLineEdit* get_name;
    QListWidget* elements;

signals:
    void refresh();

public slots:
    void handleAdd();
    void handleFilter();
    void populateList();
    void handleRemove();

};

#endif // MAINWINDOW_H
