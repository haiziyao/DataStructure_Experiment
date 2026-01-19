#include <QApplication>
#include <QPushButton>
#include "src/exp/main_menu/MainMenuWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainMenuWindow mainWindow;
    mainWindow.show(); // 启动时显示主菜单
    return QApplication::exec();
}