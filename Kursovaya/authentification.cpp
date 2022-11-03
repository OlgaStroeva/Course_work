#include "authentification.h"
#include "ui_authentification.h"

Authentification::Authentification(Account &user, QWidget *parent) : user(user),
  QDialog(parent),
  ui(new Ui::Authentification)
{
  ui->setupUi(this);
  ui->label_4->setStyleSheet("color: #FF0000");

  QPixmap bkgnd("/home/olga/Kursovaya/Resourses/background.png");
     bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
     QPalette p = palette();
     p.setBrush(QPalette::Window, bkgnd);
     setPalette(p);
}

Authentification::~Authentification()
{
  delete ui;
}

bool autnetificationSuccess;
QString nickname;

void Authentification::on_pushButton_clicked()
{
  nickname = ui->textEdit->toPlainText();
  autnetificationSuccess = nickname=="nick" && ui->textEdit_2->toPlainText() == "0";
  if (!(autnetificationSuccess)){
    ui->label_4->setText("Неправильный пароль или логин");
    }
  else{
        user.Nickname = nickname;
        close();
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
