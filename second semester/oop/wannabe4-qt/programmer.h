#ifndef PROGRAMMER_H
#define PROGRAMMER_H
#include <qwidget.h>
#include <observer.h>
#include <controller.h>
#include "member.h"
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlistwidget.h>
#include <qgridlayout.h>
#include <qlineedit.h>

class Programmer: public QWidget, public Observer
{
    Q_OBJECT
public:

    Programmer(Member m, Controller& ctrl,QWidget* parent = Q_NULLPTR);
    ~Programmer(){this->ctrl.removeObserver(this);}
private:
    Member prog;
    Controller& ctrl;
    void update() override;
    QListWidget* slist;
    QLabel* current;
    QLabel* left;
    QGridLayout* main_zone;
    QLineEdit* filename;
    QPushButton* add_button;
    QPushButton* revise_button;

public slots:
    void populate();
    void handleAdd();
    void handleRevise();
    void handleEnable(int);

signals:
    void refresh();

};

#endif // PROGRAMMER_H
