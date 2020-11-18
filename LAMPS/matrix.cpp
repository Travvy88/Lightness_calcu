#include "matrix.h"
#include "lamp.h"
#include "led.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;

Matrix::Matrix(int n_, int m_) {
    if (n_>0 && m_>0) {
        n = n_;
        m = m_;
        }
    else {
        n = 1;
        m = 1;
    }
    matrix = new Lamp*[n];
    for (int i = 0; i < m; ++i)
        matrix[i] = new Lamp[m];
}

Matrix::Matrix(const Matrix &other) {

    n = other.getSizeN();
    m = other.getSizeM();

    if (n>0 && m>0) {
        matrix = new Lamp*[n];
        for (int i = 0; i < m; ++i)
            matrix[i] = new Lamp[m];
    }

    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            matrix[i][j].setPower(other.getItem(i, j).getPower());
            matrix[i][j].setIntencity(other.getItem(i, j).getIntencity());
        }
}

int Matrix::getSizeN() const {
    return n;
}

int Matrix::getSizeM() const {
    return m;
}
Lamp &Matrix::getItem(int i, int j) const{
    return matrix[i][j];
}

int Matrix::getNumberOfObjects() const {
    return n*m;
}

double  Matrix::countLight(const int x, const int y, const int z, float height) const {
        // height - высота комнаты
        if (z < height && z>=0 && x>=0 && x <= n
                && y >= 0 && y <= m) {
            float curIntensity;
            double illuminance = 0;
            for (int i = 0; i < n; i++) {
                curIntensity =0;
                for (int j = 0; j < m; j++) {
                    illuminance += (curIntensity) * (height-z)/
                                   pow((pow(i-x+1, 2) + pow(j-y+1, 2) +
                                        pow(height-z, 2)), 3/2);
                }
            }
            return illuminance;
        }
        else
            return -1; //координаты выходят за рамки помещения
}

Matrix::~Matrix(){
    delete []matrix;
}

void Matrix::save(string filename) const{
    ofstream file(filename);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            file << matrix[i][j].getPower() <<" "
                 << matrix[i][j].getIntencity() << '\n';
        }
}

void Matrix::read(string filename) const {
    ifstream file(filename);
    int i = 0, j = 0, k = 0;
    int power, intencity;

    while (!file.eof() && k < m*n) {

        k ++;
        char str[256];
        file.getline(str, 256, ' ');
        matrix[i][j] = new LED;
        matrix[i][j].setPower(power);
        matrix[i][j].setIntencity(intencity);

        if (j==m-1) {
            i++;
            j=0;
        }
        else
            j++;
    }
}

bool Matrix::operator==(const Matrix &other_) const {
    if (this->getSizeN() != other_.getSizeN()
            || this->getSizeM() != other_.getSizeM())
        return 0;

    int n = this->getSizeN();
    int m = this->getSizeM();
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            int power1 = this->getItem(i, j).getPower();
            int power2 = other_.getItem(i, j).getPower();
            int intencity1 = this->getItem(i, j).getIntencity();
            int intencity2 = other_.getItem(i, j).getIntencity();

            if (power1 != power2 || intencity1 != intencity2)
                return 0;
        }
    return 1;
}
