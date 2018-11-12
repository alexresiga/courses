#include "mainwindow.h"
#include <QApplication>
#include "controller.h"
#include "participantwindow.h"
#include "presenter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo{"q.txt", "p.txt"};
    Controller ctrl{repo};
    Presenter pre{ctrl};
    pre.show();
    vector<Participant> participants = repo.getP();
    vector<ParticipantWindow*> windows;


    for(auto i = 0; i < participants.size(); ++i)
    {
        windows.push_back(new ParticipantWindow{participants[i], ctrl});
        windows[i]->show();
    }

    return a.exec();
}
