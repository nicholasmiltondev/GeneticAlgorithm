//
// Created by nicho on 2018-11-14.
//

#ifndef GENETICALGORITHM_TOURPOPULATION_HPP
#define GENETICALGORITHM_TOURPOPULATION_HPP

#include "tour.hpp"
#include <set>

class tourPopulation {
protected:
    std::vector<tour> population;
    std::vector<tour> potentialParents;
    double bestFitness;
public:
    void addTour(tour* t);
    tour* crossover(int size);
    void repopulate();
};


#endif //GENETICALGORITHM_TOURPOPULATION_HPP
