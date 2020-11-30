#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <sstream>
#include <QDebug>
#include <iostream>
#include <QMessageBox>

MainWindow::MainWindow(Matrix *mat_, int n, int m, QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mat = mat_;
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->setRowCount(n);
    ui->tableWidget->setColumnCount(m);
    for (int col = 0; col < m; ++col)
        ui->tableWidget->setColumnWidth(col, 288);
    for (int row = 0; row < n; ++row)
        for (int col = 0; col <m; ++col) {

            QString qs;
            Cell *item = &mat->getItem(row, col);
            if (item->getTypeOfLight()==0) {
                QTextStream out(&qs);
                out << "<LAMP> I= " << item->getLamp().getIntencity()
                << " P = " << item->getLamp().getPower();
                qDebug() << qs;

            }
            else {
                QTextStream out(&qs);
                out << "<LED> "
                     "I = " << item->getLED().getIntencity()
                << " P = " << item->getLED().getPower();
            }
            QTableWidgetItem *tbl = new QTableWidgetItem(qs);
            ui->tableWidget->setItem(row, col, tbl);
        }

}
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    unsigned int x = ui->xline->text().toLongLong();
    unsigned int h = ui->hline->text().toLongLong();
    unsigned int y = ui->yline->text().toLongLong();
    unsigned int z = ui->zline->text().toLongLong();
    auto light = mat->countLight(x, y, z, h);
    if (light == -1)
        QMessageBox::information(this,  "Lightness", "Coordinates out of room");
    else {
        QString qs = QString::number(light);
        QMessageBox::information(this,  "Lightness", qs);
    }

}
