#include "mainwindow.h"
#include <QApplication>
#include "controller.h"
#include "programmer.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller ctrl{};
    vector<Member> members = ctrl.getMembers();
    vector<Programmer*> windows;
    for(unsigned i = 0 ; i < members.size(); ++i)
    {
        windows.push_back(new Programmer{members[i], ctrl});
        windows[i]->show();
    }

    return a.exec();
}
