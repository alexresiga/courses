#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <controller.h>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Controller ctrl, QWidget *parent = 0);
    ~MainWindow();

private:
    Controller ctrl;
    QListWidget* elements;
    QPushButton* show_button;
    QLineEdit* priority;
    QLabel* showPriority;

public slots:
    void populate();
    void handleShow();
signals:
    void refresh();

};

#endif // MAINWINDOW_H
