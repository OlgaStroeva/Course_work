#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H

#include <QDialog>
#include <account.h>
//#include "enter.h"

namespace Ui {
  class Authentification;
}

class Authentification : public QDialog
{
  Q_OBJECT

public:
  //Account *user = nullptr;
  Authentification(Account &user, QWidget *parent = nullptr);
  ~Authentification();

private slots:
  void on_pushButton_clicked();

  void on_textEdit_textChanged();

  void on_textEdit_2_textChanged();

private:
  Account &user;
  Ui::Authentification *ui;
};

#endif // AUTHENTIFICATION_H
