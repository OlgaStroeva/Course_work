#include "tasks.h"
#include "ui_tasks.h"

Tasks::Tasks(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Tasks)
{
  ui->setupUi(this);
  QPixmap bkgnd(":/Resourses/background.png");
     bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
     QPalette p = palette();
     p.setBrush(QPalette::Window, bkgnd);
     setPalette(p);
}

void Tasks::createTask(QString text, int AmountOfLeft, int Count){
  tasks[i] = new SingleTask(text, AmountOfLeft, Count);
  ui->TasksOfUser_5->addWidget(tasks[i]);
  ++i;
}

Tasks::~Tasks()
{
  this->hide();
}
