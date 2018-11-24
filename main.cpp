#include <iostream>
#include "city.hpp"
#include "tour.hpp"
#include "tourPopulation.hpp"
#define CITIES_IN_TOUR 32
#define POPULATION_SIZE 32
#define SHUFFLES 64
#define ITERATIONS 1000
#define MAP_BOUNDARY 1000
#define PARENT_POOL_SIZE 5
#define MUTATION_RATE 0.15
#define NUMBER_OF_PARENTS 2
#define NUMBER_OF_ELITES 1

int main() {
    static long randomCityName = 0;
    static long randomTourName = 0;
    double bestFitness = 0;


    tour *t = new tour();

    for (int i = 0; i < CITIES_IN_TOUR; i++) {
        int newX = rand() % MAP_BOUNDARY;
        int newY = rand() % MAP_BOUNDARY;
        ++randomCityName;
        std::string newCityName("City#" + std::to_string(randomCityName));
        city *newCity = new city(newCityName, newX, newY);
        t->addCity(newCity);
    }

    t->shuffle_cities(SHUFFLES);

    for(int k = 0; k < ITERATIONS; k++) {
        double df = t->determine_fitness();
        t->mutate();
        if (df > bestFitness) {
            bestFitness = df;
            std::cout << bestFitness << std::endl;
        }
    }
    return 0;
}