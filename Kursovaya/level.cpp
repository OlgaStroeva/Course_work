#include "level.h"
#include "ui_level.h"
#include "QPainter"
#include "QKeyEvent"
#include "QPalette"
#include "pause.h"
#include "report.h"

Level::Level(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Level)
{
  ui->setupUi(this);
}

Level::Level(int a, bool lang, QWidget *main) : Level(){
  mainWindow = main;
  this->a = a;
  this->text = new Available_chars(a, lang);
  ui->text->setText(text->set_text);
  //setText(a);
  ui->progress->setText(QString::number(0) + "/" + text->main_text_len);
  ui->textEdit->setFocus();
  tmr = new QTimer();
  connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
  tmr->start(1000);

  if(a==3){
    ui->text->setStyleSheet("color: rgb(255, 255, 255);");
    ui->time_spend->setStyleSheet("color: rgb(255, 255, 255);");
    ui->progress->setStyleSheet("color: rgb(255, 255, 255);");
    }

  if(lang) ui->lang->setStyleSheet("background-image: url(:/Resourses/icons8-russian-federation-100.png);");
  else ui->lang->setStyleSheet("background-image: url(:/Resourses/icons8-great-britain-100.png);");

  QPixmap bkgnd("/home/olga/Kursovaya/Resourses/background" + QString::number(this->a) + ".jpg");
  bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
  QPalette p = palette();
  p.setBrush(QPalette::Window, bkgnd);
  setPalette(p);
}

Level::~Level()
{
  delete text;
  delete tmr;
  delete ui;
}

void Level::closeEvent (QCloseEvent *) //при закрытии окошка видно только Main немножко
{
  Continue = false;
  Report *report = new Report(
        a,
        QString::number(start/60) + (start%60>9 ? ":" : ":0") + QString::number(start%60),
        QString::number(str.length()-mistakes*46) + "/" + text->main_text_len,
        mistakes
        );
  report->exec();
  //delete this;
  mainWindow->show();
}

void Level::Mistakes(int count){
  switch(count){
    case 1:
      ui->mistake1->setStyleSheet("background-image: url(:/Resourses/mistake.png);");
      break;
    case 2:
      ui->mistake2->setStyleSheet("background-image: url(:/Resourses/mistake.png);");
      break;
    case 3:
      ui->mistake3->setStyleSheet("background-image: url(:/Resourses/mistake.png);");
      break;

    }
}

void Level::Keyboard(){
 //Тут кароч должны ставиться красивые буковки, соответствующие доступным символам
}

/*void Level::setText(int a){ //тут ставится текст
  ui->text->setText(text->set_text);
}*/

void Level::updateTime(){
  if(Continue){
    ++start;
    ui->time_spend->setText(QString::number(start/60) + (start%60>9 ? ":" : ":0") + QString::number(start%60));
    }
}

void Level::on_textEdit_textChanged()
{
  if(html){
  tempStr = ui->textEdit->toPlainText();
    if(tempStr.length() > str.length()-mistakes*45) {
        str.append(tempStr[tempStr.length()-1]);
        ui->textEdit->moveCursor(QTextCursor::End);
        QChar a = str[str.length()-1], b = (text->main_text)[str.length()-1-mistakes*46];
        if(QString::compare(a, b)!=0){
            ++mistakes;
            if(mistakes<=3)
              Mistakes(mistakes);//update();
          str.insert(str.length()-1, "<font color=\"Red\">");
          str.append("</font><font color=\"Black\">");
          } else {
            ui->progress->setText(QString::number(str.length()-mistakes*46) + "/" + text->main_text_len);
          }
    }
    html = 0;
    ui->textEdit->setHtml(str);
    if(str.length()-mistakes*46 == (text->main_text_len).toInt()){
      close();
      }
    html = 1;
    ui->textEdit->moveCursor(QTextCursor::End);
    }
}


void Level::on_pushButton_clicked()
{
  Continue = false;
    Pause *pause = new Pause;
    pause->exec();
  Continue = true;
}

