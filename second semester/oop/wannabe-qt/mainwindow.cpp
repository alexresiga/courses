#include "mainwindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>
#include <iostream>

void MainWindow::populateList()
{
    vector<Elem> all =  this->ctrl.getAll();
    this->elements->clear();
    for(auto e: all)
    {
        QString ceva = QString(e.toString().c_str());
        this->elements->addItem(ceva);

    }
    for(int i = 0; i < this->elements->count(); ++i)
    {
        QListWidgetItem* item = this->elements->item(i);
        QString number = item->text().split(":")[0];
        if (number.toInt() == 23)
        {
            QFont bold{};
            bold.setBold(true);
            item->setFont(bold);
        }
    }
    if (this->ctrl.getAll().size() == 0)
    {
        QMessageBox* alert = new QMessageBox();
        alert->setText("tzeapa");
        alert->show();
        return;
    }
}

void MainWindow::handleFilter()
{
    if (this->elements->currentItem() != NULL){
        const QString& selected = this->elements->currentItem()->text();
         QString filter = selected.split(":")[0];
         vector<Elem> newElems = this->ctrl.filter(filter.toStdString());
         this->elements->clear();
         for(auto e: newElems)
         {
             QString ceva = QString(e.toString().c_str());
             this->elements->addItem(ceva);
         }
        cout<<"buna";
    }
    else
    {

        QMessageBox* alert = new QMessageBox();
        alert->setText("empty filter!");
        alert->show();
        return;
    }
}

void MainWindow::handleRemove()
{
    if (this->elements->currentItem() != NULL)
    {
        const QString& text = this->elements->currentItem()->text();
        QString ceva = text.split(":")[0];
        this->ctrl.remove_element(ceva.toInt());
        emit refresh();
    }
    else
    {
        QMessageBox* alert = new QMessageBox();
        alert->setText("empty remove index!");
        alert->show();
    }
}

void MainWindow::handleAdd()
{
    QString id = this->get_id->text();
    QString name = this->get_name->text();
    if (name.isEmpty() || id == 0)
    {
        QMessageBox* alert = new QMessageBox();
        alert->setText("empty fields");
        alert->show();
        return;
    }
    this->ctrl.add(id.toInt(), name.toStdString());
    emit refresh();
}

MainWindow::MainWindow(Controller c, QWidget *parent) : ctrl{c}, QMainWindow(parent)
{
    this->setWindowTitle("Wannabe");
    //this->setFixedSize(1000, 500);
    this->elements = new QListWidget();

    QGridLayout* main_zone = new QGridLayout(this);

    this->add_button = new QPushButton("add", this);
    this->remove_button = new QPushButton("remove");

    QLabel* id = new QLabel("Enter id:", this);
    this->get_id =  new QLineEdit(this);

    QLabel* name = new QLabel("Enter name: ", this);
    this->get_name = new QLineEdit(this);

    this->filter_button = new QPushButton("filter", this);

    main_zone->addWidget(this->elements, 0, 0, 3, 3);
    main_zone->addWidget(id, 3, 0);
    main_zone->addWidget(get_id, 4, 0, 1, 3);
    main_zone->addWidget(name, 5, 0);
    main_zone->addWidget(get_name, 6, 0, 1, 3);
    main_zone->addWidget(add_button, 7, 0);
    main_zone->addWidget(filter_button, 7, 1);
    main_zone->addWidget(remove_button, 7, 2);


    //this->setLayout(main_zone);
    QWidget *wg = new QWidget();
    this->setCentralWidget(wg);

    wg->setLayout(main_zone);

    QObject::connect(this, SIGNAL(refresh()), this, SLOT(populateList()) );
    QObject::connect(add_button, SIGNAL(clicked()), this, SLOT(handleAdd()));
    QObject::connect(filter_button, SIGNAL(clicked()), this, SLOT(handleFilter()));
    QObject::connect(remove_button, SIGNAL(clicked()), this, SLOT(handleRemove()));
    emit refresh();
}

MainWindow::~MainWindow()
{

}
