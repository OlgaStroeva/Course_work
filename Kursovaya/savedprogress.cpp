#include "savedprogress.h"
#include "ui_savedprogress.h"

SavedProgress::SavedProgress(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::SavedProgress)
{
  ui->setupUi(this);

  QPixmap bkgnd("/home/olga/Kursovaya/Resourses/background.png");
     bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
     QPalette p = palette();
     p.setBrush(QPalette::Window, bkgnd);
     setPalette(p);
}

SavedProgress::~SavedProgress()
{
  delete ui;
}

void SavedProgress::on_pushButton_clicked()
{
  accept();
}

void SavedProgress::on_pushButton_2_clicked()
{
    reject();
}
