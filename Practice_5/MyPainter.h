#pragma once
#ifndef MYPAINTER_H
#define MYPAINTER_H
#include "Signal.h"
#include <QPainter>
#include <QWheelEvent>

class MyPainter : public QWidget
{
Q_OBJECT
    int koefXForGraphLine = 25;
    int koefYForGraphLine = 25;
    int height = 370;
    int width = 540;
    std::vector<QPoint> points;
public:
    explicit MyPainter(QWidget *parent = nullptr);
    void drawAxis();
    void drawGraphLine();
    void wheelEvent(QWheelEvent *wheelEvent);
    void resizeEvent(QResizeEvent *resizeEvent);
signals:

protected:
    void paintEvent(QPaintEvent *event) final;
};

#endif // MYPAINTER_H
