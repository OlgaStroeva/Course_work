#ifndef PAUSE_H
#define PAUSE_H

#include <QDialog>
#include "account.h"

namespace Ui {
  class Pause;
}

class Pause : public QDialog
{
  Q_OBJECT

public:
  explicit Pause(const Account &user, QWidget *parent = nullptr);
  ~Pause();

private slots:
  void on_pushButton_3_clicked();

  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

private:
  Ui::Pause *ui;
  QWidget *parent;
  const Account &user;
};

#endif // PAUSE_H
