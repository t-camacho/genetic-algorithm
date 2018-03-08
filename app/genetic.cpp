#include <iostream>
#include "Population.hpp"
#include "Target.hpp"

int main() {
  char phrase[] = "To be or not to be";
  
  Target *target = new Target(phrase);
  float mutationRate = 0.01;
  int popmax = 200;

  
  std::srand(time(NULL));
  
  Population *population = 
    new Population(mutationRate, popmax, target);
  
  int f = 0;
  while(f < 16) {
    population->naturalSelection();
    population->generate();
    population->calcFitness();
    
    //if(population->isFinished()) {
     // break;
    //}
    f++;
  }
  population->print(); 
  return 0;
}
