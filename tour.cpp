//
// Created by nicho on 2018-11-14.
//

#include "tour.hpp"
tour::tour(){ // Consturctor for new tour.
    mutation_value = rand() % 100;
};
void tour::addCity(city* c){ // Method adds new citys to the tour.
    cityTour.push_back(*c);
};
city* tour::getCityFromTour(int x){ // Getter for city in tour.
    return &cityTour[x];
};
double tour::getFitnessRating(){ // Getter for tour fitness rating.
    return fitnessRating;
};
int tour::getMutateValue() { // Getter for mutate value.
    return mutation_value;
}
void tour::setTourName(std::string s) { // Setter for tour name.
    tourName = s;
}
void tour::printCitiesInTour(){ // Method allows user to check cities in tour.
    auto it = cityTour.begin();
    while(it != cityTour.end()) {
        std::cout << it->getCityName() << " at xCoord: " << it->getX() << ", at yCoord: " << it->getY() << std::endl;
        ++it;
    }
};
bool tour::contains_city(std::string s){ // Method returns true if tour contains city.
    auto it = cityTour.begin();
    while(it != cityTour.end()) {
        if(it->getCityName() == s)
            return true;
        ++it;
    }
    return false;
};

std::string tour::getTourName() { // Getter for tour name.
    return tourName;
}
double tour::determine_distance() { // Method calculates distance between cities on the route.
    auto it = cityTour.begin();
    int previousX = (cityTour.end() - 1)->getX();
    int previousY = (cityTour.end() - 1)->getY();
    distance = 0;
    while (it != cityTour.end()) { // Calculates a distance.
        distance += sqrt(pow((it->getX() - previousX), 2) + pow((it->getY() - previousY), 2));
        previousX = it->getX();
        previousY = it->getY();
        ++it;
    }
    return distance;
}

double tour::determine_fitness(){ // Method returns arbitrary value to gage fitness.
    fitnessRating = 1000000/distance; // Turns it into a scalar. The higher the fitter.
    return fitnessRating;
};

void tour::mutate(){ // Methods swaps cities in tour randomly.
    int randCity1 = rand() % cityTour.size();
    int randCity2 = rand() % cityTour.size();
    iter_swap(cityTour.begin() + randCity1, cityTour.begin() + randCity2);
};

void tour::shuffle_cities(int x){ // Method randomizes a tour completely.
    for (int j = 0; j < x; j++) { // Shuffle function.
        mutate();
    }
};