#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <account.h>

namespace Ui {
  class Registration;
}

class Registration : public QDialog
{
  Q_OBJECT

public:
  explicit Registration(Account &user, QWidget *parent = nullptr);
  ~Registration();


private slots:
  void on_pushButton_clicked();

private:
  Account &user;
  Ui::Registration *ui;

};

#endif // REGISTRATION_H
