//
// Created by nicho on 2018-11-14.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include "city.hpp"
#include <vector>

class tour {
private:
    std::vector<city> cityTour;
    int fitnessRating;
public:
    tour();
    void addCity(city c);
    int getFitnessRating();
};


#endif //GENETICALGORITHM_TOUR_HPP
