//
// Created by nicho on 2018-11-14.
//

#ifndef GENETICALGORITHM_TOURPOPULATION_HPP
#define GENETICALGORITHM_TOURPOPULATION_HPP

#include "tour.hpp"
#include <set>

class tourPopulation {
public:
    std::vector<tour> population;
    std::vector<tour> potentialParents;
    std::vector<tour> nextGeneration;
    void crossover();
    double bestFitness;
    void addTour(tour* t);
    void addChild(tour* t);
    tour getChild(int i);
    void select_parents(int size);
    void findCopyElite();
    void repopulate();
    tour getTour(int i);
};


#endif //GENETICALGORITHM_TOURPOPULATION_HPP
