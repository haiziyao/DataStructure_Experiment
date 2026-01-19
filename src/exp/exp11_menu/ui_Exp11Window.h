/********************************************************************************
** Form generated from reading UI file 'Exp11Window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXP11WINDOW_H
#define UI_EXP11WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Exp11Window
{
public:
    QPushButton *compressButton;
    QPushButton *decompressButton;
    QPushButton *backButton;
    QLineEdit *originalfile;

    void setupUi(QWidget *Exp11Window)
    {
        if (Exp11Window->objectName().isEmpty())
            Exp11Window->setObjectName("Exp11Window");
        Exp11Window->resize(632, 466);
        compressButton = new QPushButton(Exp11Window);
        compressButton->setObjectName("compressButton");
        compressButton->setGeometry(QRect(190, 50, 79, 24));
        decompressButton = new QPushButton(Exp11Window);
        decompressButton->setObjectName("decompressButton");
        decompressButton->setGeometry(QRect(310, 50, 79, 24));
        backButton = new QPushButton(Exp11Window);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(510, 20, 79, 24));
        originalfile = new QLineEdit(Exp11Window);
        originalfile->setObjectName("originalfile");
        originalfile->setGeometry(QRect(150, 170, 261, 20));

        retranslateUi(Exp11Window);

        QMetaObject::connectSlotsByName(Exp11Window);
    } // setupUi

    void retranslateUi(QWidget *Exp11Window)
    {
        Exp11Window->setWindowTitle(QCoreApplication::translate("Exp11Window", "Form", nullptr));
        compressButton->setText(QCoreApplication::translate("Exp11Window", "\345\216\213\347\274\251", nullptr));
        decompressButton->setText(QCoreApplication::translate("Exp11Window", "\350\247\243\345\216\213\347\274\251", nullptr));
        backButton->setText(QCoreApplication::translate("Exp11Window", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Exp11Window: public Ui_Exp11Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXP11WINDOW_H
