#include "pause.h"
#include "ui_pause.h"


Pause::Pause(const Account &user, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Pause),
  user(user)
{
  ui->setupUi(this);
  this->parent = parent;
  if(user.Nickname == ""){
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->setStyleSheet("color: rgb(136, 138, 133); border: none;");
    ui->pushButton_2->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(245, 224, 176, 255), stop:0.09 rgba(246, 189, 237, 255), stop:0.14 rgba(194, 207, 246, 255), stop:0.19 rgba(184, 160, 168, 255), stop:0.25 rgba(171, 186, 248, 255), stop:0.32 rgba(243, 248, 224, 255), stop:0.385 rgba(249, 162, 183, 255), stop:0.47 rgba(100, 115, 124, 255), stop:0.58 rgba(251, 205, 202, 255), stop:0.65 rgba(170, 128, 185, 255), stop:0.75 rgba(252, 222, 204, 255), stop:0.805 rgba(206, 122, 218, 255), stop:0.86 rgba(254, 223, 175, 255), stop:0.91 rgba(254, 236, 244, 255), stop:1 rgba(255, 191, 221, 255));");
    }

  QPixmap bkgnd(":/Resourses/background.png");
     bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
     QPalette p = palette();
     p.setBrush(QPalette::Window, bkgnd);
     setPalette(p);
}

Pause::~Pause()
{
  delete ui;
}

void Pause::on_pushButton_3_clicked()
{
    accept();
    close();
}


void Pause::on_pushButton_clicked()
{
    close();
}


void Pause::on_pushButton_2_clicked()
{
  done(3);
  close();
}

