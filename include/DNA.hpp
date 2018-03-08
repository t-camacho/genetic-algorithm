#ifndef DNA_HPP
#define DNA_HPP

#include <iostream>
#include <cstdlib>

class DNA {
  private:
    int targetSize;
    float fitness, mutationRate;
    char *genes;
  public:
    DNA(float mutationRate, int targetSize);
    char* getGenes();
    char newChar();
};

#endif
