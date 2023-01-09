#ifndef AVAILABLE_CHARS_H
#define AVAILABLE_CHARS_H
#include "QString"

class Available_chars //класс, генерирующий тексты
{
public:
  Available_chars(int diff, int lang); // 0 - для всех текстов, 1 - английский, 2/3 - повышенный уровень сложности (средний), сложный - всё, везде и сразу
  Available_chars(QString Text);
  QString set_text = "", main_text = "", main_text_len; //отформатированный для удобства просмотра пользователем текст, исходный текст, длина текста
private:
  int count = 100; //количество символов в тексте
};

#endif // AVAILABLE_CHARS_H
