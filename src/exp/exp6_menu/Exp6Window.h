//
// Created by 17542 on 2025/10/29.
//
#include <QMainWindow>

#ifndef DATASTRUCTURE_EXP6WINDOW_H
#define DATASTRUCTURE_EXP6WINDOW_H

class MainMenuWindow;
namespace Ui { class Exp6Window; }

class Exp6Window : public QMainWindow {
    Q_OBJECT

public:
    Exp6Window(MainMenuWindow *main_menu_window,QWidget *parent = nullptr);
    ~Exp6Window();

private slots:
    void on_backButton_clicked();
    void on_startButton_clicked();
private:
    Ui::Exp6Window *ui;
    int currentStep;
    MainMenuWindow *main_menu_window;
};
#endif //DATASTRUCTURE_EXP6WINDOW_H