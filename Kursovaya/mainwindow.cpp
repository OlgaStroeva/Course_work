#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "level.h"
#include "enter.h"


int a = 0;

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  Enter start_window(user);
  start_window.exec();
  if(user.Nickname != "") ui->label->setText(user.Nickname);
  for(int i = 0; i<3; i++){
      descr[i] = new Description(i, a, this); // i+1, a, this
      ui->gridLayout->addWidget(descr[i], 0, i);
    }


  QPixmap bkgnd("/home/olga/Kursovaya/Resourses/background.png");
     bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
     QPalette p = palette();
     p.setBrush(QPalette::Window, bkgnd);
     setPalette(p);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_comboBox_activated(int index)
{
    a = index;
    for(int i = 0; i<3; i++)
      descr[i]->setLanguage(a);
}

