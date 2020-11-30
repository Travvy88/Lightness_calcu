#include <iostream>
#include <assert.h>
#include "lamp.h"
#include "matrix.h"
#include "led.h"
#include "mainwindow.h"
#include "first_win.h"
#include <QApplication>
#include <QDebug>

using namespace std;


int main(int argc, char *argv[])
{
    //Matrix b(2, 3);
    qDebug() << "done";

    QApplication a(argc, argv);
    first_win w;
    w.show();

    return a.exec();

}
