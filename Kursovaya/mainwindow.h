#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <account.h>
#include "description.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  //Account *user;

private slots:
  //void on_pushButton_clicked();

  void on_comboBox_activated(int index);

private:
  Account user;
  Ui::MainWindow *ui;
  Description **descr = new Description*[3];
};
#endif // MAINWINDOW_H
