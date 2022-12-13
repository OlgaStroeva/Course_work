#include "keyboard.h"
#include "ui_keyboard.h"


const QString symbols[] = {
  "1234567890-=",
  "`QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./",
  "ЁЙЦУКЕНГШЩЗХЪ\\ФЫВАПРОЛДЖЭЯЧСМИТЬБЮ.",
  "~!@#$%^&*()_+{}|:\"<>?", //2-й уровень
  "!\"№;%:?*()_+/,"
};




const int Left[3][4] = {{29, 117, 135, 160},  //отступы для простого уровня (построчно)
                        {20, 680, 632, 548},
                        {49, 137, 155, 180}}; //отступы для среднего уровня
const int Top[3][4] = {{42, 50, 55, 55},
                       {22, 53, 55, 55},
                       {50, 50, 55, 58}};

Keyboard::Keyboard(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Keyboard)
{
  ui->setupUi(this);
}

Keyboard::Keyboard(int difficulty, bool lang) : Keyboard(){
  this->difficulty = difficulty;
  this->lang = lang;
}

void Keyboard::paintEvent(QPaintEvent*){
  int top = 0, left = 0;
  painter = new QPainter(this);
  QFont font;
  font.setPixelSize(20);
  font.setBold(true);
  painter->setBrush(QColor(205, 1, 111));
  if(a == ' '){
      painter->drawRect(260, 230, 276, 45);
    }
  if(difficulty==3){
      keys[1][1][0][0] = '`';
    }
  for(int K = 0; K<difficulty; ++K){

      painter->setFont(font);
      for(int i=0; i<4; ++i){
          top+= Top[K][i];
          left = Left[K][i];
          for(int j = 0; j<keys[K][lang][i].length(); ++j){
              if(keys[K][lang][i][j] == a && a != ' ') painter->setPen(QColor(205, 1, 111));
              else painter->setPen(Qt::black);
              painter->drawText(left, top, keys[K][lang][i][j]);
              left += 57;
            }
        }
      top = 0;
      font.setPixelSize(15);
    }
 painter->end();
}

void Keyboard::setActivChar(QChar b){
  a = b.toUpper();
}

Keyboard::~Keyboard()
{
  delete painter;
  delete ui;
}
