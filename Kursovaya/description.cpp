#include "description.h"
#include "ui_description.h"

const QString difficult[] = {"Простой", "Средний", "Сложный"};

Description::Description(const Account &user, QWidget *parent) :
  QWidget(parent),
  user(user),
  ui(new Ui::Description)
{
  ui->setupUi(this);
}

Description::Description(int a, int lang, QWidget* main, const Account &user) : Description(user){
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
  Level *level;
      if(user.Nickname != "" && user.checkForSavedProgress()){
          main->setEnabled( false );
          SavedProgress *saved = new SavedProgress();
          if(saved->exec() == QDialog::Accepted){
              UsersProgress *progress = user.getExistingProgress();
              level = new Level(progress->Difficulty, progress->Language, main /* this*/, user, progress);

            } else{
            user.deleteSavedProgress();
            level = new Level(a+1, lang, main, user);
            }
  } else
  level = new Level(a+1, lang, main, user);
      main->setEnabled( true );
  level->setWindowTitle("Level");
  level->show();
  //main->hide();
}

