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

std::string tour::getTourName() {
    return tourName;
}

int tour::determine_fitness(){
    auto it = cityTour.begin();
    int previousX = (cityTour.end()-1)->getX();
    int previousY = (cityTour.end()-1)->getY();
    fitnessRating = 0;
    while(it != cityTour.end()) {
        fitnessRating += sqrt(pow((it->getX() - previousX), 2) + pow((it->getY() - previousY), 2));
        previousX = it->getX();
        previousY = it->getY();
        ++it;
    }
    fitnessRating = 1000000/fitnessRating;
    return fitnessRating;
};

void tour::shuffle_cities(){
    std::random_shuffle (cityTour.begin(), cityTour.end());
};