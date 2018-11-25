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
#define MUTATION_RATE 15 // Out of 100


int main() {
    static long randomCityName = 0; // Used to create unique city names.
    static long randomTourName = 0; // Used to create unique route names.

    tourPopulation* tp = new tourPopulation(); // Create a new population.

    for(int j = 0; j < POPULATION_SIZE; j++) { // Fill the population with tours.

        tour *t = new tour(); // Create a new tour.

        for (int i = 0; i < CITIES_IN_TOUR; i++) { // Fill the tour with cities.
            int newX = rand() % MAP_BOUNDARY;
            int newY = rand() % MAP_BOUNDARY;
            ++randomCityName;
            std::string newCityName("City#" + std::to_string(randomCityName));
            city *newCity = new city(newCityName, newX, newY); // Construct city with name and random coordinates.
            t->addCity(newCity); // Add new city to the tour.
        }

        t->shuffle_cities(SHUFFLES); // Randomize cities.
        std::cout << t->determine_distance() << std::endl; // Initialize tour distance.
        std::cout << t->determine_fitness() << std::endl; // Initialize tour fitness.
        ++randomTourName;
        std::string newTourName("Tour#" + std::to_string(randomTourName));
        t->setTourName(newTourName);
        tp->addTour(t); // Add tour to population.
    }

    for(int m = 0; m < ITERATIONS; m++) { // Number of iterations the genetic algorithm will go for.
        tp->select_parents(PARENT_POOL_SIZE); // Create a pool to choose parents from.
        tp->findCopyElite(); // Add the elite route to the next generation at index 0.
        std::cout << "Elite tour name is " << tp->nextGeneration[0].getTourName() << ", distance is "
            << tp->nextGeneration[0].determine_distance()
            << ", fitness is " << tp->nextGeneration[0].determine_fitness() << " Containing cities : " << std::endl;
        tp->nextGeneration[0].printCitiesInTour();

        for (int k = 1; k < tp->population.size(); k++) { // For the rest of the next generation, breed new tours.
            tp->crossover(); // Breed parents and and the child to the next generation.
            ++randomTourName;
            std::string newChildTourName("Tour#" + std::to_string(randomTourName));
            if(tp->nextGeneration[k].getMutateValue() < MUTATION_RATE) // Determine if the child should mutate.
                tp->nextGeneration[k].mutate(); // Mutate the tour.
            tp->nextGeneration[k].determine_distance(); // Initialize the distance.
            tp->nextGeneration[k].setTourName(newChildTourName);
            tp->nextGeneration[k].determine_fitness(); // Initialize the fitness value.
            std::cout << k << " is the position of child " << tp->getChild(k).getTourName() << ", distance is "
                      << tp->nextGeneration[k].determine_distance()
                      << ", fitness is " << tp->nextGeneration[k].determine_fitness() << std::endl;
        }
        tp->population.clear(); // Clear the vector for the old population for next iteration.
        tp->population = tp->nextGeneration; // Move in the next generation.
        tp->nextGeneration.clear(); // Clear for next iteration.
        tp->potentialParents.clear(); // Clear for next iteration.
    }
    return 0;
}