#include "Population.hpp"

Population::Population(float mutationRate, int popmax, Target *target) {
  this->mutationRate = mutationRate;
  this->popmax = popmax;
  this->target = target;
  this->chromosomes = (DNA**) std::malloc(popmax * sizeof (DNA*));

  for(int i = 0; i < popmax; i++) {
    this->chromosomes[i] = new DNA(mutationRate, target);
  }
}


void Population::print() {
  std::cout << std::fixed;
  std::cout.precision(4);
  for(int i = 0; i < this->popmax; i++) {
    std::cout << this->chromosomes[i]->getGenes() << " " <<
       this->chromosomes[i]->getFitness() << std::endl;
  }
}

float map(float value, float maxFitness) {
  return value / maxFitness;
}

void Population::select() {
  float maxFitness = 0, buffer;
  int n;

  matingPool.remove();

  for(int i = 0; i < this->target->getLength(); i++) {
    if(this->chromosomes[i]->getFitness() > maxFitness) {
      maxFitness = this->chromosomes[i]->getFitness();
    }
  }
  
  for(int i = 0; i < this->target->getLength(); i++) {
    buffer = map(this->chromosomes[i]->getFitness(), maxFitness);
    n = buffer * 100;
    for(int i = 0; i < n; i++) {
      matingPool.push_back(this->chromosomes[i]);
    }
  }
}
