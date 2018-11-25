//
// Created by nicho on 2018-11-14.
//

#include "city.hpp"

city::city(std::string name, int X, int Y){ // Constructor for new city.
    x = X;
    y = Y;
    cityName = name;
};
std::string city::getCityName(){ // Getter for city name.
    return cityName;
};
int city::getX(){ // Getter for x coord.
    return x;
};
int city::getY(){ // Getter for y coord.
    return y;
};