#ifndef AVAILABLE_CHARS_H
#define AVAILABLE_CHARS_H
#include "QString"

class Available_chars
{
public:
  Available_chars(int diff, int lang); // 0 - для всех текстов, 1 - английский, 2/3 - повышенный уровень сложности (средний), сложный - всё, везде и сразу
  QString set_text = "", main_text = "", main_text_len;
private:
  int count = 145;
};

#endif // AVAILABLE_CHARS_H