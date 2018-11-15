//
// Created by nicho on 2018-11-14.
//

#include "city.hpp"

city::city(std::string name, int X, int Y){
    x = X;
    y = Y;
    cityName = name;
};
std::string city::getCityName(){
    return cityName;
};
int city::getX(){
    return x;
};
int city::getY(){
    return y;
};