#include "mainwindow.h"
#include <QApplication>
#include "controller.h"

int main(int argc, char *argv[])
{
    Controller ctrl{};
    ctrl.add(23, "da");
    ctrl.add(11, "nu");
    QApplication a(argc, argv);
    MainWindow w{ctrl};
    w.show();

    return a.exec();
}
