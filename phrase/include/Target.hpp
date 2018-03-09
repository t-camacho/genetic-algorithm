#ifndef TARGET_HPP
#define TARGET_HPP

#include "cstring"

class Target {
  private:
    int length;
    char *phrase;
  public:
    Target(char *phrase);
    int getLength();
    char* getPhrase();
};

#endif
