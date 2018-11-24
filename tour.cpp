//
// Created by nicho on 2018-11-14.
//

#include "tour.hpp"
tour::tour(){

};
void tour::addCity(city* c){
    cityTour.push_back(*c);
};
city* tour::getCityFromTour(int x){
    return &cityTour[x];
};
double tour::getFitnessRating(){
    return fitnessRating;
};
void tour::setTourName(std::string s) {
    this->tourName = s;
}
void tour::printCitiesInTour(){
    std::vector<city>::iterator it = cityTour.begin();
    while(it != cityTour.end()) {
        std::cout << it->getCityName() << " " << it->getX() << " " << it->getY() << std::endl;
        ++it;
    }
};

std::string tour::getTourName() {
    return tourName;
}
double tour::determine_distance() {
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

double tour::determine_fitness(){
    fitnessRating = 1000000/distance; // Turns it into a scalar. The higher the fitter.
    return fitnessRating;
};

void tour::mutate(){
    int randCity1 = rand() % cityTour.size();
    int randCity2 = rand() % cityTour.size();
    iter_swap(cityTour.begin() + randCity1, cityTour.begin() + randCity2);
};

void tour::shuffle_cities(int x){
    for (int j = 0; j < x; j++) { // Shuffle function.
        mutate();
    }
};