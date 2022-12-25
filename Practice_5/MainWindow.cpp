#include "MainWindow.h"
#include "MyPainter.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
{
    setCentralWidget(new QWidget(this));
    auto mainLayout = new QHBoxLayout(this);
    centralWidget()->setLayout(mainLayout);

    auto painter = new MyPainter(this);
    mainLayout->addWidget(painter);
}

MainWindow::~MainWindow()
{
}