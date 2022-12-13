#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include "available_chars.h"
#include "QPainter"
#include "QPalette"
#include "pause.h"
#include "report.h"
#include <QTimer>
#include <QTime>
#include "keyboard.h"

namespace Ui {
  class Level;
}

class Level : public QWidget
{
  Q_OBJECT

public:
  explicit Level(const Account &user, UsersProgress *progress, QWidget *parent = nullptr);
  Level(int Difficulty, bool Language, QWidget*, const Account &user, UsersProgress *progress = new UsersProgress());
  ~Level();
  //friend Pause;

private slots:
  void updateTime();
  void on_textEdit_textChanged();

  void on_pushButton_clicked();

private:
  QWidget *mainWindow = nullptr;
  QTimer *tmr;
  int mistakes = 0;
  int start = 0;
  const Account &user;
  bool lang;
  int countOfEnterd;
  Keyboard *chars;
  int sum = 0;

  Ui::Level *ui;
  void closeEvent (QCloseEvent *);
  //bool saved;
  void Mistakes(int count);
  //void Keyboard();
  int a = 1;
  Available_chars *text = nullptr;
  //void setText(int a);
  bool Continue = true;
  //Keyboard *keyboard;
  QString str = "", htmlStr;
  bool html = 1;
};

#endif // LEVEL_H
