//
// Created by nicho on 2018-11-14.
//

#include "tourPopulation.hpp"

void tourPopulation::addTour(tour* t){ // Adds tour to population.
    population.push_back(*t);
};
void tourPopulation::addChild(tour* t){ // Adds tour to nextGeneration.
    nextGeneration.push_back(*t);
};
tour tourPopulation::getTour(int i) { // returns a tour at index position.
    return population.at(i);
}
tour tourPopulation::getChild(int i) { // returns a tour at index position.
    return nextGeneration.at(i);
}
void tourPopulation::findCopyElite() {
    int eliteIndex = 0;
    for (int i = 1; i < population.size(); i++) { // Iterate through population to find the elite tour.
        if (population[i].determine_distance() < population[eliteIndex].determine_distance()) {
            eliteIndex = i;
        }
    }
    //std::cout << population[eliteIndex].getTourName();
    this->addChild(&population[eliteIndex]);
}

void tourPopulation::select_parents(int poolSize) { // Takes PARENT_POOL_SIZE
    for (int i = 0; i < poolSize; i++) {
        int rIndex = rand() % population.size();
        std::cout << "Selecting parent at index " << rIndex << std::endl;
        potentialParents.push_back(population[rIndex]); // Add random parents to a potentialParent vector.
    }
}

void tourPopulation::crossover() {
    int parent1 = 0;
    int parent2 = 1;
    if(potentialParents.at(parent1).determine_distance() > potentialParents.at(parent2).determine_distance()){
        parent1 = 1;
        parent2 = 0;
    }
    //Block chooses the fittest 2 parents.
    for(int i = 2; i < 5; i++){
        if(potentialParents.at(parent1).determine_distance() > potentialParents.at(i).determine_distance()){
            parent2 = parent1;
            parent1 = i;
        } else if (potentialParents.at(parent2).determine_distance() > potentialParents.at(i).determine_distance()){
            parent2 = i;
        }
    }
    std::cout << "Chosen parents are " << parent1 << " and " << parent2 << std::endl;

    tour* child = new tour(); // Create a blank child tour.
    int r = rand()%(potentialParents[parent1].cityTour.size() - 1); // Random index to choose 2 parents.
    for(int i = 0; i < r; i++)
        child->addCity(potentialParents[parent1].getCityFromTour(i)); // Copy cities from parent 1 up to index r.
    for(int i = r; i < potentialParents[parent2].cityTour.size(); i++)
        child->addCity(potentialParents[parent2].getCityFromTour(i)); // Copy cities from parent 2 up to index end.
    this->addChild(child);
}
