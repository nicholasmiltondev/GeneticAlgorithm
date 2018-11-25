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
    double bestFitness = 0;
    static long randomCityName = 0;
    static long randomTourName = 0;

    tourPopulation* tp = new tourPopulation();
    for(int j = 0; j < POPULATION_SIZE; j++) {
        
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
        std::cout << t->determine_distance() << std::endl;
        std::cout << t->determine_fitness() << std::endl;
        ++randomTourName;
        std::string newTourName("Tour#" + std::to_string(randomTourName));
        t->setTourName(newTourName);
        tp->addTour(t);
    }

    for(int m = 0; m < ITERATIONS; m++) { // Number of iterations the genetic algorithm will go for.
        tp->select_parents(PARENT_POOL_SIZE);
        tp->findCopyElite();
        std::cout << "Elite tour name is ..." << tp->nextGeneration[0].getTourName() << ", distance is "
            << tp->nextGeneration[0].determine_distance()
            << ", fitness is " << tp->nextGeneration[0].determine_fitness() << std::endl;

        for (int k = 1; k < tp->population.size(); k++) {
            tp->crossover();
            ++randomTourName;
            std::string newChildTourName("Tour#" + std::to_string(randomTourName));
            tp->nextGeneration[k].determine_distance();
            tp->nextGeneration[k].setTourName(newChildTourName);
            tp->nextGeneration[k].determine_fitness();
            std::cout << k << " position child tour name is " << tp->getChild(k).getTourName() << ", distance is "
                      << tp->nextGeneration[k].determine_distance()
                      << ", fitness is " << tp->nextGeneration[k].determine_fitness() << std::endl;
        }
        tp->population.clear();
        tp->population = tp->nextGeneration;
        tp->nextGeneration.clear();
        tp->potentialParents.clear();
    }
    return 0;
}