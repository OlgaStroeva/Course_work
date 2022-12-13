#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QPainter>

namespace Ui {
  class Keyboard;
}

class Keyboard : public QWidget
{
  Q_OBJECT

public:
  explicit Keyboard(QWidget *parent = nullptr);
  Keyboard(int difficulty, bool lang);
  ~Keyboard();
  void setActivChar(QChar a);
  QPainter *painter;


private:
  QChar A, a;

  void paintEvent(QPaintEvent*);
  Ui::Keyboard *ui;
  int difficulty; bool lang = 0;
  QString keys[3][2][4] = {
    {{"`1234567890-=", //easy
      "QWERTYUIOP[]",
      "ASDFGHJKL;\'\\",
      "ZXCVBNM,./"},
      {"Ё1234567890-=",
      "ЙЦУКЕНГШЩЗХЪ",
       "ФЫВАПРОЛДЖЭ\\",
      "ЯЧСМИТЬБЮ."}},
    {{"~!@#$%^&*()_+", //middle
      "{}",
      ":\"|",
      "<>?"},
      {" !\"№;%:?*()_+",
      "/",
      "",
      ","}},
    {{"Ё \"№; :?", //hard
      "ЙЦУ   ГШЩЗ Ъ",
      "ФЫ  П  ЛДЖЭ/",
      "ЯЧ  И ЬБЮ,"},
      {"~ @#$ ^&",
      "QW R YUI  []",
      " SDFG J L;\'|",
      "Z  V N ,./"}}
  };
};

#endif // KEYBOARD_H
