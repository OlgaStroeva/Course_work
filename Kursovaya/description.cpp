#include "description.h"
#include "ui_description.h"
#include "qmessagebox.h"
#include "level.h"

const QString difficult[] = {"Простой", "Средний", "Сложный"};

Description::Description(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Description)
{
  ui->setupUi(this);
}

Description::Description(int a, int lang, QWidget* main) : Description(){
  this->main = main;
  this->a = a;
  this->lang = lang;
  ui->label->setText(difficult[a]);
  ui->pushButton->setStyleSheet("background-image: url(:/Resourses/back" + QString::number(a+1) + ".png);");
}

Description::~Description()
{
  delete ui;
}
void Description::setLanguage(int i){
  lang = i;
}


void Description::on_pushButton_clicked()
{
  Level *level = new Level(a+1, lang, main);
  level->setWindowTitle("Level");
  level->show();
  main->hide();
}

