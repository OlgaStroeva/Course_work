#include "account.h"

Account::Account(){
  db = QSqlDatabase::addDatabase("QMYSQL", "localhost");
  db.setUserName("root");
  db.setPassword("1KoTt&2!!");
  db.setDatabaseName("typeBetter");
  if(db.open()) successConnection = true;
}

bool Account::checkForExistingUser(QString Nickname) const{
  QSqlQuery query(db);
  query.prepare("SELECT Nickname FROM Accounts WHERE Nickname = :Nickname");
  query.bindValue(":Nickname", Nickname);
  bool ok{query.exec()};
  if(ok && query.next())
        return false;
  return true;
}

void Account::createNewUser(QString password, QString Nickname){
  QSqlQuery query(db);
  query.prepare("INSERT INTO Accounts (Nickname, password) VALUES(:Nickname,:password)");
  query.bindValue(":Nickname", Nickname);
  query.bindValue(":password", password);
  query.exec();

  query.prepare("INSERT INTO TasksOfUsers VALUES(:Nickname, FALSE, :Number, :AmountOfLeft)");
  QSqlQuery query1(db);
  query1.prepare("SELECT Count FROM TasksInfo WHERE Number = :Number");

  for(int i = 1, Count; i < 8; ++i){
      query.bindValue(":Nickname", Nickname);
      query.bindValue(":Number", i);

      query1.bindValue(":Number", i);

      if(query1.exec()){
          query1.last();
          Count = query1.value("Count").toInt();
          query.bindValue(":AmountOfLeft", Count);
        }
      query.exec();
    }
  this->Nickname = Nickname;
  CreateTasks();
}

bool Account::Authentification(QString Nickname, QString password){
  QSqlQuery query(db);
  bool ok = query.exec("SELECT password FROM Accounts WHERE Nickname = \'"+Nickname + "\'");
  if(ok){
      query.last();
      QString newPassword{query.value("password").toString()};
      if(password == newPassword){
         this->Nickname = Nickname;
         CreateTasks();
         return true;
        }
    }
  return false;
}

void Account::saveProgress(bool Language, int countOfEntered, int Time, int Mistakes, QString TextOfLevel, QString inputText, int Difficulty) const{
    if(Nickname != ""){
       QSqlQuery query(db);
       query.prepare(
       "INSERT INTO UsersProgress (Nickname, Language, CountOfEntered, Time, Mistakes, TextOfLevel, InputText, Difficulty) VALUES(:Nickname, :Language, :countOfEntered, :Time, :Mistakes, :TextOfLevel, :inputText, :Difficulty)");
       query.bindValue(":Nickname", Nickname); query.bindValue(":Language", Language);
       query.bindValue(":countOfEntered", countOfEntered - Mistakes);
       query.bindValue(":Time", Time); query.bindValue(":Mistakes", Mistakes);
       query.bindValue(":TextOfLevel", TextOfLevel); query.bindValue(":inputText", inputText);
       query.bindValue(":Difficulty", Difficulty);
       query.exec();
      }
}

UsersProgress *Account::getExistingProgress() const{
  UsersProgress *progress;
  QSqlQuery query(db);
  query.prepare("SELECT * FROM UsersProgress WHERE Nickname = :Nickname");
  query.bindValue(":Nickname", Nickname);
  query.exec();
  query.last();
  progress = new UsersProgress(query.value("Language").toBool(), query.value("CountOfEntered").toInt(),
                           query.value("Time").toInt(), query.value("Mistakes").toInt(),
                           query.value("TextOfLevel").toString(), query.value("InputText").toString(), query.value("Difficulty").toInt());
  deleteSavedProgress();
  return progress;

}

bool Account::checkForSavedProgress() const{
  QSqlQuery query(db);
  query.prepare("SELECT * FROM UsersProgress WHERE Nickname = :Nickname");
  query.bindValue(":Nickname", Nickname);
  query.exec();
  if(query.next())
  return true;
  else return false;
}

void Account::deleteSavedProgress() const {
  QSqlQuery query(db);
  query.prepare("DELETE FROM UsersProgress WHERE Nickname = :Nickname");
  query.bindValue(":Nickname", Nickname);
  query.exec();
}

void Account::CreateTasks(){
  QSqlQuery query(db);
  query.prepare("SELECT * FROM TasksOfUsers WHERE Nickname = :Nickname");
  query.bindValue(":Nickname", Nickname);
  query.exec();

  QSqlQuery query1(db);
  query1.prepare("SELECT * FROM TasksInfo WHERE Number = :Number ");

  while(query.next()){
      query1.bindValue(":Number", query.value("Number").toInt());
      query1.exec();
      query1.next();

      if(query.value("Completed").toBool()){
          currentTasks.createTask(query1.value("Text").toString(), !(query.value("Completed").toBool()));
        } else {
          currentTasks.createTask(query1.value("Text").toString(), query.value("AmountOfLeft").toInt(), query1.value("Count").toInt());
        }

    }
}

void Account::UpdateTasks(int Difficulty, int Time) const{
  QSqlQuery query(db);
  query.prepare("SELECT * FROM TasksOfUsers WHERE Nickname = :Nickname"); //ДБ прогресса пользователя
  query.bindValue(":Nickname", Nickname);
  query.exec();

  QSqlQuery query1(db);
  query1.prepare("SELECT * FROM TasksInfo"); //ДБ информации о заданиях
  query1.exec();

  QSqlQuery query2(db);
  query2.prepare("UPDATE TasksOfUsers SET AmountOfLeft = :AmountOfLeft WHERE Number = :Number AND Nickname = :Nickname");
  query2.bindValue(":Nickname", Nickname);

  QSqlQuery query3(db);
  query3.prepare("UPDATE TasksOfUsers SET Completed = TRUE WHERE Number = :Number AND Nickname = :Nickname");
  query3.bindValue(":Nickname", Nickname);

  int Number = 1;
  while(query.next()){
      query1.next();
      if(query.value("Completed").toBool()) continue;
      else{
          bool success = 1;

          int Type, diffOfTask, timeOfTask, AmountOfLeft;
          Type = query1.value("Type").toInt(); diffOfTask = query1.value("Difficulty").toInt();
          timeOfTask = query1.value("Time").toInt(); AmountOfLeft = query.value("AmountOfLeft").toInt();
          switch (Type) {
            case 2:
                success &= (Time<=timeOfTask);
            case 1:
              success &= (Difficulty == diffOfTask);
            case 0:
              success &= 1;
            }
          if(success){
              --AmountOfLeft;
              query2.bindValue(":Number", Number);
              query2.bindValue(":AmountOfLeft", AmountOfLeft);
              query2.exec();
              currentTasks.tasks[Number-1]->updateTask(AmountOfLeft);
              if(!(AmountOfLeft)){
                query3.bindValue(":Number", Number);
                query3.exec();
                }
            }
        }
      ++Number;
    }
}
