#ifndef TASKS_H
#define TASKS_H

#include <QWidget>
#include "singletask.h"

namespace Ui {
  class Tasks;
}

class Tasks : public QWidget //класс, отображающий все задания пользователя
{
  Q_OBJECT

public:
  explicit Tasks(QWidget *parent = nullptr);
  ~Tasks();
  void createTask(QString text, int AmountOfLeft, int Count = 0);
    SingleTask **tasks = new SingleTask*[7];

private:
  int i = 0;
  Ui::Tasks *ui;
};

#endif // TASKS_H
