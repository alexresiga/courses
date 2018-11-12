#include "mainwindow.h"
#include <QApplication>
#include "controller.h"
#include "userwindow.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller ctrl{};
    MainWindow w{ctrl};
    w.show();
    vector<User> users = ctrl.getU();
    vector<UserWindow*> windows;
    for(size_t i = 0; i< users.size(); ++i)
    {
        windows.push_back(new UserWindow{users[i], ctrl});
        windows[i]->show();
    }
    return a.exec();
}
