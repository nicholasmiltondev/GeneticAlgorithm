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
    double distance;
public:
    tour();
    void addCity(city* c);
    std::string getTourName();
    void printCitiesInTour();
    double determine_fitness();
    double determine_distance();
    void mutate();
    void shuffle_cities(int x);
};


#endif //GENETICALGORITHM_TOUR_HPP
