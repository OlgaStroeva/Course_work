#include "registration.h"
#include "ui_registration.h"
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>

Registration::Registration(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Registration)
{
  ui->setupUi(this);

  QPixmap bkgnd("/home/olga/Kursovaya/Resourses/background.png");
     bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
     QPalette p = palette();
     p.setBrush(QPalette::Window, bkgnd);
     setPalette(p);
}


//ОБЯЗАТЕЛЬНО дописать проверку БД на такие же имена, потому что это - ключ и всё упадёт, если писать без этого. Ну, не прям всё, но пользователи будут спокойно переписывать чужие пароли


Registration::~Registration()
{
  delete ui;
}

void Registration::on_pushButton_clicked()
{
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("1KoTt&2!!");
    db.setDatabaseName("typeBetter");
    bool ok = db.open();
    if(ok){
        db.close();
      close();
      }*/

}

