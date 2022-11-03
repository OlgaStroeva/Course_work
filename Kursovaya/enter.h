#ifndef ENTER_H
#define ENTER_H

#include <QDialog>
#include "registration.h"
#include "authentification.h"

namespace Ui {
  class Enter;
}

class Enter : public QDialog
{
  Q_OBJECT

public:
  //Account* user;
  explicit Enter(Account &user, QWidget *parent = nullptr);
  ~Enter();

private slots:
  void on_pushButton_2_clicked();

  void on_pushButton_clicked();

  void on_pushButton_3_clicked();

private:
  Account &user;
  Ui::Enter *ui;
};

#endif // ENTER_H
