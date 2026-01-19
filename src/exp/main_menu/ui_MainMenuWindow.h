/********************************************************************************
** Form generated from reading UI file 'MainMenuWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENUWINDOW_H
#define UI_MAINMENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenuWindow
{
public:
    QPushButton *exp6Button;
    QPushButton *exp13Button;
    QPushButton *exp1Button;
    QPushButton *exp11Button;
    QPushButton *exp4Button;

    void setupUi(QWidget *MainMenuWindow)
    {
        if (MainMenuWindow->objectName().isEmpty())
            MainMenuWindow->setObjectName("MainMenuWindow");
        MainMenuWindow->resize(400, 300);
        exp6Button = new QPushButton(MainMenuWindow);
        exp6Button->setObjectName("exp6Button");
        exp6Button->setGeometry(QRect(70, 50, 79, 24));
        exp13Button = new QPushButton(MainMenuWindow);
        exp13Button->setObjectName("exp13Button");
        exp13Button->setGeometry(QRect(190, 50, 79, 24));
        exp1Button = new QPushButton(MainMenuWindow);
        exp1Button->setObjectName("exp1Button");
        exp1Button->setGeometry(QRect(70, 110, 79, 24));
        exp11Button = new QPushButton(MainMenuWindow);
        exp11Button->setObjectName("exp11Button");
        exp11Button->setGeometry(QRect(190, 110, 79, 24));
        exp4Button = new QPushButton(MainMenuWindow);
        exp4Button->setObjectName("exp4Button");
        exp4Button->setGeometry(QRect(70, 170, 79, 24));

        retranslateUi(MainMenuWindow);

        QMetaObject::connectSlotsByName(MainMenuWindow);
    } // setupUi

    void retranslateUi(QWidget *MainMenuWindow)
    {
        MainMenuWindow->setWindowTitle(QCoreApplication::translate("MainMenuWindow", "Form", nullptr));
        exp6Button->setText(QCoreApplication::translate("MainMenuWindow", "\345\206\234\345\244\253\350\277\207\346\262\263", nullptr));
        exp13Button->setText(QCoreApplication::translate("MainMenuWindow", "\350\277\267\345\256\253\351\227\256\351\242\230", nullptr));
        exp1Button->setText(QCoreApplication::translate("MainMenuWindow", "\350\203\214\345\214\205\351\227\256\351\242\230", nullptr));
        exp11Button->setText(QCoreApplication::translate("MainMenuWindow", "\345\223\210\345\244\253\346\233\274\345\216\213\347\274\251", nullptr));
        exp4Button->setText(QCoreApplication::translate("MainMenuWindow", "\345\205\253\347\232\207\345\220\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenuWindow: public Ui_MainMenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUWINDOW_H
