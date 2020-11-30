#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "matrix.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Matrix *mat, int n, int m, QWidget *parent = nullptr);
    ~MainWindow();
    Matrix *mat;

private slots:

    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;

};

#endif // MAINWINDOW_H
