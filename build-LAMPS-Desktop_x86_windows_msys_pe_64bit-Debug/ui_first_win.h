/********************************************************************************
** Form generated from reading UI file 'first_win.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRST_WIN_H
#define UI_FIRST_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_first_win
{
public:
    QLabel *label_3;
    QLineEdit *line_file;
    QPushButton *pushButton_2;
    QLineEdit *line_n;
    QLabel *label_2;
    QLineEdit *line_m;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *first_win)
    {
        if (first_win->objectName().isEmpty())
            first_win->setObjectName(QString::fromUtf8("first_win"));
        first_win->resize(374, 134);
        first_win->setMinimumSize(QSize(374, 134));
        first_win->setMaximumSize(QSize(374, 134));
        label_3 = new QLabel(first_win);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 20, 121, 16));
        line_file = new QLineEdit(first_win);
        line_file->setObjectName(QString::fromUtf8("line_file"));
        line_file->setGeometry(QRect(200, 40, 131, 20));
        pushButton_2 = new QPushButton(first_win);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 70, 131, 31));
        line_n = new QLineEdit(first_win);
        line_n->setObjectName(QString::fromUtf8("line_n"));
        line_n->setGeometry(QRect(50, 40, 31, 21));
        label_2 = new QLabel(first_win);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 20, 47, 14));
        line_m = new QLineEdit(first_win);
        line_m->setObjectName(QString::fromUtf8("line_m"));
        line_m->setGeometry(QRect(110, 40, 31, 20));
        label = new QLabel(first_win);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 47, 14));
        pushButton = new QPushButton(first_win);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 70, 131, 31));

        retranslateUi(first_win);

        QMetaObject::connectSlotsByName(first_win);
    } // setupUi

    void retranslateUi(QDialog *first_win)
    {
        first_win->setWindowTitle(QApplication::translate("first_win", "Dialog", nullptr));
        label_3->setText(QApplication::translate("first_win", "Enter file name", nullptr));
        line_file->setText(QApplication::translate("first_win", "in.txt", nullptr));
        pushButton_2->setText(QApplication::translate("first_win", "Read  From File", nullptr));
        line_n->setText(QApplication::translate("first_win", "3", nullptr));
        label_2->setText(QApplication::translate("first_win", "Enter M", nullptr));
        line_m->setText(QApplication::translate("first_win", "2", nullptr));
        label->setText(QApplication::translate("first_win", "Enter N", nullptr));
        pushButton->setText(QApplication::translate("first_win", "Enter room size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class first_win: public Ui_first_win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRST_WIN_H
