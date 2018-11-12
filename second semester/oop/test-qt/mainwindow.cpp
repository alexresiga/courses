#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGridLayout"
#include <string.h>
void MainWindow::populate()
{
    vector<Document> all = this->ctrl.getAll();
    this->elements->clear();
    for (auto d: all)
    {
        QString ceva = QString(d.toString().c_str());
        this->elements->addItem(ceva);
    }
}

void MainWindow::handleSearch(QString s)
{
    if (s.isEmpty()) populate();
    this->elements->clear();
    vector<Document> all = this->ctrl.getAll();
    for (auto d: all)
    {
        if (d.getName().find(s.toStdString()) != string::npos ||d.getKeyW().find(s.toStdString()) != string::npos)
        {
            QString ceva = QString(d.toString().c_str());
            this->elements->addItem(ceva);
        }
    }
}

void MainWindow::handleBestMatch()
{
    QString word = this->search_query->text();
    Document best_match = this->ctrl.computeBestMatch(word.toStdString());
    this->elements->clear();
    QString ceva = QString(best_match.toString().c_str());
    this->elements->addItem(ceva);
}
MainWindow::MainWindow(Controller c, QWidget *parent): ctrl{c}, QMainWindow(parent)
{
        this->setWindowTitle("Search Engine");
        this->setFixedSize(500, 500);
        this->elements = new QListWidget();
        QGridLayout* main_zone = new QGridLayout();
        this->search_query = new QLineEdit();
        this->showBest = new QPushButton("show best matching", this);

        QObject::connect(this, SIGNAL(refresh()), this, SLOT(populate()));
        QObject::connect(this->search_query, SIGNAL(textChanged(QString)), this, SLOT(handleSearch(QString)));
        QObject::connect(this->showBest, SIGNAL(clicked()), this, SLOT(handleBestMatch()));

        main_zone->addWidget(this->elements, 0, 0, 3, 5);
        main_zone->addWidget(this->search_query, 4, 0, 1, 5);
        main_zone->addWidget(this->showBest, 5, 0, 1, 5);
        QWidget* wg = new QWidget();


        this->setCentralWidget(wg);
        wg->setLayout(main_zone);
        emit refresh();
}

MainWindow::~MainWindow()
{

}
