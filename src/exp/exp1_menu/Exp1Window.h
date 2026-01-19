//
// Created by 17542 on 2025/11/8.
//

#ifndef DATASTRUCTURE_EXP1WINDOW_H
#define DATASTRUCTURE_EXP1WINDOW_H
#include <QMainWindow>
class MainMenuWindow;
namespace Ui { class Exp1Window; }

class Exp1Window : public QMainWindow {
    Q_OBJECT

public:
    Exp1Window(MainMenuWindow *main_menu_window,QWidget *parent = nullptr);
    ~Exp1Window();

private slots:
    void on_backButton_clicked();
    void on_startButton_clicked();
    void showSolution();
private:
    Ui::Exp1Window *ui;
    int currentStep;
    MainMenuWindow *main_menu_window;
};

#endif //DATASTRUCTURE_EXP1WINDOW_H