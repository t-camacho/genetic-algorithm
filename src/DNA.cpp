#include "DNA.hpp"

DNA::DNA(float mutationRate, int targetSize) {
  this->mutationRate = mutationRate;
  this->targetSize = targetSize;

  this->genes = (char*) std::malloc(targetSize * sizeof (char));

  for(int i = 0; i < targetSize; i++) {
    this->genes[i] = newChar();
  }
}

char* DNA::getGenes() {
  return this->genes;
}

char DNA::newChar() {
  int c;

  c = std::rand() % 59 + 63;  
  std::cout << c << std::endl;
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
  
  for(int i = 0; i < this->targetSize; i++) {
    /*if() {
    }*/
  }
}
