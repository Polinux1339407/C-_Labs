#include "MyPainter.h"

MyPainter::MyPainter(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(width, height);
}

void MyPainter::paintEvent(QPaintEvent *event)
{
    //Оси
    drawAxis();
    //Точки
    drawGraphLine();
}

void MyPainter::wheelEvent(QWheelEvent *wheelEvent)
{
    QCursor::pos(this->screen());
    if(wheelEvent->modifiers() & Qt::ShiftModifier)
    {
        if(wheelEvent->delta() > 0)
            koefXForGraphLine += 1;
        else if(wheelEvent->delta() < 0 and koefXForGraphLine > 1)
            koefXForGraphLine -= 1;
    }
    else
    {
        if(wheelEvent->delta() > 0)
            koefYForGraphLine += 1;
        else if(wheelEvent->delta() < 0 and koefYForGraphLine > 1)
            koefYForGraphLine -= 1;
    }
    update();
}


void MyPainter::drawAxis()
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black,3));
    //Y Axis
    painter.drawLine(0, 0, 0, height);
    //X Axis
    painter.drawLine(0, height/2, width, height/2);

    for(int i = height/2; i > 0; i -= koefYForGraphLine)
        painter.drawLine(0, i, 5, i);
    for(int i = height/2; i < height; i += koefYForGraphLine)
        painter.drawLine(0, i, 5, i);
    for(int i = 0; i < width; i += koefXForGraphLine)
        painter.drawLine(i, height/2-2, i, height/2 + 2);
}

void MyPainter::drawGraphLine()
{
    QPainter painter(this);

    Signal signal(500);
    double freq = 1000.0;
    constexpr double sig_ampl = 3;

    signal.generate_sine(freq, sig_ampl);

    double coordX = 0.0, coordY = height/2 - signal[0] * koefYForGraphLine;
    double frequency = freq/10000 * koefXForGraphLine;
    for (int i = 1; i < signal.get_size(); i++)
    {
        double amplitude = height/2 - signal[i] * koefYForGraphLine;

        painter.setPen(QPen(Qt::blue, 3));
        painter.drawLine(coordX, coordY, coordX+frequency, amplitude);

        painter.setPen(QPen(Qt::blue,7));
        painter.drawPoint(coordX+frequency, amplitude);

        coordX += frequency;
        coordY = amplitude;
    }
}

void MyPainter::resizeEvent(QResizeEvent *resizeEvent) {
    width = resizeEvent->size().width();
    height = resizeEvent->size().height();
}