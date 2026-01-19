//
// Created by 17542 on 2025/11/7.
//
#include <QMainWindow>
#include "../experiment_11/src/work.h"
#ifndef DATASTRUCTURE_EXP11WINDOW_H
#define DATASTRUCTURE_EXP11WINDOW_H
class MainMenuWindow;
namespace Ui { class Exp11Window; }

class Exp11Window : public QMainWindow {
    Q_OBJECT

public:
    Exp11Window(MainMenuWindow *main_menu_window,QWidget *parent = nullptr);
    ~Exp11Window();

private slots:
    void on_backButton_clicked();
    void on_compressButton_clicked();
    void on_decompressButton_clicked();
private:
    Ui::Exp11Window *ui;
    int currentStep;
    MainMenuWindow *main_menu_window;
};
#endif //DATASTRUCTURE_EXP11WINDOW_H