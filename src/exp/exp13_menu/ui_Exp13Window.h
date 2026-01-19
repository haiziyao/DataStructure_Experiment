/********************************************************************************
** Form generated from reading UI file 'Exp13Window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXP13WINDOW_H
#define UI_EXP13WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Exp13Window
{
public:
    QPushButton *startButton;
    QPushButton *noButton;
    QPushButton *backButton;
    QWidget *widget;

    void setupUi(QWidget *Exp13Window)
    {
        if (Exp13Window->objectName().isEmpty())
            Exp13Window->setObjectName("Exp13Window");
        Exp13Window->resize(591, 579);
        startButton = new QPushButton(Exp13Window);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(240, 30, 91, 31));
        noButton = new QPushButton(Exp13Window);
        noButton->setObjectName("noButton");
        noButton->setGeometry(QRect(80, 30, 91, 31));
        backButton = new QPushButton(Exp13Window);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(420, 30, 79, 24));
        widget = new QWidget(Exp13Window);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 90, 491, 441));

        retranslateUi(Exp13Window);

        QMetaObject::connectSlotsByName(Exp13Window);
    } // setupUi

    void retranslateUi(QWidget *Exp13Window)
    {
        Exp13Window->setWindowTitle(QCoreApplication::translate("Exp13Window", "Form", nullptr));
        startButton->setText(QCoreApplication::translate("Exp13Window", "\345\274\200\345\247\213\345\256\236\351\252\214", nullptr));
        noButton->setText(QCoreApplication::translate("Exp13Window", "\347\202\271\346\210\221\344\271\237\346\262\241\347\224\250", nullptr));
        backButton->setText(QCoreApplication::translate("Exp13Window", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Exp13Window: public Ui_Exp13Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXP13WINDOW_H
