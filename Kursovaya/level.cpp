#include "level.h"
#include "ui_level.h"
#include "exception"
//лабораторные наследование и виртуальность
//Спарвочная система
//Добавить звук событий
//Добавить hint
//горячие клавиши
//контекстное меню подумать
//дописать try cathc для соединения с БД +-
Level::Level(const Account &user, UsersProgress *progress, QWidget *parent) :
  QWidget(parent),
  user(user),
  ui(new Ui::Level)
{
  ui->setupUi(this);
  countOfEnterd = progress->countOfEntered;
  start = progress->Time;
  htmlStr = progress->inputText;
  mistakes = progress->Mistakes;
  for(int i = 1; i<=mistakes && mistakes!=0; ++i){
      Mistakes(i);
    }
  html = 0;
  ui->textEdit->setHtml(htmlStr);
  ui->textEdit->moveCursor(QTextCursor::End);
  html = 1;
  if(progress->TextOfLevel != ""){
      text = new Available_chars(progress->TextOfLevel);
    }
}

Level::Level(int a, bool lang, QWidget *main, const Account &user, UsersProgress *progress) : Level(user, progress) { //Тут надо вставлять ТОЛЬКО после user
  mainWindow = main;
  main->hide();
  this->a = a;
  this->lang = lang;

  if(text == nullptr)
  this->text = new Available_chars(a, lang);

  ui->text->setText(text->set_text);
  chars = new Keyboard(a, lang);
  int i = (ui->textEdit->toPlainText()).length(); //+ ((ui->textEdit->toPlainText()).length() ? -1 : 0) ;
  chars->setActivChar((text->main_text)[i - mistakes]);
  ui->verticalLayout->addWidget(chars);

  //setText(a);
  ui->progress->setText(QString::number(countOfEnterd) + "/" + text->main_text_len);
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
        QString::number(str.length()-mistakes) + "/" + text->main_text_len,
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


void Level::updateTime(){
  if(Continue){
    ++start;
    ui->time_spend->setText(QString::number(start/60) + (start%60>9 ? ":" : ":0") + QString::number(start%60));
    }
}

void Level::on_textEdit_textChanged()
{
  if(html){
      int N = 1;
    if((ui->textEdit->toPlainText()).length() > str.length()) {
        str = ui->textEdit->toPlainText();
        if(str[str.length()-1] == '<'){
          htmlStr.append("&lt;"); // < = &it; > = &gt;
          N = 4;
          }
        else if(str[str.length()-1] == '>'){
          htmlStr.append("&gt;");
          N = 4;
          }
        else{
          htmlStr.append(str[str.length()-1]);
          N = 1;
          }
        ui->textEdit->moveCursor(QTextCursor::End);
        try {
        QChar a = str[str.length()-1], b = (text->main_text)[str.length()-1-mistakes];
        if(QString::compare(a, b)!=0){
            ++mistakes;
            if(mistakes<=3)
              Mistakes(mistakes);
          htmlStr.insert(htmlStr.length()-N, "<font color=\"Red\">");
          htmlStr.append("</font><font color=\"Black\">");
          }
              ui->progress->setText(QString::number(str.length()-mistakes) + "/" + text->main_text_len);
              if(str == (text->main_text)) throw true;
              chars->setActivChar((text->main_text)[str.length()-mistakes]);
              chars->repaint();

            }  catch (...) {
              if(user.Nickname != "" && mistakes<=3) user.UpdateTasks(this->a, start);
              close();
              return;
            }
    }
    html = 0;
    ui->textEdit->setHtml("<body>" + htmlStr + "</body>");
    html = 1;
    ui->textEdit->moveCursor(QTextCursor::End);
    }
}

void Level::on_pushButton_clicked()
{
  Continue = false;
    Pause *pause = new Pause(user, this);
    int command = pause->exec();
    if( command == QDialog::Accepted) close();
    if( command == 3){
        user.saveProgress(lang, str.length(), start, mistakes, text->main_text, htmlStr, a);
        close();
      }
  Continue = true;
}

