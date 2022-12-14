#ifndef REPORT_H
#define REPORT_H

#include <QDialog>

namespace Ui {
  class Report;
}

class Report : public QDialog //класс, отображающий результат тренировки пользователя
{
  Q_OBJECT

public:
  explicit Report(QWidget *parent = nullptr);
  Report(int, QString, QString, int);
  ~Report();

private:
  Ui::Report *ui;
};

#endif // REPORT_H
