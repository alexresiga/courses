#ifndef PRESENTER_H
#define PRESENTER_H
#include <qwidget.h>
#include <controller.h>
#include <QListWidget>
#include <qgridlayout.h>
#include <qpushbutton.h>
#include <qlineedit.h>

class Presenter: public QWidget
{
    Q_OBJECT
public:
    explicit Presenter(Controller& c, QWidget *parent = 0);
    ~Presenter();

private:
    Controller& ctrl;
    QListWidget* qlist;
    QGridLayout* main_zone;
    QLineEdit* id;
    QLineEdit* text;
    QLineEdit* correct;
    QLineEdit* score;
    QPushButton* add_button;
public slots:
    void populate();
    void handleAdd();

signals:
    void refresh();
};

#endif // PRESENTER_H
