//
// Created by 17542 on 2025/11/8.
//
#include <QMainWindow>
#ifndef DATASTRUCTURE_EXP4WINDOW_H
#define DATASTRUCTURE_EXP4WINDOW_H
class MainMenuWindow;
namespace Ui { class Exp4Window; }

class Exp4Window : public QMainWindow {
    Q_OBJECT

public:
    Exp4Window(MainMenuWindow *main_menu_window,QWidget *parent = nullptr);
    ~Exp4Window();

private slots:
    void on_backButton_clicked();
    void on_startButton_clicked();
private:
    Ui::Exp4Window *ui;
    int currentStep;
    MainMenuWindow *main_menu_window;
};



#endif //DATASTRUCTURE_EXP4WINDOW_H