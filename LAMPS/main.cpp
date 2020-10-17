#include <iostream>
#include <assert.h>
#include "lamp.h"
#include "matrix.h"

using namespace std;

int compare(const Matrix &col1, const Matrix &col2 ){
    if (col1.getSizeN() != col2.getSizeN() || col1.getSizeM() != col2.getSizeM())
        return 0;

    int n = col1.getSizeN();
    int m = col1.getSizeM();
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            int power1 = col1.getItem(i, j).getPower();
            int power2 = col2.getItem(i, j).getPower();
            int intencity1 = col1.getItem(i, j).getIntencity();
            int intencity2 = col2.getItem(i, j).getIntencity();

            if (power1 != power2 || intencity1 != intencity2)
                return 0;
        }
    return 1;
}


void show(const Matrix &col) {
    int n = col.getSizeN();
    int m = col.getSizeM();
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            Lamp item = col.getItem(i, j);
            cout << "Row: " << i << " Column: " << j << " Power: " << item.getPower() << " Intencity: "<< item.getIntencity() << endl;
        }
}


int main()  
{

    Lamp a;
    a.setPower(150);
    assert(a.getPower() == 150);
    a.setPower(-23);
    assert(a.getPower() == 1);
    a.setPower(78545);
    assert(a.getPower() == 1000);

    a.setIntencity(150);
    assert(a.getIntencity() == 150);
    a.setIntencity(-23);
    assert(a.getIntencity() == 1);
    a.setIntencity(78545);
    assert(a.getIntencity() == 1000);

    Lamp b;
    assert(b.getPower() == 300 && b.getIntencity() == 100);

    Lamp c(234, 567);
    assert(c.getPower() == 234 && c.getIntencity() == 567);


    Matrix mat(2, 2), mat_different(2, 2);

    assert(mat.getItem(0, 0).getPower() == 300 && mat.getItem(0, 0).getIntencity() == 100 &&
           mat.getItem(0, 1).getPower() == 300 && mat.getItem(0, 1).getIntencity() == 100 &&
           mat.getItem(1, 0).getPower() == 300 && mat.getItem(1, 0).getIntencity() == 100 &&
           mat.getItem(1, 1).getPower() == 300 && mat.getItem(1, 1).getIntencity() == 100);
    // проверка иниц. конструктора

    Matrix mat_def(-3, -4);
    assert(mat_def.getSizeM() == 1 && mat_def.getSizeN() == 1);

    mat.read("in.txt");
    mat_different.read("in1.txt");
    assert(compare(mat, mat)); // проверка compare
    assert(compare(mat, mat_different) == 0); // проверка compare

    Matrix matcopy(mat);
    assert(compare(mat, matcopy)); // проверка конструктора копирования

    Matrix mat1(2, 2);
    assert(mat.getItem(0, 0).getPower() == 111 && mat.getItem(0, 0).getIntencity() == 111 &&
           mat.getItem(0, 1).getPower() == 244 && mat.getItem(0, 1).getIntencity() == 432 &&
           mat.getItem(1, 0).getPower() == 343 && mat.getItem(1, 0).getIntencity() == 344 &&
           mat.getItem(1, 1).getPower() == 498 && mat.getItem(1, 1).getIntencity() == 411);
    // проверка read
    mat.save("out.txt");
    mat1.read("out.txt");
    assert(compare(mat, mat1)); // проверка save

    cout << "All tests are done!" << endl;



}
