/********************************************************************************
** Form generated from reading UI file 'Exp1Window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXP1WINDOW_H
#define UI_EXP1WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Exp1Window
{
public:
    QPushButton *backButton;
    QPushButton *startButton;
    QTextEdit *textEdit;

    void setupUi(QWidget *Exp1Window)
    {
        if (Exp1Window->objectName().isEmpty())
            Exp1Window->setObjectName("Exp1Window");
        Exp1Window->resize(534, 543);
        backButton = new QPushButton(Exp1Window);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(310, 30, 79, 24));
        startButton = new QPushButton(Exp1Window);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(100, 30, 79, 24));
        textEdit = new QTextEdit(Exp1Window);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(30, 130, 471, 401));

        retranslateUi(Exp1Window);

        QMetaObject::connectSlotsByName(Exp1Window);
    } // setupUi

    void retranslateUi(QWidget *Exp1Window)
    {
        Exp1Window->setWindowTitle(QCoreApplication::translate("Exp1Window", "Form", nullptr));
        backButton->setText(QCoreApplication::translate("Exp1Window", "\350\277\224\345\233\236 ", nullptr));
        startButton->setText(QCoreApplication::translate("Exp1Window", "\345\274\200\345\247\213\345\256\236\351\252\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Exp1Window: public Ui_Exp1Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXP1WINDOW_H
