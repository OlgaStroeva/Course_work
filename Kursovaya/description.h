#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <QWidget>
#include "level.h"
#include "savedprogress.h"

namespace Ui {
  class Description;
}

class Description : public QWidget //класс для отображения выбора уровня сложности
{
  Q_OBJECT

public:
  explicit Description(const Account &user, QWidget *parent = nullptr);
  Description(int a, int lang, QWidget* main, const Account &user);
  ~Description();
  void setLanguage(int i);//установка языка для всех уровней сложности

private slots:
  void on_pushButton_clicked();

private:
  const Account &user;
  Ui::Description *ui;
  int a, lang; //номер уровня сложности и языка
  QWidget* main;
};

#endif // DESCRIPTION_H
