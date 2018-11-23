//
// Created by nicho on 2018-11-14.
//

#ifndef GENETICALGORITHM_TOURPOPULATION_HPP
#define GENETICALGORITHM_TOURPOPULATION_HPP

#include "tour.hpp"
#include <set>

class tourPopulation {
protected:
//    std::set<tour> tp;
public:
    void addTour(tour* t);
    void printToursInPop();
};


#endif //GENETICALGORITHM_TOURPOPULATION_HPP
