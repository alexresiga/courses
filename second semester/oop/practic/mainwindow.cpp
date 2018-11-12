#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::handleSearch(QString s)
{
    vector<Question> result = this->ctrl.search(s.toStdString());
    this->results->clear();
    this->results->addItem(QString(this->ctrl.topThree(result[0]).c_str()));

    for(size_t i = 1; i < result.size(); ++i)
    {
        auto q = result[i];
        QString ceva = QString(q.toString().c_str());
        this->results->addItem(ceva);
    }
}

void MainWindow::update()
{
    emit refresh();
}

MainWindow::MainWindow(Controller ctrl, QWidget *parent) :ctrl{ctrl}, QWidget(parent)
{
    this->ctrl.addObserver(this);
    this->setWindowTitle("Search");
    this->main_zone = new QGridLayout();
    this->results = new QListWidget();
    this->input = new QLineEdit();
    QObject::connect(this->input, SIGNAL(textChanged(QString)), this, SLOT(handleSearch(QString)));
    QObject::connect(this->input, SIGNAL(textChanged(QString)), this, SLOT(update()));
    QObject::connect(this, SIGNAL(refresh()), this, SLOT(handleSearch(QString)));
    main_zone->addWidget(results, 0,0);
    main_zone->addWidget(input, 1, 0);

   this->setLayout(main_zone);
}

MainWindow::~MainWindow()
{

}
