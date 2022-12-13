#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QtSql/QSql>
#include <QtSql/QSqlDriver>
#include <QSqlQuery>
#include "tasks.h"

struct UsersProgress{
  bool Language;
  int countOfEntered = 0, Time = 0, Mistakes = 0 , Difficulty;
  QString TextOfLevel = "", inputText = "";
  UsersProgress(bool Language, int countOfEntered, int Time, int Mistakes, QString TextOfLevel, QString inputText, int Difficulty):
    Language(Language), countOfEntered(countOfEntered), Time(Time), Mistakes(Mistakes),
    TextOfLevel(TextOfLevel), inputText(inputText), Difficulty(Difficulty) {}
  UsersProgress(){}
};

class Account
{
public:
  QString Nickname = "";
  bool autnetificationSuccess = false, successConnection = false;
  Tasks currentTasks;

  Account();
  bool checkForExistingUser(QString Nickname) const;
  void createNewUser(QString, QString);
  bool Authentification(QString Nickname, QString password);
  void saveProgress(bool Language, int countOfEntered, int Time, int Mistakes, QString TextOfLevel, QString inputText, int Difficulty) const;
  void deleteSavedProgress() const;
  bool checkForSavedProgress() const;
  UsersProgress *getExistingProgress() const;
  void UpdateTasks(int Difficulty, int Time) const;

private:
  void CreateTasks();
  QSqlDatabase db;

};



#endif // ACCOUNT_H
