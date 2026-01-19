//
// Created by 17542 on 2025/10/29.
//

#include "../main_menu/MainMenuWindow.h"
#include "Exp6Window.h"
#include  "ui_Exp6Window.h"
#include "../experiment_2/src/work.h"
Exp6Window::Exp6Window(MainMenuWindow *main_menu_window,QWidget *parent): QMainWindow(parent) ,
                                                                          ui(new Ui::Exp6Window),main_menu_window(main_menu_window){
    currentStep = 0;
    ui->setupUi(this);

    //connect(ui->backButton,&QPushButton::clicked,this,&Exp6Window::on_backButton_clicked);
}

Exp6Window::~Exp6Window()
{
    delete ui;
}

void Exp6Window::on_backButton_clicked() {
    main_menu_window->show();
    this->close();
}

void Exp6Window::on_startButton_clicked() {
    std::vector<std::string> strVec = question2::work();
    QString text;
    for (const std::string& line : strVec) {
        text += QString::fromStdString(line ) + "\n";
    }
    qDebug()<<text;
    ui->textEdit->setText(text);

}