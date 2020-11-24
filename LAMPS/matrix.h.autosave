#ifndef MATRIX_H
#define MATRIX_H
#include "lamp.h"
#include <string>

#include "cell.h"
using namespace std;

class Matrix {
public:
    Matrix(int, int);
    Matrix(string);
    Matrix(const Matrix &other);
    ~Matrix();

    int getNumberOfObjects() const;
    int getSizeN() const;
    int getSizeM() const;
    Cell &getItem(const int, const int) const;
    double countLight(const int, const int, const int, const float) const;

    void save(string filename) const;
    void read(string filename) const;
    bool operator==(const Matrix&) const;
    void show() const;
private:
    int n, m;
    Cell **matrix;
};

#endif // MATRIX_H
