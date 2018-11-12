#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller ctrl{"in.txt"};
    MainWindow w{ctrl};
    w.show();

    return a.exec();
}
