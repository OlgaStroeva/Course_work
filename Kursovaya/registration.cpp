#include "registration.h"
#include "ui_registration.h"

Registration::Registration(Account &user, QWidget *parent) :
  QDialog(parent),
  user(user),
  ui(new Ui::Registration)
{
  ui->setupUi(this);

  QPixmap bkgnd(":/Resourses/background.png");
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
        try{

        if(Nickname=="") throw 0;
        else if (password =="") throw 1;
        else if(Nickname.length()>255) throw 2;
        else if(password.length()>30) throw 3;

        if(user.checkForExistingUser(Nickname)){
            user.createNewUser(password, Nickname);
            close();
          }
        else ui -> Nickname -> setHtml("<font color=\"Red\">Данное имя уже занято");
        } catch(int a){
          switch (a) {
          case 1:
              ui -> password -> setHtml("<font color=\"Red\">Введите пароль");
              break;
          case 0:
            ui -> Nickname -> setHtml("<font color=\"Red\">Введите имя");
              break;
          case 2:
              ui -> Nickname -> setText(Nickname.left(255));
              break;
          case 3:
              ui->password->setText(password.left(30));

        }
      }
  }
}

