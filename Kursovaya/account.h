#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QtSql/QSql>
#include <QtSql/QSqlDriver>
#include <QSqlQuery>
#include "tasks.h"

#include <QDir>

struct UsersProgress{ //структура для обмена данными о сохраненном прогрессе с другими классами
  bool Language;
  int countOfEntered = 0, Time = 0, Mistakes = 0 , Difficulty;
  QString TextOfLevel = "", inputText = "";
  UsersProgress(bool Language, int countOfEntered, int Time, int Mistakes, QString TextOfLevel, QString inputText, int Difficulty):
    Language(Language), countOfEntered(countOfEntered), Time(Time), Mistakes(Mistakes),
    TextOfLevel(TextOfLevel), inputText(inputText), Difficulty(Difficulty) {}
  UsersProgress(){}
};

class Account //класс для взаимодействия с базой данных
{
public:
  QString Nickname = ""; //имя пользователя
  bool autnetificationSuccess = false, successConnection = false; //флаги, отображающие статус пользователя и соединения с базой данных
  Tasks currentTasks;

  Account();
  bool checkForExistingUser(QString Nickname) const; //проверка на существования пользователя с таким именем
  void createNewUser(QString, QString); //создание нового пользователя в базе данных
  bool Authentification(QString Nickname, QString password);
  void saveProgress(bool Language, int countOfEntered, int Time, int Mistakes, QString TextOfLevel, QString inputText, int Difficulty) const; //сохранение текущего прогресса тренировки пользователя
  void deleteSavedProgress() const; //удаление из базы данных сохраненного прогресса
  bool checkForSavedProgress() const; //проверка на существование сохраненного прогресса
  UsersProgress *getExistingProgress() const;//получение данных о сохраненном в базе прогрессе пользователя
  void UpdateTasks(int Difficulty, int Time) const; //обновление данных о заданиях в базе

private:
  void CreateTasks(); //получение данных о заданиях пользователя
  QSqlDatabase db;

};

#endif // ACCOUNT_H
