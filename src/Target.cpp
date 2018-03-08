#include "Target.hpp"

Target::Target(char *phrase) {
  this->phrase = phrase;
  this->size = strlen(phrase);
}
