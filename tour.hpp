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
    double fitnessRating;
    double distance;
public:
    std::vector<city> cityTour;
    tour();
    void addCity(city* c);
    std::string getTourName();
    void printCitiesInTour();
    double determine_fitness();
    double determine_distance();
    double getFitnessRating();
    void mutate();
    void shuffle_cities(int x);
};


#endif //GENETICALGORITHM_TOUR_HPP
