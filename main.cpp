#include <iostream>
#include "city.hpp"
#include "tour.hpp"

int main() {
    tour* t = new tour();
    city* London = new city("London", 3, 4);
    city* Vancouver = new city("Vancouver", 0, 0);

    t->addCity(London);
    t->addCity(Vancouver);
    t->printCitiesInTour();
    t->calcFitness();

    return 0;
}