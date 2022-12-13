#include "enter.h"
#include "ui_enter.h"

Enter::Enter(Account &user, QWidget *parent) :
  QDialog(parent),
   user(user),
  ui(new Ui::Enter)
{
  ui->setupUi(this);
  QPixmap bkgnd("/home/olga/Kursovaya/Resourses/background.png");
     bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
     QPalette p = palette();
     p.setBrush(QPalette::Window, bkgnd);
     setPalette(p);
     if(!user.successConnection){
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
       }
}

Enter::~Enter()
{
  delete ui;
}

void Enter::on_pushButton_2_clicked()
{
  Registration *registration = new Registration(user);
  registration->exec();
  if(user.Nickname != "")
    close();
}


void Enter::on_pushButton_clicked()
{
  Authentification *authentification = new Authentification(user);
  authentification->exec();
  if(user.Nickname != "")
    close();
}


void Enter::on_pushButton_3_clicked()
{
    close();
}
