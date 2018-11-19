//
// Created by nicho on 2018-11-14.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP
#include <string>

class city{
protected:
    std::string cityName;
    int x;
    int y;
public:
    city(std::string name, int X, int Y);
    std::string getCityName();
    int getX();
    int getY();
};


#endif //GENETICALGORITHM_CITY_HPP
