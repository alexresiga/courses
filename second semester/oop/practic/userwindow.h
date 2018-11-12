#ifndef USERWINDOW_H
#define USERWINDOW_H
#include "controller.h"
#include "user.h"
#include "observer.h"
#include "QWidget"
#include "QListWidget"
#include <qgridlayout.h>
#include <QPushButton>
#include <qlineedit.h>
#include <QSpinBox>

class UserWindow: public QWidget, public Observer
{
    Q_OBJECT
public:

    UserWindow(User u, Controller& ctrl, QWidget* parent = 0);
    void update() override;

private:
    User user;
    Controller& ctrl;
    QListWidget* qlist;
    QGridLayout* main_zone;
    QPushButton* add_button;
    QLineEdit* text;
    QListWidget* alist;
    QLineEdit* answer;
    QPushButton* answer_button;
    QSpinBox* votes;

public slots:
    void populate();
    void handleAdd();
    void showA(QString);
    void handleAnswer();
    void handleVote(QString);
    void handleEnable(QString s);
    void increaseVotes(int i);

signals:
    void refresh();

};

#endif // USERWINDOW_H
