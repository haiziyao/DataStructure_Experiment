//
// Created by 17542 on 2025/11/8.
//

#include "../main_menu/MainMenuWindow.h"
#include "Exp4Window.h"
#include  "ui_Exp4Window.h"
#include "../experiment_4/src/work.h"

Exp4Window::Exp4Window(MainMenuWindow *main_menu_window,QWidget *parent): QMainWindow(parent) ,
                                                                          ui(new Ui::Exp4Window),main_menu_window(main_menu_window){
    currentStep = 0;
    ui->setupUi(this);

    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    // 禁用自动拉伸（关键：避免单元格被拉伸变形）
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);


    int cellSize = 10;
    ui->tableWidget->setIconSize(QSize(cellSize, cellSize));

    connect(ui->backButton,&QPushButton::clicked,this,&Exp4Window::on_backButton_clicked);
}

Exp4Window::~Exp4Window()
{
    delete ui;
}

void Exp4Window::on_backButton_clicked() {
    ui->textEdit->clear();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);
    main_menu_window->show();
    this->close();
}

void Exp4Window::on_startButton_clicked() {
    ui->textEdit->clear();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);
    int n = 8;
    bool isNum;
    int num = ui->lineEdit->text().toInt(&isNum);
    if (isNum) n = num;
    auto solution = question4::solve(n);
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


    int rowCount = solution.size();
    int colCount = solution[0].size();
    ui->tableWidget->setRowCount(rowCount);
    ui->tableWidget->setColumnCount(colCount);

    int cellSize = 10 ;

    for (int i = 0; i < rowCount; ++i) {
        ui->tableWidget->setRowHeight(i, cellSize); // 行高
    }
    for (int j = 0; j < colCount; ++j) {
        ui->tableWidget->setColumnWidth(j, cellSize); // 列宽
    }

    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < colCount; ++col) {
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            if (solution[row][col] == 1) {
                item->setBackground(QColor(0, 100, 255)); // 蓝色块
            } else {
                item->setBackground(QColor(240, 240, 240)); // 灰色底色
            }
            ui->tableWidget->setItem(row, col, item);
        }
    }
}
