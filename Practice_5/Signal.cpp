#define _USE_MATH_DEFINES
#include "Signal.h"

Signal::Signal(size_t size) {
    this->_size = size;
    _array = new double[size];
    for (int i = 0; i < size; i++)
        _array[i] = 0;
}

Signal::Signal(const Signal& signal) {
    this->_array = new double[signal._size];
    this->_size = signal._size;
    for (int i = 0; i < signal._size; i++) {
        this->_array[i] = signal._array[i];
    }
}

void Signal::resize(size_t new_size) {
    auto new_array = new double[new_size];
    if (this->_size == 0)
    {
        _array = new_array;
        this->_size = new_size;
        return;
    }

    for (int i = 0; i < fmin(_size, new_size); i++) {
        new_array[i] = _array[i];
    }
    delete[] _array;
    this->_size = new_size;
    _array = new_array;
}

double& Signal::operator[] (size_t index) const {
    if (index < 0 || index >= _size)
        throw "Invaild index";
    return _array[index];
}

Signal Signal::operator+ (Signal& second) {
    int new_size = fmin(this->_size, second._size);
    Signal res(new_size);

    for (int i = 0; i < new_size; i++)
        res._array[i] = this->_array[i] + second[i];

    for (int i = new_size; i < fmax(this->_size, second._size); i++) {
        if (this->_size < second._size)
            res._array[i] = this->_array[i];
        else
            res._array[i] = second._array[i];
    }
    return res;
}

Signal Signal::operator- (Signal& second) {
    int new_size = fmin(this->_size, second._size);
    Signal res(new_size);

    for (int i = 0; i < new_size; i++) {
        res._array[i] = this->_array[i] - second[i];
    }

    for (int i = new_size; i < fmax(this->_size, second._size); i++) {
        if (this->_size < second._size)
            res._array[i] = this->_array[i];
        else
            res._array[i] = second._array[i];
    }
    return res;
}

Signal::~Signal() {
    delete[] _array;
}


double Signal::amplitude() {
    double sum = 0.0, max_amplitude = 0.0;
    for (int i = 0; i < get_size(); i++) {
        sum += _array[i];
    }
    double average_value = sum / (get_size() - 1);

    for (int i = 0; i < get_size(); i++)
        max_amplitude = fmax(max_amplitude, std::abs(average_value - _array[i]));
    return max_amplitude;
}

void Signal::generate_sine(double freq, double ampl) {
    for (int i = 0; i < get_size(); i++) {
        _array[i] = ampl * std::sin(2 * M_PI * freq * i / _discrFreq);
    }
}

std::vector<QPoint> Signal::get_points(double height, double width, int koefXForGraphLine, int koefYForGraphLine) {
    double freq = 100.0;
    constexpr double sig_ampl = 2;
    std::vector<QPoint> array;
    for (int i = 0; i < 8; ++i)
    {
        this->generate_sine(freq, sig_ampl);

        double amplitude = height - this->amplitude() * koefYForGraphLine;
        double frequency = freq / koefXForGraphLine;
        array.push_back(QPoint(frequency, amplitude));
    }
}

std::ostream& operator<<(std::ostream& stream, const Signal& iSignal)
{
    stream << iSignal.get_size() << '\n';
    for(int i = 0; i < iSignal.get_size(); i++)
        stream << iSignal[i] << ' ';
    return stream;
}

std::ifstream& operator>>(std::ifstream& stream, Signal& iSignal)
{
    stream >> iSignal._size;
    for(int i = 0; i < iSignal._size; i++)
        stream >> iSignal[i];
    return stream;
}
