#include "matrix.h"
#include "lamp.h"
#include "led.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include "cell.h"
#include "sstream"
#include <QDebug>

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
    matrix = new Cell*[n]; // �������� ������ �� 15 ���������� ���� int � ��� ���� ������
    for (int count = 0; count < n; ++count)
        matrix[count] = new Cell[m]; // � ��� ���� �������

}


Matrix::Matrix(const Matrix &other) {

    n = other.getSizeN();
    m = other.getSizeM();

    if (n>0 && m>0) {
        matrix = new Cell*[n];
        for (int i = 0; i < m; ++i)
            matrix[i] = new Cell[m];
    }

    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            Cell *cell = &other.getItem(i, j);
            if (cell->getTypeOfLight()==0)
                cell->setLamp(cell->getLamp());
            else if (cell->getTypeOfLight()==1)
                cell->setLED(cell->getLED());
        }
}

int Matrix::getSizeN() const {
    return n;
}

int Matrix::getSizeM() const {
    return m;
}
Cell &Matrix::getItem(int i, int j) const{
    return matrix[i][j];
}

int Matrix::getNumberOfObjects() const {
    return n*m;
}

double  Matrix::countLight(const int x, const int y, const int z, float height) const {
    if (z < height && z>=0 && x>=0 && x <= n+1
                && y >= 0 && y <= m+1)
        {
            float curIntensity;
            double illuminance = 0;
            for (int i = 0; i < n; i++)
            {
                curIntensity =0;
                for (int j = 0; j < m; j++)
                {

                    if(matrix[i][j].getTypeOfLight()==1)
                        curIntensity = matrix[i][j].getLED().getIntencity();
                    else{
                        curIntensity = matrix[i][j].getLamp().getIntencity();
                    }
                    illuminance += (curIntensity) * (height-z)/
                                   pow((pow(i-x+1, 2) + pow(j-y+1, 2) +
                                        pow(height-z, 2)), 3/2);
                }
            }
            return illuminance;
        }
        else
            return -1; //���������� ������� �� ����� ���������
}

Matrix::~Matrix(){
    delete []matrix;
}

void Matrix::save(string filename) const{
    ofstream file(filename);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {

            Cell *cell = &this->getItem(i, j);
            int type = cell->getTypeOfLight();
            if (type==0)
                file << type << " " << cell->getLamp().getPower() <<" "
                     << cell->getLamp().getIntencity() << '\n';
            else if (type==1)
                file << type << " " << cell->getLED().getPower() <<" "
                     << cell->getLED().getRed() <<" "
                     << cell->getLED().getGreen() << " "
                     << cell->getLED().getBlue() << '\n';
            else file << type << endl;

        }
}

void Matrix::read(string filename) const {
    ifstream file(filename);
    int i = 0, j = 0;
    int power, intencity;
    string s;
    while(getline(file, s)) {
        stringstream x;
        x << s;
        char type = s[0];
        if (type == '1') {
            int r, g, b;
            x >> type >> power >> r >> g >> b;
            this->getItem(i, j).setLED();
            this->getItem(i, j).getLED().setIntencity(r, g, b);
            this->getItem(i, j).getLED().setPower(power);

        } else if (type == '0') {
            x >> type >> intencity >> power;
            this->getItem(i, j).setLamp();
            this->getItem(i, j).getLamp().setIntencity(intencity);
            this->getItem(i, j).getLamp().setPower(power);
        }

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
            if (!(this->getItem(i, j) == other_.getItem(i, j)))
                return 0;
        }
    return 1;
}

void Matrix::show() const
{
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            Cell item = this->getItem(i, j);
            if (item.getTypeOfLight() == 0)
                cout << "Index " << i <<'-'<< j <<
                        " Power: " << item.getLamp().getPower() <<
                        " Intencity: "<< item.getLamp().getIntencity() << endl;
            else if (item.getTypeOfLight() == 1)
                cout << "Index " << i <<'-'<< j <<
                        " Power: " << item.getLED().getPower() <<
                        " Intencity: "<< item.getLED().getIntencity() <<
                        " Red: " << item.getLED().getRed() <<
                        " Green: " << item.getLED().getGreen() <<
                        " Blue: "<< item.getLED().getBlue() << endl;
            else
                cout << "Index " << i <<'-'<< j << " None" << endl;
            }
}
