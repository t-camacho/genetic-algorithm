#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <list>
#include "DNA.hpp"
#include "Target.hpp"

class Population {
  private:
    float mutationRate;
    int popmax;
    std::list<DNA*> matingPool;
    Target *target;
    DNA **chromosomes;
  public:
    Population(float mutationRate, int popmax, Target *target);
    void naturalSelection();
    void generate();
    void print();
};

#endif
