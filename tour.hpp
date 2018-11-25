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
    int mutation_value;
public:
    std::vector<city> cityTour;
    tour();
    void addCity(city* c);
    std::string getTourName();
    void setTourName(std::string s);
    city* getCityFromTour(int x);
    void printCitiesInTour();
    double determine_fitness();
    double determine_distance();
    double getFitnessRating();
    void mutate();
    void shuffle_cities(int x);
    bool contains_city(std::string s);
};


#endif //GENETICALGORITHM_TOUR_HPP
