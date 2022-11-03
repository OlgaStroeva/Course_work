#include "report.h"
#include "ui_report.h"

Report::Report(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Report)
{
  ui->setupUi(this);
  ui->setupUi(this);
  QPixmap bkgnd("/home/olga/Kursovaya/Resourses/background.png");
     bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
     QPalette p = palette();
     p.setBrush(QPalette::Window, bkgnd);
     setPalette(p);
}

const QString difficult[] = {"Простой", "Средний", "Сложный"};

Report::Report(int diff, QString time, QString count, int mistakes) : Report(){
    ui->label_3->setText(difficult[diff-1]);
    ui->label_5->setText(time);
    ui->label_7->setText(count);
    ui->label_9->setText(QString::number(mistakes));
}

Report::~Report()
{
  delete ui;
}
