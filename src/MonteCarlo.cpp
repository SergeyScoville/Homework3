#include <iostream>
#include <vector>
#include <fstream>
#include "carlotools.h"

int main() {
    int M;
    std::cout << "Enter the number of times you want to evaluate the volume: ";
    std::cin >> M;
    double radius = 1.0;

    std::vector<int> runValues = {1000, 100000};
    for (const auto& N : runValues) {
        std::cout << "Running Monte Carlo simulation for N=" << N << "...\n";
        std::vector<double> volumes = runSimulation(N, M, radius);

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