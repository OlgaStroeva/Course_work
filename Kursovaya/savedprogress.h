#ifndef SAVEDPROGRESS_H
#define SAVEDPROGRESS_H

#include <QDialog>

namespace Ui {
  class SavedProgress;
}

class SavedProgress : public QDialog //класс, позволяющий пользователю загрузить сохраненный прогресс тренировки, посредством класса Account
{
  Q_OBJECT

public:
  explicit SavedProgress(QWidget *parent = nullptr);
  ~SavedProgress();

private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

private:
  Ui::SavedProgress *ui;
};

#endif // SAVEDPROGRESS_H
