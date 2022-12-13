#include "tasks.h"
#include "ui_tasks.h"

Tasks::Tasks(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Tasks)
{
  ui->setupUi(this);
  //ui->scrollArea->setVerticalScrollBar(ui->verticalScrollBar);
  //ui->scrollArea->setLayout(ui->TasksOfUser);

  QPixmap bkgnd("/home/olga/Kursovaya/Resourses/background.png");
     bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
     QPalette p = palette();
     p.setBrush(QPalette::Window, bkgnd);
     setPalette(p);
     //ui->scrollArea->setWidget(ui->widget);
     //ui->scrollArea->setVerticalScrollBar(ui->verticalScrollBar);

}

void Tasks::createTask(QString text, int AmountOfLeft, int Count){
  tasks[i] = new SingleTask(text, AmountOfLeft, Count);
  //ui->scrollArea->setWidget(tasks[i]);
  //ui->scrollArea->addScrollBarWidget(tasks[i], Qt::AlignTop);
  ui->TasksOfUser_5->addWidget(tasks[i]);
  //ui->scrollAreaWidgetContents->ad
  ++i;
  //if(i==6)
}

Tasks::~Tasks()
{
  this->hide();
  //delete ui;
}
