//
// Created by 17542 on 2025/11/7.
//

#include "../main_menu/MainMenuWindow.h"
#include "Exp11Window.h"
#include  "ui_Exp11Window.h"
#include <string>
#include <QFileInfo>
#include "../experiment_11/src/work.h"


Exp11Window::Exp11Window(MainMenuWindow *main_menu_window,QWidget *parent): QMainWindow(parent) ,
                                                                            ui(new Ui::Exp11Window),main_menu_window(main_menu_window){
    currentStep = 0;
    ui->setupUi(this);


    //我今天才知道底层自动绑定了
    // connect(ui->backButton,&QPushButton::clicked,this,&Exp11Window::on_backButton_clicked);
    // connect(ui->compressButton,&QPushButton::clicked,this,&Exp11Window::on_compressButton_clicked);
    // connect(ui->decompressButton,&QPushButton::clicked,this,&Exp11Window::on_decompressButton_clicked);
}

Exp11Window::~Exp11Window()
{
    delete ui;
}



void Exp11Window::on_backButton_clicked() {
    main_menu_window->show();
    this->close();
}

void Exp11Window::on_compressButton_clicked() {
    qDebug()<<"compressButton被点击";
    QString originalFilePath = ui->originalfile->text();
    qDebug()<<"originalFilePath : "+originalFilePath;
    QFileInfo fileInfo(originalFilePath);
    QString fileName = fileInfo.baseName();
    QString fileDir = fileInfo.path();
    QString filesuffix = fileInfo.suffix();
    QString compressedFileName = fileName + "_huffman_"+filesuffix+".bin";
    QString compressedFilePath = fileDir + "/" + compressedFileName;

    std::string inputPath = originalFilePath.toStdString();
    std::string compressedPath = compressedFilePath.toStdString();
    try {
        question11::HuffmanCoderExample::compressToSingleFile(inputPath,compressedPath);
        qDebug()<<"压缩成功";
    }catch (const std::exception &e) {
        qDebug()<<"压缩失败，发生错误";
    }


}

void Exp11Window::on_decompressButton_clicked() {
    qDebug()<<"decompressButton被点击";
    QString originalFilePath = ui->originalfile->text();
    qDebug()<<"originalFilePath : "+originalFilePath;

    try {
        QFileInfo compressedFileInfo(originalFilePath);
        QString compressedFileName = compressedFileInfo.baseName();
        QString fileDir = compressedFileInfo.path();

        QStringList parts = compressedFileName.split("_huffman_");
        if (parts.length()<2) {
            throw std::runtime_error("the filepath is not vaild");
        }
        QString originalFileName = parts[0];
        QString originalSuffix = parts[1];

        QString decompressedFileName = QString("%1_decompressed.%2")
                                            .arg(originalFileName)
                                            .arg(originalSuffix);
        QString decompressedFilePath = fileDir + "/" + decompressedFileName;

        std::string compressedPath = originalFilePath.toStdString();
        std::string decompressedPath = decompressedFilePath.toStdString();
        question11::HuffmanCoderExample::decompressFromSingleFile(compressedPath, decompressedPath);
        qDebug()<<"解压缩成功";
    }catch (const std::exception &e) {
        qDebug()<<"解压缩失败，发生错误";
    }


}
