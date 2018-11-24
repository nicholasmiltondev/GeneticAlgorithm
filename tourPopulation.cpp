//
// Created by nicho on 2018-11-14.
//

#include "tourPopulation.hpp"
void tourPopulation::addTour(tour* t){
    population.push_back(*t);
};
tour* tourPopulation::crossover(int poolSize) { // Takes PARENT_POOL_SIZE
    for(int i = 0; i < poolSize; i++)
        potentialParents.push_back(population[rand()%population.size()]); // Add random parents to a potentialParent vector.
    //std::sort(potentialParents.begin()->determine_fitness(), (potentialParents.end()- 1)->determine_fitness(), std::greater<double>()); // Sort low to high
    int parent1 = 0;
    int parent2 = 1;
    if(potentialParents.at(parent1).determine_fitness() < potentialParents.at(parent2).determine_fitness()){
        parent1 = 1;
        parent2 = 0;
    }

    for(int i = 2; i < poolSize; i++){
        if(potentialParents.at(parent1).determine_fitness() < potentialParents.at(i).determine_fitness()){
            parent2 = parent1;
            parent1 = i;
        } else if (potentialParents.at(parent2).determine_fitness() < potentialParents.at(i).determine_fitness()){
            parent2 = i;
        }
    }

    tour* child = new tour(); // Create a blank child tour.
    int r = rand()%31; // Random index to choose 2 parents.
    for(int i = 0; i < r; i++)
        child->cityTour[i] = potentialParents[parent1].cityTour[i]; // Copy cities from parent 1 up to index r.
    for(int i = r; i < 32; i++)
        child[i].cityTour[i] = potentialParents[parent2].cityTour[i]; // Copy cities from parent 2 up to index end.
    return child;
}

void tourPopulation::repopulate(){
    int eliteIndex = 0;
    for(int i = 1; i < population.size(); i++){
        if(population[i].determine_fitness() > population[eliteIndex].determine_fitness()){
            eliteIndex = i;
        }
    }
    tourPopulation* temp = new tourPopulation();
    temp->addTour(&population[eliteIndex]); // Add elite to new population.
    for(int i = 1; i < population.size(); i++){
        tour* c = crossover(5);
        temp->addTour(c);
    }
    this->population = temp->population;
}
