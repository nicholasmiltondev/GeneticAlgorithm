//
// Created by nicho on 2018-11-14.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include "city.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

class tour {
protected:
    std::string tourName;
    std::vector<city> cityTour;
    double fitnessRating;
public:
    tour();
    void addCity(city* c);
    int getFitnessRating();
    void printCitiesInTour();
    void determine_fitness();
    void shuffle_cities();
};


#endif //GENETICALGORITHM_TOUR_HPP
