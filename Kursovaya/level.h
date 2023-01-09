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

class Level : public QWidget //класс, обеспечивающий функционал тренировки "слепой" печати
{
  Q_OBJECT

public:
  explicit Level(const Account &user, UsersProgress *progress, QWidget *parent = nullptr);
  Level(int Difficulty, bool Language, QWidget*, const Account &user, UsersProgress *progress = new UsersProgress());
  ~Level();

private slots:
  void updateTime();
  void on_textEdit_textChanged();

  void on_pushButton_clicked();

private:
  QWidget *mainWindow = nullptr;
  QTimer *tmr;
  int mistakes = 0; //количество допущенных ошибок
  int start = 0;
  const Account &user;
  bool lang; //выбранный язык
  int countOfEnterd; //количество введённых символов
  Keyboard *chars;
  int sum = 0;

  Ui::Level *ui;
  void closeEvent (QCloseEvent *);
  void Mistakes(int count); //установка изображений, отражающих количество допущенных пользователем ошибок
  int a = 1;
  Available_chars *text = nullptr;
  bool Continue = true;
  QString str = "", htmlStr; //введенный пользователем текст, отформатированный формат введённого текста
  bool html = 1;
};

#endif // LEVEL_H
