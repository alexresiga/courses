#ifndef PARTICIPANTWINDOW_H
#define PARTICIPANTWINDOW_H
#include <QWidget>
#include "observer.h"
#include "controller.h"
#include <QGridLayout>
#include <QPushButton>
#include <qlistwidget.h>
#include <participant.h>
#include <QLineEdit>
#include <qlabel.h>

class ParticipantWindow: public QWidget, public Observer
{
    Q_OBJECT
private:
    Controller& ctrl;
    Participant& part;
public:
    ParticipantWindow();
    ParticipantWindow(Participant& part,Controller& c, QWidget* parent = Q_NULLPTR);
    ~ParticipantWindow() {this->ctrl.removeObserver(this);}

    void update() override;
    QGridLayout* main_zone;
    QListWidget* qlist;
    QPushButton* answer_button;
    QLineEdit* answer;
    QLabel* score;


public slots:
    void populate();
    void handleAns();
    void handleEnable(int);

signals:
    void upd();


};

#endif // PARTICIPANTWINDOW_H
