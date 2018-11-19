//
// Created by nicho on 2018-11-14.
//

#include "tour.hpp"
tour::tour(){

};
void tour::addCity(city* c){
    cityTour.push_back(*c);
};
int tour::getFitnessRating(){
    return fitnessRating;
};
void tour::printCitiesInTour(){
    std::vector<city>::iterator it = cityTour.begin();
    while(it != cityTour.end()) {
        std::cout << it->getCityName() << " " << it->getX() << " " << it->getY() << std::endl;
        ++it;
    }
};

void tour::determine_fitness() {
    std::vector<city>::iterator it = cityTour.begin();
    int previousX = 0;
    int previousY = 0;
    fitnessRating = 0;
    while(it != cityTour.end()) {
        fitnessRating += sqrt(pow((it->getX() - previousX), 2) + pow((it->getY() - previousY), 2));
        previousX = it->getX();
        previousY = it->getY();
        ++it;
    }
    std::cout << "Fitness rating is: " << fitnessRating << std::endl;
};

void tour::shuffle_cities(){
    std::random_shuffle (cityTour.begin(), cityTour.end());
};