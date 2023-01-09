#include "singletask.h"
#include "ui_singletask.h"

SingleTask::SingleTask(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::SingleTask)
{
  ui->setupUi(this);
}

SingleTask::SingleTask(QString text, int AmountOfLeft, int count) : SingleTask(){
  this->count = count;
  ui->TextOfTask->setText(text);
  updateTask(AmountOfLeft);
}

SingleTask::~SingleTask()
{
  delete ui;
}

void SingleTask::updateTask(int AmountOfLeft){
  if(AmountOfLeft <=0){
      ui->count->setText("");
      ui->count->setStyleSheet("background-image: url(:/Resourses/star(1).png);");}
  else ui->count->setText(QString::number(count - AmountOfLeft) + "/" + QString::number(count));
}
