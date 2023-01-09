#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "enter.h"
#include "description.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow //класс основного меню приложения
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:

  void on_comboBox_activated(int index);

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

private:
  Account user;
  Ui::MainWindow *ui;
  Description **descr = new Description*[3]; //уровни сложности
};
#endif // MAINWINDOW_H
