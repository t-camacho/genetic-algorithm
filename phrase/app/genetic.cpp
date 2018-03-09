#include <iostream>
#include "Population.hpp"
#include "Target.hpp"
#include "DNA.hpp"

void display(Population *population) {
  DNA *best;

  best = population->getBest();

  std::cout << std::endl;
  std::cout << "total generations: " 
    << population->getGeneration() << std::endl;

  std::cout << std::fixed;
  std::cout.precision(5);
  std::cout << "      best phrase: " << best->getGenes() << " (" 
    << best->getFitness() << ")" << std::endl;
}

int main() {
  char phrase[] = "To be or not to be\0";
  
  Target *target = new Target(phrase);
  float mutationRate = 0.01;
  int popmax = 150;

  
  std::srand(time(NULL));
  
  Population *population = 
    new Population(mutationRate, popmax, target);
 
  while(true) {
    population->naturalSelection();
    population->generate();
    population->calcFitness();
    
    display(population);

    if(population->isFinished()) {
      break;
    }
  }
  return 0;
}
