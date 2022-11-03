#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include "available_chars.h"
#include "mainwindow.h"
#include <QTimer>
#include <QTime>

namespace Ui {
  class Level;
}

class Level : public QWidget
{
  Q_OBJECT
protected:
  //virtual void keyPressEvent(QKeyEvent *event);

public:
  explicit Level(QWidget *parent = nullptr);
  Level(int, bool, QWidget*);
  ~Level();  

private slots:
  void updateTime();
  void on_textEdit_textChanged();

  void on_pushButton_clicked();

private:
  QWidget *mainWindow = nullptr;
  QTimer *tmr;
  int mistakes = 0;
  int start = 0;
  Ui::Level *ui;
  void closeEvent (QCloseEvent *);
  //void paintEvent(QPaintEvent*);
  void Mistakes(int count);
  void Keyboard();
  int a = 1;
  Available_chars *text;
  //void setText(int a);
  bool Continue = true;
  QString str = "", tempStr;
  bool html = 1;
};

#endif // LEVEL_H
