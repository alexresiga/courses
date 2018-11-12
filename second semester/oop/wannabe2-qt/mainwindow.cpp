#include "mainwindow.h"
#include <QGridLayout>

void MainWindow::populate()
{
    vector<Task> all = this->ctrl.getByPriority();
    this->elements->clear();

    for(auto i = 0; i < all.size(); ++i)
    {
        auto t = all[i];
        QString ceva = QString(t.toString().c_str());
        this->elements->addItem(ceva);
        if (t.getPrior() == 1)
        {
            QFont bolded{};
            QColor ceva{rand()%255, rand()%255, rand()%255};

            bolded.setBold(true);
            this->elements->item(i)->setFont(bolded);
            this->elements->item(i)->setBackgroundColor(ceva);
        }
    }
}
void MainWindow::handleShow()
{
    QString p = this->priority->text();
    QString result = QString::number(this->ctrl.compute(p.toInt()));
    showPriority->clear();
    showPriority->setText(result);
}
MainWindow::MainWindow(Controller c, QWidget *parent) : ctrl{c}, QMainWindow(parent)
{
    this->elements = new QListWidget();
    this->elements->setSpacing(3);

    this->show_button = new QPushButton("enter priority", this);

    this->priority = new QLineEdit();

    this->showPriority = new QLabel("Total duration will be shown here.");


    QObject::connect(this, SIGNAL(refresh()), this, SLOT(populate()));
    QObject::connect(show_button, SIGNAL(clicked()), this, SLOT(handleShow()));


    QGridLayout* main_zone = new QGridLayout();
    main_zone->addWidget(this->elements, 0, 0, 3, 3);
    main_zone->addWidget(show_button, 4, 0, 1, 3);
    main_zone->addWidget(priority, 3, 0, 1, 3);
    main_zone->addWidget(showPriority, 5, 0, 1, 3);

    QWidget* wg = new QWidget();
    this->setCentralWidget(wg);
    wg->setLayout(main_zone);


    emit refresh();
}

MainWindow::~MainWindow()
{
}
