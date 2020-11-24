#ifndef FIRST_WIN_H
#define FIRST_WIN_H

#include <QDialog>
#include <matrix.h>

namespace Ui {
class first_win;
}

class first_win : public QDialog
{
    Q_OBJECT

public:
    explicit first_win(QWidget *parent = nullptr);
    ~first_win();
    Matrix *mat;

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::first_win *ui;
};

#endif // FIRST_WIN_H
