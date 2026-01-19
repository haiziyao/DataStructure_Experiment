//
// Created by 17542 on 2025/10/29.
//

#ifndef DATASTRUCTURE_MAINMENUWINDOW_H
#define DATASTRUCTURE_MAINMENUWINDOW_H
#include <QMainWindow>
#include "ui_MainMenuWindow.h"
#include "../exp6_menu/Exp6Window.h"
#include "../exp13_menu/Exp13Window.h"
#include "../exp11_menu/Exp11Window.h"
#include "../exp4_menu/Exp4Window.h"
#include "../exp1_menu/Exp1Window.h"
namespace Ui { class MainMenuWindow; }

class MainMenuWindow : public QMainWindow {
    Q_OBJECT
public:
    MainMenuWindow(QWidget *parent = nullptr);
    ~MainMenuWindow();

private slots:
    void onExp6Clicked();
    void onExp13Clicked();
    void onExp11Clicked();
    void onExp4Clicked();
    void onExp1Clicked();
private:
    Ui::MainMenuWindow *ui;
    Exp6Window *exp6_window;
    Exp13Window *exp13_window;
    Exp11Window *exp11_window;
    Exp4Window *exp4_window;
    Exp1Window *exp1_window;
};




#endif //DATASTRUCTURE_MAINMENUWINDOW_H