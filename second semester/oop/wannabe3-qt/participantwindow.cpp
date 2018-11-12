#include "participantwindow.h"
#include <iostream>
using namespace std;
void ParticipantWindow::populate()
{
    if (this->qlist->count() >0)
        this->qlist->clear();
    vector<Question> res = this->ctrl.getAllQ();
    sort(res.begin(), res.end(), [](Question a, Question b){return a.getScore() > b.getScore();});
    for(auto g: res)
    {
        QString ceva = QString(g.toString().c_str());
        this->qlist->addItem(ceva);
    }
}

void ParticipantWindow::handleEnable(int i)
{
    if (i == -1) return;
    this->answer_button->setEnabled(true);
    if (this->qlist->item(i)->backgroundColor() == Qt::green)
    {
        this->answer_button->setEnabled(false);
        return;
    }
    this->answer->clear();
}

void ParticipantWindow::handleAns()
{

    QString s = this->qlist->currentItem()->text();
    auto idx = this->qlist->currentRow();
    QString correct = s.split(" ")[2];
    QString score = s.split(" ")[3];
    QString user = this->answer->text();

    if (user == correct)
    {
        this->qlist->item(idx)->setBackgroundColor(Qt::green);
        this->answer_button->setEnabled(false);
        this->part.setScore(score.toInt());
        this->score->setText(QString::number(this->part.getScore()));
    }
}

ParticipantWindow::ParticipantWindow(Participant& part, Controller& ctrl, QWidget* parent):part{part}, ctrl{ctrl}, QWidget(parent)
{
    this->ctrl.addObserver(this);

    this->setWindowTitle(this->part.getName().c_str());
    this->main_zone = new QGridLayout();
    this->answer_button = new QPushButton("answer");
    this->answer = new QLineEdit();
    this->qlist = new QListWidget();
    this->score = new QLabel();
    this->score->setText(QString::number(this->part.getScore()));

    main_zone->addWidget(this->qlist, 0, 0);
    main_zone->addWidget(answer, 1, 0);
    main_zone->addWidget(answer_button, 2, 0);
    main_zone->addWidget(score, 3, 0);

    this->setLayout(main_zone);
    QObject::connect(this, SIGNAL(upd()), this, SLOT(populate()));
    QObject::connect(this->answer_button, SIGNAL(clicked()), this, SLOT(handleAns()));
    QObject::connect(this->qlist, SIGNAL(currentRowChanged(int)), this, SLOT(handleEnable(int)));

    emit upd();
}

void ParticipantWindow::update()
{
    if (this->qlist->count() >0)
        this->qlist->clear();
    vector<Question> res = this->ctrl.getAllQ();
    sort(res.begin(), res.end(), [](Question a, Question b){return a.getScore() > b.getScore();});
    for(auto g: res)
    {
        QString ceva = QString(g.toString().c_str());
        this->qlist->addItem(ceva);
    }
}
