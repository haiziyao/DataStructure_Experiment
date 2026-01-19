//
// Created by 17542 on 2025/10/29.
//
#include <QMainWindow>
#include "../experiment_13/src/work.h"
#include <QTimer>
#include <QStack>
#include <QTableWidget>
#include <QStatusBar>
#ifndef DATASTRUCTURE_EXP13WINDOW_H
#define DATASTRUCTURE_EXP13WINDOW_H

class MainMenuWindow;
namespace Ui {class Exp13Window;}
class Exp13Window : public QMainWindow {
    Q_OBJECT

public:
    Exp13Window(MainMenuWindow *main_menu_window,QWidget *parent = nullptr);
    ~Exp13Window();

signals:
    void updateCellSignal(int row ,int col,int status);//规定状态


private slots:
    void on_backButton_clicked();
    void on_startButton_clicked();
    void updateCellSlot(int row ,int col ,int status);
    void stepDFS();

private:
    Ui::Exp13Window *ui;
    MainMenuWindow *main_menu_window;
    QTableWidget* mazeTable;
    question13::Data* mazeData;
    QTimer* dfsTimer;
    QStack<std::tuple<int,int,int>> dfsStack;
    std::vector<std::vector<int>> currentMaze;
    int b_x, b_y, e_x, e_y;
    bool isPaused = false;

    void initMazeTable();
    void initDFSStack();
};


#endif //DATASTRUCTURE_EXP13WINDOW_H