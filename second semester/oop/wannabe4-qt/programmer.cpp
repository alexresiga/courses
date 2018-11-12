#include "programmer.h"
#include "qmessagebox.h"

void Programmer::populate()
{
    if (this->slist->count() > 0)
        this->slist->clear();
    vector<SourceFile> res = this->ctrl.getFiles();
    for(unsigned i = 0; i< res.size(); ++i)
    {
        auto s = res[i];
        QString ceva = QString(s.toString().c_str());
        this->slist->addItem(ceva);
        if (!s.isRevised()){
            QFont bolded{};
            bolded.setBold(true);
            this->slist->item(i)->setFont(bolded);
        }
    }

    this->current->setText(QString::number(this->prog.getNumber()));
    this->left->setText(QString::number(this->prog.getTotal()-this->prog.getNumber()));

}


void Programmer::handleAdd()
{
    QString ceva = this->filename->text();
    try
    {
        this->ctrl.addFile(ceva.toStdString(), this->prog.getName());
    }
    catch(exception& e)
    {
        QMessageBox* msg = new QMessageBox();
        msg->setText(e.what());
        msg->show();
    }
}
void Programmer::update()
{
    populate();
}

void Programmer::handleRevise()
{
    QString ceva = this->slist->currentItem()->text();
    auto idx = this->slist->currentRow();

    QString name = ceva.split("-")[0];
    this->prog.increase();
    this->ctrl.revise(name.toStdString(), this->prog.getName());
    if (this->prog.getTotal()-this->prog.getNumber() == 0)
    {
        QMessageBox* msg = new QMessageBox();
        msg->setText("CONGRATULATIONS");
        msg->show();
    }
    this->slist->item(idx)->setBackgroundColor(Qt::green);

}
void Programmer::handleEnable(int i)
{
    this->revise_button->setEnabled(true);
    if (i == -1) return;
    QString ceva = this->slist->item(i)->text();
    QString status = ceva.split("-")[1];
    QString creator = ceva.split("-")[2];
    if (status.toStdString() == "revised" or creator.toStdString() == this->prog.getName())
        this->revise_button->setEnabled(false);
}
Programmer::Programmer(Member m, Controller &ctrl, QWidget *parent): prog{m}, ctrl{ctrl}, QWidget(parent)
{
    this->ctrl.addObserver(this);
    this->setWindowTitle(QString(this->prog.getName().c_str()));
    this->slist = new QListWidget();
    this->main_zone = new QGridLayout();
    this->current = new QLabel;
    this->left = new QLabel;

    QLabel* text = new QLabel();
    text->setText("Revised:");
    QLabel* text_left =  new QLabel();
    text_left->setText("Left:");
    this->filename = new QLineEdit();
    this->add_button = new QPushButton("Add");
    this->revise_button = new QPushButton("Revise");
    main_zone->addWidget(slist, 0,0);
    main_zone->addWidget(text, 1, 0);
    main_zone->addWidget(this->current, 1, 1);
    main_zone->addWidget(text_left, 2, 0);
    main_zone->addWidget(this->left, 2, 1);
    main_zone->addWidget(filename, 3, 0);
    main_zone->addWidget(add_button, 4, 0);
    main_zone->addWidget(revise_button, 5, 0);



    QObject::connect(this, SIGNAL(refresh()), this, SLOT(populate()));
    QObject::connect(this->add_button, SIGNAL(clicked()), this, SLOT(handleAdd()));
    QObject::connect(this->revise_button, SIGNAL(clicked()), this, SLOT(handleRevise()));
    QObject::connect(this->slist, SIGNAL(currentRowChanged(int)), this, SLOT(handleEnable(int)));
    this->setLayout(main_zone);
    emit refresh();
}
