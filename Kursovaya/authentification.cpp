#include "authentification.h"
#include "ui_authentification.h"

Authentification::Authentification(Account &user, QWidget *parent) :
  QDialog(parent),
  user(user),
  ui(new Ui::Authentification)
{
  ui->setupUi(this);
  ui->label_4->setStyleSheet("color: #FF0000");

  QPixmap bkgnd(":/Resourses/background.png");
     bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
     QPalette p = palette();
     p.setBrush(QPalette::Window, bkgnd);
     setPalette(p);
}

Authentification::~Authentification()
{
  delete ui;
}

void Authentification::on_pushButton_clicked()
{
  if(user.successConnection){
      QString Nickname = ui -> textEdit -> toPlainText();
      QString password = ui -> textEdit_2 -> toPlainText();
      if(user.Authentification(Nickname, password))
         close();
      else
        ui->label_4->setText("Неправильный пароль или логин");
    }
}

void Authentification::on_textEdit_textChanged()
{
    ui->label_4->setText("");
}


void Authentification::on_textEdit_2_textChanged()
{
    on_textEdit_textChanged();
}
