//
// Created by 17542 on 2025/11/8.
//

#include "../main_menu/MainMenuWindow.h"
#include "Exp1Window.h"
#include  "ui_Exp1Window.h"
#include "../exp1_menu/Exp1Window.h"

#include "../experiment_1/src/work.h"

Exp1Window::Exp1Window(MainMenuWindow *main_menu_window,QWidget *parent): QMainWindow(parent) ,
                                                                          ui(new Ui::Exp1Window),main_menu_window(main_menu_window){
    currentStep = 0;
    ui->setupUi(this);

    //connect(ui->backButton,&QPushButton::clicked,this,&Exp1Window::on_backButton_clicked);
}

Exp1Window::~Exp1Window()
{
    delete ui;
}

void Exp1Window::on_backButton_clicked() {
    main_menu_window->show();
    this->close();
}
void Exp1Window::on_startButton_clicked() {
    qDebug()<<"exp1启动";
    showSolution();
}
void Exp1Window::showSolution() {
    auto solution = question1::work();
    QString text;
    for (const auto& row : solution) {
        text += "[";
        for (int i = 0; i < row.size(); ++i) {
            text += QString::number(row[i]);
            if (i != row.size() - 1) {
                text += ", ";
            }
        }
        text += "]\n";
    }
    ui->textEdit->setText(text);

}