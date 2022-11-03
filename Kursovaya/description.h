#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <QWidget>

namespace Ui {
  class Description;
}

class Description : public QWidget
{
  Q_OBJECT

public:
  explicit Description(QWidget *parent = nullptr);
  Description(int a, int lang, QWidget* main);
  ~Description();
  void setLanguage(int i);

private slots:
  void on_pushButton_clicked();

private:
  Ui::Description *ui;
  int a, lang;
  QWidget* main;
};

#endif // DESCRIPTION_H
