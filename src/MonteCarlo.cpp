/*
This is a module that computes the volume of a sphere with radius r=1. This module 
places either 1,000 points or 100,000 points within the cube space. It asks the 
user how many times they would like to run the simulation then saves them to an 
output. 
*/

#include <iostream>
#include <vector>
#include <fstream>
#include "carlotools.h"

int main() {
    int M;
    std::cout << "Enter the number of times you want to evaluate the volume: ";
    std::cin >> M;
    double radius = 1.0;

    // Number of points to place
    std::vector<int> runValues = {1000, 100000};
    for (const auto& N : runValues) {
        std::cout << "Running Monte Carlo simulation for N=" << N << "...\n";
        std::vector<double> volumes = runSimulation(N, M, radius);

        // Calculate the mean of the data, then std dev.
        double mean = calculateMean(volumes);
        double stdDev = calculateStdDev(volumes, mean);

        std::cout << "Estimated volume mean: " << mean << "\n";
        std::cout << "Estimated standard deviation: " << stdDev << "\n";

        std::string fileName;
        std::cout << "Enter in the name of the file you want to save the results under: ";
        std::cin >> fileName;
        saveToCSV(volumes, fileName);
    }
    return 0;
}