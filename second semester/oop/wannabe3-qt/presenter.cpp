#include "presenter.h"

#include "qmessagebox.h"

void Presenter::populate()
{
    this->qlist->clear();
    vector<Question> res = this->ctrl.getAllQ();
    for(auto q: res)
    {
        QString ceva = QString(q.toString().c_str());
        this->qlist->addItem(ceva);
    }
}

void Presenter::handleAdd()
{
    QString id = this->id->text();
    QString text = this->text->text();
    QString correct = this->correct->text();
    QString score = this->score->text();

    Question q{id.toInt(), text.toStdString(), correct.toStdString(), score.toInt()};
    try
    {
        this->ctrl.addQuestion(q);
    }
    catch(exception& e)
    {
        QMessageBox* msg = new QMessageBox();
        msg->setText(e.what());
        msg->show();

    }

    emit refresh();
}

Presenter::Presenter(Controller& c,QWidget *parent) : ctrl{c}, QWidget(parent)
{
   this->setFixedSize(500, 500);
   this->setWindowTitle("Presenter");
   this->qlist = new QListWidget();
   this->id = new QLineEdit();
   this->text = new QLineEdit();
   this->correct = new QLineEdit();
   this->score = new QLineEdit();
   this->main_zone = new QGridLayout();
   this->add_button = new QPushButton("Add");
   QObject::connect(this, SIGNAL(refresh()), this, SLOT(populate()));
   QObject::connect(this->add_button, SIGNAL(clicked()), this, SLOT(handleAdd()));

   main_zone->addWidget(this->qlist, 0,0);
   main_zone->addWidget(this->id,1, 0);
   main_zone->addWidget(this->text,2, 0);
   main_zone->addWidget(this->correct,3, 0);
   main_zone->addWidget(this->score,4, 0);
   main_zone->addWidget(this->add_button,5, 0);


   this->setLayout(main_zone);

   emit refresh();


}

Presenter::~Presenter()
{

}
