#include <iostream>
#include "Population.hpp"

int main() {
  char target[] = "To be or not to be";
  float mutationRate = 0.01;
  int popmax = 200;
  
  std::srand(time(NULL));
  
  Population *population = 
    new Population(mutationRate, popmax, target);

  population->print();

  return 0;
}
