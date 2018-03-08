#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "DNA.hpp"

class Population {
  private:
    float mutationRate;
    int popmax, targetSize;
    char *target;
    DNA **chromosomes;
  public:
    Population(float mutationRate, int popmax, char *target);
    void print();
};

#endif
