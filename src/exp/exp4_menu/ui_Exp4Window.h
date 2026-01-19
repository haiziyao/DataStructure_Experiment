/********************************************************************************
** Form generated from reading UI file 'Exp4Window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXP4WINDOW_H
#define UI_EXP4WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Exp4Window
{
public:
    QPushButton *backButton;
    QPushButton *startButton;
    QTextEdit *textEdit;
    QTableWidget *tableWidget;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Exp4Window)
    {
        if (Exp4Window->objectName().isEmpty())
            Exp4Window->setObjectName("Exp4Window");
        Exp4Window->resize(684, 604);
        backButton = new QPushButton(Exp4Window);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(490, 60, 79, 24));
        startButton = new QPushButton(Exp4Window);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(290, 60, 79, 24));
        textEdit = new QTextEdit(Exp4Window);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(0, 0, 191, 191));
        tableWidget = new QTableWidget(Exp4Window);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(150, 200, 451, 401));
        lineEdit = new QLineEdit(Exp4Window);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(290, 100, 113, 20));

        retranslateUi(Exp4Window);

        QMetaObject::connectSlotsByName(Exp4Window);
    } // setupUi

    void retranslateUi(QWidget *Exp4Window)
    {
        Exp4Window->setWindowTitle(QCoreApplication::translate("Exp4Window", "Form", nullptr));
        backButton->setText(QCoreApplication::translate("Exp4Window", "\350\277\224\345\233\236", nullptr));
        startButton->setText(QCoreApplication::translate("Exp4Window", "\345\274\200\345\247\213\345\256\236\351\252\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Exp4Window: public Ui_Exp4Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXP4WINDOW_H
