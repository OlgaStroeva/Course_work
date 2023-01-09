#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDesktopServices>
#include <QMessageBox>
#include <QDir>

int a = 0;

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  QPixmap bkgnd(":/Resourses/background.png"); //Установка красивого фона
     bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
     QPalette p = palette();
     p.setBrush(QPalette::Window, bkgnd);
     setPalette(p);

  Enter start_window(user);
  start_window.exec();

  if(user.Nickname != "")
        ui->label->setText(user.Nickname);
  else
    ui->pushButton_2->setEnabled(false);
  for(int i = 0; i<3; i++){
      descr[i] = new Description(i, a, this, user); //Создание красивых окошечек с уровнями)))
      ui->gridLayout->addWidget(descr[i], 0, i);
    }
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_comboBox_activated(int index)
{
    a = index;
    for(int i = 0; i<3; i++)
      descr[i]->setLanguage(a); //Установка языка для всех уровней
}


void MainWindow::on_pushButton_2_clicked()
{
    user.currentTasks.show();
}


void MainWindow::on_pushButton_3_clicked()
{
  QString link = ":/Resourses/Information/read_me.html"; // rename the file
  //QString link = QDir::currentPath()+"/Resourses/Information/read_me.html";
  try {
    if(!QDesktopServices::openUrl(QUrl(link.trimmed()))) throw 1;
  }  catch (int a) {
    QMessageBox::information(NULL,"Произошла ошибка!","Файл не найден");

  }
}

