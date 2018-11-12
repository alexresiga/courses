#include "userwindow.h"
#include "utility"
#include <qmessagebox.h>
#include <iostream>

void UserWindow::populate()
{
    if (this->qlist->count() > 0 )
        this->qlist->clear();

    vector<Question> all = this->ctrl.getQ();
    for( auto q: all)
    {
        QString ceva = QString(q.toString().c_str());
        this->qlist->addItem(ceva);
    }
}

void UserWindow::update()
{
    this->populate();
}

void UserWindow::handleAdd()
{
    QString ceva = this->text->text();
    try
    {
        this->ctrl.addQ(ceva.toStdString(), this->user.getName());
    }catch(runtime_error& e)
    {
        QMessageBox* msg = new QMessageBox();
        msg->setText(e.what());
        msg->show();
    }
}

void UserWindow::showA(QString s)
{
    QString id = s.split("-")[0];
    vector<Answer> all = this->ctrl.showAnswers(id.toInt());
    this->alist->clear();
    for( size_t i = 0; i< all.size();++i)
    {
        auto q = all[i];

        QString ceva = QString(q.toString().c_str());

        this->alist->addItem(ceva);
        if (q.getName() == this->user.getName())
            this->alist->item(i)->setBackground(Qt::yellow);
    }

}

void UserWindow::handleAnswer()
{
    QString ceva = this->qlist->currentItem()->text();
    QString text = this->answer->text();
    QString id = ceva.split("-")[0];
    try{
        this->ctrl.addA(id.toInt(),text.toStdString(), this->user.getName());
    }catch(runtime_error& e)
    {
        QMessageBox* msg = new QMessageBox();
        msg->setText(e.what());
        msg->show();
    }
}

void UserWindow::handleEnable(QString s)
{
    this->votes->setEnabled(true);
    QString name = s.split("-")[2];
    if (name.toStdString() == this->user.getName())
        this->votes->setEnabled(false);
}
void UserWindow::handleVote(QString s)
{

    QString id = s.split("-")[0];
    QString nbVotes = s.split("-")[4];

    this->votes->setValue(nbVotes.toInt());

}

void UserWindow::increaseVotes(int i)
{
    QString ceva = this->alist->currentItem()->text();
    QString id = ceva.split("-")[0];
    this->ctrl.increase(id.toInt(), i);
}

UserWindow::UserWindow(User u, Controller& ctrl, QWidget *parent): user{u}, ctrl{ctrl}, QWidget(parent)
{
    this->ctrl.addObserver(this);
    this->setWindowTitle(QString(this->user.getName().c_str()));
    this->qlist = new QListWidget();
    this->alist = new QListWidget();
    this->add_button = new QPushButton("add");
    this->answer = new QLineEdit();
    this->answer_button = new QPushButton("answer");
    this->votes = new QSpinBox();
    this->text = new QLineEdit();
    QObject::connect(this, SIGNAL(refresh()), this, SLOT(populate()));
    QObject::connect(this->add_button, SIGNAL(clicked()), this, SLOT(handleAdd()));
    QObject::connect(this->qlist, SIGNAL(currentTextChanged(QString)), this, SLOT(showA(QString)));
    QObject::connect(this->answer_button, SIGNAL(clicked()), this, SLOT(handleAnswer()));
    QObject::connect(this->alist, SIGNAL(currentTextChanged(QString)), this, SLOT(handleEnable(QString)));
    QObject::connect(this->alist, SIGNAL(currentTextChanged(QString)), this, SLOT(handleVote(QString)));
    QObject::connect(this->votes, SIGNAL(valueChanged(int)), this, SLOT(increaseVotes(int)));
    this->main_zone = new QGridLayout();
    main_zone->addWidget(this->qlist, 0, 0);
    main_zone->addWidget(this->alist, 0, 1);
    main_zone->addWidget(this->answer,1, 1);
    main_zone->addWidget(this->answer_button, 2, 1);
    main_zone->addWidget(text, 1, 0);
    main_zone->addWidget(add_button, 2, 0);
    main_zone->addWidget(this->votes, 3, 0);
    this->setLayout(main_zone);

    emit refresh();
}
