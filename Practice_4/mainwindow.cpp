#include "mainwindow.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QTimer>
#include <QTime>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto mainLayout = new QHBoxLayout(this);
    setCentralWidget(new QWidget(this));
    centralWidget()->setLayout(mainLayout);
    this->setMinimumSize(300, 600);

    auto createButton = [this](){
        auto button = new QPushButton(this);

        button->setText("*");
        auto x = this->width() - button->width();
        button->move(rand()%x, 100);

        tmrBut = new QTimer(button);
        int speed = rand()%3 + 1;

        auto moveBut = [button, speed, this](){
          button->move(button->x(), button->y() + speed);
          if(button->y() >= this->height()) {
            this->setWindowTitle("ÐŸÑ€Ð¾Ð¸Ð³Ñ€Ñ‹Ñˆ!");
            this->setStyleSheet("background-color: red;");
          };
          if(button->underMouse()){
              button->move(button->x(), button->y() + speed*2);
          };
        };

        connect(tmrBut, &QTimer::timeout, button, moveBut);
        tmrBut->start(1000/30);

        connect(button, &QPushButton::clicked, [button](){button->deleteLater();});
        button->show();
    };

    tmr = new QTimer(this);
    tmr->setInterval(1000);
    connect(tmr, &QTimer::timeout, this, createButton);
    tmr->start();
}

MainWindow::~MainWindow()
{
}

