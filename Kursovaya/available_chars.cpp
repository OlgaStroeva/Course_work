#include "available_chars.h"
#include "Random.hpp"

const QString chars_for_texts[] = { " 1234567890-=",
                          "`qwertyuop[]\\asdfghjkl;'zxcvbnm,./",
                          "ёйцукенгшщзхъ\\фывапролджэячсмитьбю.",
                          "~@#$^&{}|<>*",
                          "№;/,",
                            "QWERTYUIOPASDFGHJKLZXCVBNMЙЦУГШЩЪФЫПЛДЖЭЯЧИЬБЮ",
                            "ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮQWRYUI[]SDFGJL;\'ZCVN/",
                                  "ёйцукнгшщзъфывплджэячмитьбю",
                                  "qwrtyui[]sdfghjkl\'zvbnm`"};

Available_chars::Available_chars(int diff, int lang)
{
  QString rez_alphabet = chars_for_texts[0] + chars_for_texts[lang+1]; //лёгкий
  if(diff>1) rez_alphabet += "!%*()_+:?\""+ chars_for_texts[3+lang]; //средний
  if(diff>2){
      rez_alphabet += chars_for_texts[5+lang] + chars_for_texts[7+lang];
    }
  int size = rez_alphabet.length();
  QChar symb =rez_alphabet[Random::get(1, size-1)];
  set_text.append(symb);
  main_text.append(symb);
  for (int i = 1; i < count; ++i)
  {
      symb = rez_alphabet[Random::get(0, size-1)];
      set_text.append(symb);
      main_text.append(symb);
      if(!(i%28) && symb != ' ') set_text.append('\n');
  }
  main_text_len = QString::number(main_text.length());
}

Available_chars::Available_chars(QString Text){
  main_text = Text;
  set_text = Text;
  for(int i = 28; i< count; i+= 29)
    set_text.insert(i, "\n");
  main_text_len = QString::number(main_text.length());
}
