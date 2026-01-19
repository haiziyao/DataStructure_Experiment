//
// Created by 17542 on 2025/10/29.
//

#include "Exp13Window.h"
#include "ui_Exp13Window.h"
#include "../main_menu/MainMenuWindow.h"
Exp13Window::Exp13Window(MainMenuWindow *main_menu_window,QWidget *parent): QMainWindow(parent) ,
ui(new Ui::Exp13Window),main_menu_window(main_menu_window){

    ui->setupUi(this);
    //
    dfsTimer = new QTimer(this);
    dfsTimer->setInterval(200);
    //
    connect(dfsTimer,&QTimer::timeout,this,&Exp13Window::stepDFS);
    connect(this, &Exp13Window::updateCellSignal, this, &Exp13Window::updateCellSlot);
    //
    connect(ui->backButton,&QPushButton::clicked,this,&Exp13Window::on_backButton_clicked);
    connect(ui->startButton,&QPushButton::clicked,this,&Exp13Window::on_startButton_clicked);

}

Exp13Window::~Exp13Window()
{
    delete ui;
    delete dfsTimer;
    if (mazeData) delete mazeData;
}

void Exp13Window::on_backButton_clicked() {
    main_menu_window->show();
    this->close();
}

void Exp13Window::on_startButton_clicked() {
    std::string jsonPath = "../Resource/exp13_data/data2.json";
    mazeData = question13::getData(jsonPath);
    if (!mazeData) {
        qWarning()<<("读取数据失败");
    }
    initMazeTable();
    initDFSStack();
    dfsTimer->start();
}

void Exp13Window::updateCellSlot(int row, int col, int status) {
    QTableWidgetItem* item = mazeTable->item(row, col);
    switch (status) {
        case 0: item->setBackground(Qt::gray); break;    // 墙壁
        case 1: item->setBackground(Qt::white); break;   // 未探索
        case 2: item->setBackground(Qt::blue); break;    // 最终路径
        case 3: item->setBackground(Qt::yellow); break;  // 探索中
        case 4: item->setBackground(Qt::red); break;  // 断路
    }
}

void Exp13Window::initMazeTable() {
    if (!mazeData) return;
    currentMaze = mazeData->maze;
    b_x = mazeData->begin_x;
    b_y = mazeData->begin_y;
    e_x = mazeData->end_x;
    e_y = mazeData->end_y;

    mazeTable = new QTableWidget(this);
    mazeTable->setRowCount(currentMaze.size());
    mazeTable->setColumnCount(currentMaze[0].size());
    mazeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for (int i = 0; i < currentMaze.size(); ++i) {
        for (int j = 0; j < currentMaze[0].size(); ++j) {
            QTableWidgetItem* item = new QTableWidgetItem("");
            item->setBackground(currentMaze[i][j] == 0 ? Qt::gray : Qt::white);
            mazeTable->setItem(i, j, item);
        }
    }
    int cellSize = 30;
    // 设置所有列宽
    for (int j = 0; j < currentMaze[0].size(); ++j) {
        mazeTable->setColumnWidth(j, cellSize);
    }
    // 设置所有行高
    for (int i = 0; i < currentMaze.size(); ++i) {
        mazeTable->setRowHeight(i, cellSize);
    }

    mazeTable->item(b_x, b_y)->setBackground(Qt::green);
    mazeTable->item(e_x, e_y)->setBackground(Qt::black);

    mazeTable->setParent(ui->widget);
    QRect widgetRect = ui->widget->rect();
    mazeTable->setGeometry(widgetRect);
    mazeTable->show();
}


void Exp13Window::initDFSStack() {
    dfsStack.clear();
    dfsStack.push(std::make_tuple(b_x, b_y, 0));
    currentMaze[b_x][b_y] = 3;
    emit updateCellSignal(b_x, b_y, 3);
}

void Exp13Window::stepDFS() {
    //结束条件，栈空了，无法回溯了
    if (dfsStack.empty()) {
        dfsTimer->stop();
        return;
    }

    auto [x, y, dirIndex] = dfsStack.top();
    dfsStack.pop();


    if (x == e_x && y == e_y) {
        emit updateCellSignal(x, y, 2);  // 发出信号，标记为最终路径
        dfsTimer->stop();
        return;
    }
    //注意x是行号，y是列号                         下         右           上             左
    std::vector<std::pair<int, int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    bool hasNext = false;

    for (int i = dirIndex; i < dirs.size(); ++i) {
        int nx = x + dirs[i].first;  // 新x坐标
        int ny = y + dirs[i].second; // 新y坐标

        // 检查新坐标是否合法（范围内+未探索+不是墙壁）
        if (nx >=0 && nx < currentMaze.size() && ny >=0 && ny < currentMaze[0].size() && currentMaze[nx][ny] == 1) {
            dfsStack.push(std::make_tuple(x, y, i+1));
            currentMaze[nx][ny] = 3;
            dfsStack.push(std::make_tuple(nx, ny, 0));
            emit updateCellSignal(nx, ny, 3);
            hasNext = true;
            break;
        }
    }

    // 四个方向都尝试失败，回溯（标记为未探索）
    if (!hasNext) {
        currentMaze[x][y] = 4;
        emit updateCellSignal(x, y, 4);
    }
}