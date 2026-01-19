//
// Created by 17542 on 2025/10/29.
//
#include "MainMenuWindow.h"
#include "ui_MainMenuWindow.h"
#include "../exp6_menu/Exp6Window.h"

MainMenuWindow::MainMenuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenuWindow)
{
    exp6_window= nullptr;
    exp4_window= nullptr;
    exp13_window= nullptr;
    exp11_window= nullptr;
    exp1_window= nullptr;

    ui->setupUi(this);
    setWindowTitle("DataStructure_Homework");


    // 为所有按钮设置圆角样式
    QString style = "QPushButton {"
                    "    border-radius: 8px;"  // 圆角半径，数值越大越圆
                    "    background-color: #4CAF50;"  // 按钮背景色（可选）
                    "    color: white;"  // 白色文字
                    "    padding: 6px 12px;"  // 内边距（可选，调整按钮大小）
                    "}"
                    "QPushButton:hover {"
                    "    background-color: #45a049;"  //  hover时背景色（可选）
                    "}";

    ui->exp1Button->setStyleSheet(style);
    ui->exp6Button->setStyleSheet(style);
    ui->exp4Button->setStyleSheet(style);
    ui->exp13Button->setStyleSheet(style);
    ui->exp11Button->setStyleSheet(style);



    // 绑定按钮点击事件
    connect(ui->exp1Button, &QPushButton::pressed, this, &MainMenuWindow::onExp1Clicked);
    connect(ui->exp6Button, &QPushButton::pressed, this, &MainMenuWindow::onExp6Clicked);
    connect(ui->exp13Button, &QPushButton::pressed, this, &MainMenuWindow::onExp13Clicked);
    connect(ui->exp11Button, &QPushButton::pressed, this, &MainMenuWindow::onExp11Clicked);
    connect(ui->exp4Button, &QPushButton::pressed, this, &MainMenuWindow::onExp4Clicked);
}

MainMenuWindow::~MainMenuWindow()
{
    delete ui;
}


void MainMenuWindow::onExp6Clicked()
{
    qDebug() << "exp2被点击";
    if (!exp6_window) {
        exp6_window = new Exp6Window(this);
    }
    exp6_window->show();
    this->hide();
}


void MainMenuWindow::onExp13Clicked()
{
    qDebug() << "exp13被点击";
    if (!exp13_window) {
        exp13_window = new Exp13Window(this);
    }
    exp13_window->show();
    this->hide();
}

void MainMenuWindow::onExp11Clicked() {
    qDebug() << "exp11被点击";
    if (!exp11_window) {
        exp11_window = new Exp11Window(this);
    }
    exp11_window->show();
    this->hide();
}

void MainMenuWindow::onExp4Clicked() {
    qDebug() << "exp4被点击";
    if (!exp4_window) {
        exp4_window = new Exp4Window(this);
    }
    exp4_window->show();
    this->hide();
}

void MainMenuWindow::onExp1Clicked() {
    qDebug() << "exp1被点击";
    if (!exp1_window) {
        exp1_window = new Exp1Window(this);
    }
    exp1_window->show();
    this->hide();
}