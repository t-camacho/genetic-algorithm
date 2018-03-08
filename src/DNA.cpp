#include "DNA.hpp"

DNA::DNA(float mutationRate, Target *target) {
  this->mutationRate = mutationRate;
  this->target = target;

  this->genes = (char*) std::malloc(target->getLength() * sizeof (char));

  for(int i = 0; i < target->getLength(); i++) {
    this->genes[i] = newChar();
  }
  calcFitness();
}

char* DNA::getGenes() {
  return this->genes;
}

float DNA::getFitness() {
  return this->fitness;
}

char DNA::newChar() {
  int c;

  c = std::rand() % 59 + 63;  
  
  if(c == 63) {
    c = 32;
  }
  if(c == 64) {
    c = 45;
  }

  return (char) c;
}

void DNA::calcFitness() {
  int total = 0;
  char *phrase = target->getPhrase();  
  
  for(int i = 0; i < target->getLength(); i++) {
    if(this->genes[i] == phrase[i]) {
      total++;
    }
  }
  
  this->fitness = (float)total / (float)target->getLength();
}

DNA* DNA::crossover(DNA *parent) {
  DNA *child =  new DNA(this->mutationRate, this->target);
  int midpoint = rand() % target->getLength();
  
  for(int i = 0; i < target->getLength(); i++) {
    if(i < midpoint) child->genes[i] = this->genes[i];
    else child->genes[i] = parent->genes[i];
  } 
  
  return child;
}
