#include "MyMainWindow.h"
#include "qboxlayout.h"
#include "qlabel.h"
#include "qtcpsocket.h"
#pragma execution_character_set("utf-8")


MainWindow::MainWindow(QWidget *parent)
{
    QSize szie;
    szie.setWidth(1000);
    szie.setHeight(800);   
    this->setFixedSize(szie);
    QWidget* pWid = new QWidget(this);
    QVBoxLayout* pvMainLayout = new QVBoxLayout(this);
    QWidget* pfristWid = new QWidget(this);
    QLabel* pLab = new QLabel(pfristWid);
    pLab->setText("测试中文hahahahahhah");
    pvMainLayout->addWidget(pLab);
    pvMainLayout->addWidget(pfristWid);
}

MainWindow::~MainWindow()
{
}
