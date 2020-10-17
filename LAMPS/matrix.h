#ifndef MATRIX_H
#define MATRIX_H
#include "lamp.h"
#include <string>
using namespace std;

class Matrix
{
public:
    Matrix(int, int);
    Matrix(const Matrix &other);
    ~Matrix();

    int getNumberOfObjects() const;
    int getSizeN() const;
    int getSizeM() const;
    Lamp &getItem(const int, const int) const;
    double countLight(const int, const int, const int, const float) const;

    void save(string filename) const;
    void read(string filename) const;

private:
    int n, m;
    Lamp **matrix;
};

#endif // MATRIX_H
