#include "first_win.h"
#include "ui_first_win.h"
#include "matrix.h"
#include <string>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include "mainwindow.h"


first_win::first_win(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::first_win)
{
    ui->setupUi(this);
    mat = nullptr;
}

first_win::~first_win()
{
    delete ui;
}

void first_win::on_pushButton_clicked()
{
    unsigned int n = ui->line_n->text().toLongLong();
    unsigned int m = ui->line_m->text().toLongLong();
    mat = new Matrix(n, m);
}

void first_win::on_pushButton_2_clicked()
{
    string filename = ui->line_file->text().toLocal8Bit().constData();
    if (mat) {
        mat->read(filename);
        this->close();
        MainWindow *mw = new MainWindow(mat, mat->getSizeN(), mat->getSizeM());
        mw->show();

    }
    else
        QMessageBox::critical(this,  "Warning", "Enter room size before");
}
