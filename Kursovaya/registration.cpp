#include "registration.h"
#include "ui_registration.h"

Registration::Registration(Account &user, QWidget *parent) :
  QDialog(parent),
  user(user),
  ui(new Ui::Registration)
{
  ui->setupUi(this);

  QPixmap bkgnd("/home/olga/Kursovaya/Resourses/background.png");
     bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
     QPalette p = palette();
     p.setBrush(QPalette::Window, bkgnd);
     setPalette(p);
}


Registration::~Registration()
{
  delete ui;
}

void Registration::on_pushButton_clicked()
{
    if(user.successConnection){
        QString Nickname{ui -> Nickname -> toPlainText()};
        QString password{ui -> password -> toPlainText()};
        if(user.checkForExistingUser(Nickname)){
            user.createNewUser(password, Nickname);
            close();
          }
        else ui -> Nickname -> setHtml("<font color=\"Red\">Данное имя уже занято");
      }

}

