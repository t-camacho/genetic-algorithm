#include "Population.hpp"

Population::Population(float mutationRate, int popmax, char *target) {
  this->mutationRate = mutationRate;
  this->popmax = popmax;
  this->target = target;
  this->targetSize = std::strlen(target);
  this->chromosomes = (DNA**) std::malloc(popmax * sizeof (DNA*));

  for(int i = 0; i < popmax; i++) {
    this->chromosomes[i] = new DNA(mutationRate, targetSize);
  }
}


void Population::print() {
  for(int i = 0; i < this->popmax; i++) {
    std::cout << this->chromosomes[i]->getGenes() << std::endl;
  }
}
