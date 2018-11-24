//
// Created by nicho on 2018-11-14.
//

#include "tourPopulation.hpp"
void tourPopulation::addTour(tour* t){
    population.push_back(*t);
};
tour tourPopulation::getTour(int i) {
    return population.at(i);
}


void tourPopulation::select_parents(int poolSize) { // Takes PARENT_POOL_SIZE
    // Block
    for(int i = 0; i < poolSize; i++)
        potentialParents.push_back(population[rand()%population.size()]); // Add random parents to a potentialParent vector.
//    int parent1 = 0;
//    int parent2 = 1;
//    if(potentialParents.at(parent1).determine_fitness() < potentialParents.at(parent2).determine_fitness()){
//        parent1 = 1;
//        parent2 = 0;
//    }
//
//    // Block chooses the fittest 2 parents.
//    for(int i = 2; i < poolSize; i++){
//        if(potentialParents.at(parent1).determine_fitness() < potentialParents.at(i).determine_fitness()){
//            parent2 = parent1;
//            parent1 = i;
//        } else if (potentialParents.at(parent2).determine_fitness() < potentialParents.at(i).determine_fitness()){
//            parent2 = i;
//        }
//    }
//
//    // Block creates a child from 2 parents.
//    tour* child = new tour(); // Create a blank child tour.
//    int r = rand()%31; // Random index to choose 2 parents.
//    for(int i = 0; i < r; i++)
//        child->cityTour[i] = potentialParents[parent1].cityTour[i]; // Copy cities from parent 1 up to index r.
//    for(int i = r; i < 32; i++)
//        child[i].cityTour[i] = potentialParents[parent2].cityTour[i]; // Copy cities from parent 2 up to index end.
//    return child;
}

void tourPopulation::repopulate(){
    int eliteIndex = 0;
    for(int i = 1; i < population.size(); i++){ // Iterate through population to find the elite tour.
        if(population[i].determine_fitness() > population[eliteIndex].determine_fitness()){
            eliteIndex = i;
        }
    }
    tourPopulation* temp = new tourPopulation(); // Create a new object to seed from the current population.
    temp->addTour(&population[eliteIndex]); // Add elite to new population at index 0.
    for(int i = 1; i < population.size(); i++){  // Fill the rest of the population with children of the parent pool.
        tour* c = crossover(5);
        temp->addTour(c);
    }
    this->population = temp->population; // Make this objects population the new child population.
}
