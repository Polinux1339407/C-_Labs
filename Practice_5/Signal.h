#pragma once
#ifndef SIGNAL_H
#define SIGNAL_H
#include <iostream>
#include <QWidget>
#include <math.h>
#include <fstream>
#include <ostream>

class Signal
{
    friend std::ofstream& operator<<(std::ofstream& stream, const Signal& iSignal);
    ///тело оператора можно давать прямо здесь
    friend std::ifstream& operator>>(std::ifstream& stream, Signal& iSignal);

    double _discrFreq = 44100;
    size_t _size;
    double* _array;
public:
    Signal() = default;
    Signal(size_t size);
    Signal(const Signal& cc);
    ~Signal();
    void resize(size_t newSize);
    double& operator[] (size_t i) const;

    Signal operator +(Signal& other);
    Signal operator -(Signal& other);
    void operator +=(Signal& other) { *this = *this + other; };
    void operator -=(Signal& other) { *this = *this - other; };
    size_t get_size() const { return _size; };

    double amplitude();
    void generate_sine(double freq, double ampl);
    std::vector<QPoint> get_points(double height, double width, int koefXForGraphLine, int koefYForGraphLine);
};

#endif // SIGNAL_H
