#include "Target.hpp"

Target::Target(char *phrase) {
  this->phrase = phrase;
  this->length = strlen(phrase);
}

int Target::getLength() {
  return this->length;
}

char* Target::getPhrase() {
  return this->phrase;
}
