//
// Created by nicho on 2018-11-14.
//

#include "tourPopulation.hpp"
void tourPopulation::addTour(tour* t){
    population.push_back(*t);
};
void tourPopulation::crossover(int size) {
    for(int i = 0; i < size; i++)
        potentialParents.push_back(population[rand()%population.size()]);
    
}