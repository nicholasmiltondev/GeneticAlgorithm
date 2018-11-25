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
void tourPopulation::findCopyElite() { // Finds elite tour with the lowest distance in a population.
    int eliteIndex = 0;
    for (int i = 1; i < population.size(); i++) { // Iterate through population to find the elite tour.
        if (population[i].determine_distance() < population[eliteIndex].determine_distance()) {
            eliteIndex = i;
        }
    }
    this->addChild(&population[eliteIndex]); // Adds elite to the next generation.
}

void tourPopulation::select_parents(int poolSize) { // Takes PARENT_POOL_SIZE
    for (int i = 0; i < poolSize; i++) {
        int rIndex = rand() % population.size();
        std::cout << "Selecting parent at index " << rIndex << " for the parent pool." << std::endl;
        potentialParents.push_back(population[rIndex]); // Add random parents to a potential parent pool.
    }
}

void tourPopulation::crossover() { // Takes fittest parents from the pool and breeds them to create 1 child.
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
    std::cout << "Choosing to breed parents " << parent1 << " and " << parent2 << " from the pool." << std::endl;

    tour* child = new tour(); // Create a blank child tour.
    int r = rand()%(potentialParents[parent1].cityTour.size() - 1); // Random index r.
    for(int i = 0; i < r; i++)
        child->addCity(potentialParents[parent1].getCityFromTour(i)); // Copy cities from parent 1 up to index r.
    for(int i = r; i < potentialParents[parent2].cityTour.size(); i++)
        child->addCity(potentialParents[parent2].getCityFromTour(i)); // Copy cities from parent 2 up to index end.
    this->addChild(child); // Child added to next generation.
    std::cout << "Parent 1 from index 0 to " << r -1 << ", parent 2 from index " << r << " to "
    << potentialParents[parent1].cityTour.size() - 1 << std::endl;
}
