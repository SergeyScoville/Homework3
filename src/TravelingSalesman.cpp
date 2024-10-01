/*
This is a module that attempts to solve the traveling salesman problem utilizing simulated annealing.
This is a method to find the shortest path between a set of cities by randomly swapping two 
cities and checking path length against some criteria. This over time seeks to 
find an optimal path as a temperature value decreases to a minimum.
*/

#include "salesmantools.h"
#include <fstream>

int main() {
    std::string fileName = "../data/case2.in";
    std::vector<Vector2D> cities = readCitiesFromFile(fileName);

    double Tf = 0.01, r = 0.999995, Ti = 2.0;

    /*
    // Loop over the temperature range for a set of r values
    std::vector<double> rValues = {0.999, 0.9991, 0.9992, 0.9993, 0.9994, 0.9995, 
    0.9996, 0.9997, 0.9998, 0.9999, 0.99991, 0.99992, 0.99993, 0.99994, 0.99995, 
    0.99996, 0.99997, 0.99998, 0.99999, 0.999991, 0.999992, 0.999993, 0.999994, 
    0.999995, 0.999996, 0.999997, 0.999998, 0.999999};
    for (double Ti = 10; Ti <= 1510; Ti += 100) {
        std::string outFile = "../data/results_T" + std::to_string(Ti) + "_rValues.csv";
        std::ofstream outputFile(outFile);
        if (!outputFile.is_open()) {
            std::cerr << "Error opening the file to save results." << std::endl;
            return 1;
        }
        for (double value: rValues) {
            // Write the header for the CSV file
            outputFile << "R,Result\n";
            double result = simulatedAnnealing(cities, Ti, Tf, value);
            outputFile << value << "," << result << "\n"; // Save R and total distance
        }
        outputFile.close();
    */
    /*
    // Loop over the temperature range
    std::ofstream outputFile("../data/results_10_5000_by10_R99999.csv");
    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file to save results." << std::endl;
        return 1;
    }
    for (double Ti = 10; Ti <= 5000; Ti += 10) {
        double result = simulatedAnnealing(cities, Ti, Tf, r);
        outputFile << Ti << "," << result << "\n";  // Save Ti and result
        std::cout << "Finished one: " << Ti << std::endl;
    }
    */
    std::cout << "Starting loops" << std::endl;
    std::pair<double, std::vector<int>> result = simulatedAnnealing(cities, Ti, Tf, r);
    
    // Extract the best distance and best path from the result
    double bestDistance = result.first;
    std::vector<int> bestPath = result.second;

    std::cout << bestDistance << std::endl;

    std::ofstream csvFile("../data/best_path.csv");
    
    csvFile << "x,y\n";  // CSV header
    for (int cityIndex : bestPath) {
        csvFile << cities[cityIndex].getX() << "," << cities[cityIndex].getY() << "\n";
    }
    csvFile << cities[bestPath[0]].getX() << "," << cities[bestPath[0]].getY() << "\n";
    
    csvFile.close();
    return 0;
}

