//
// Created by nicho on 2018-11-14.
//

#include "tour.hpp"
tour::tour(){

};
void tour::addCity(city c){
    cityTour.push_back(c);
};
int tour::getFitnessRating(){
    return fitnessRating;
};