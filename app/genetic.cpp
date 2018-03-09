#include <iostream>
#include "Population.hpp"
#include "Target.hpp"
#include "DNA.hpp"

int main() {
  DNA *best;
  //char phrase[] = "To be or not to be\0";
  char phrase[] = "Hello\0";
  
  Target *target = new Target(phrase);
  float mutationRate = 0.1;
  int popmax = 200;

  
  std::srand(time(NULL));
  
  Population *population = 
    new Population(mutationRate, popmax, target);
 
  int f = 0;
  while(f < 100) {
    population->naturalSelection();
    population->generate();
    population->calcFitness();
    
    best = population->getBest();
    std::cout << std::fixed;
    std::cout.precision(5);
    std::cout << best->getGenes() << " " << best->getFitness() << std::endl;

    if(population->isFinished()) {
      std::cout << "eend" << std::endl;
      break;
    }
    //f++;
  }
  return 0;
}
