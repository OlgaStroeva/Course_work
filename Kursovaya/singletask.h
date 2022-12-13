#ifndef SINGLETASK_H
#define SINGLETASK_H

#include <QWidget>

namespace Ui {
  class SingleTask;
}

class SingleTask : public QWidget
{
  Q_OBJECT

public:
  explicit SingleTask(QWidget *parent = nullptr);
  SingleTask(QString text, int AmountOfLeft, int count);
  ~SingleTask();
  void updateTask(int Number);

private:
  int count;
  Ui::SingleTask *ui;
};

#endif // SINGLETASK_H
