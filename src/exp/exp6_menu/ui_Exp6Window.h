/********************************************************************************
** Form generated from reading UI file 'Exp6Window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXP6WINDOW_H
#define UI_EXP6WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Exp6Window
{
public:
    QPushButton *startButton;
    QPushButton *backButton;
    QTextEdit *textEdit;

    void setupUi(QWidget *Exp6Window)
    {
        if (Exp6Window->objectName().isEmpty())
            Exp6Window->setObjectName("Exp6Window");
        Exp6Window->resize(884, 583);
        startButton = new QPushButton(Exp6Window);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(350, 30, 111, 41));
        backButton = new QPushButton(Exp6Window);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(570, 40, 141, 31));
        textEdit = new QTextEdit(Exp6Window);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(90, 140, 651, 431));

        retranslateUi(Exp6Window);

        QMetaObject::connectSlotsByName(Exp6Window);
    } // setupUi

    void retranslateUi(QWidget *Exp6Window)
    {
        Exp6Window->setWindowTitle(QCoreApplication::translate("Exp6Window", "Form", nullptr));
        startButton->setText(QCoreApplication::translate("Exp6Window", "\345\274\200\345\247\213\345\256\236\351\252\214", nullptr));
        backButton->setText(QCoreApplication::translate("Exp6Window", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Exp6Window", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Exp6Window: public Ui_Exp6Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXP6WINDOW_H
