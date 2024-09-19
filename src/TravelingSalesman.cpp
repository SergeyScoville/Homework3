#include "salesmantools.h"
#include <fstream>

int main() {
    std::string fileName = "../data/case2.in";
    std::vector<Vector2D> cities = readCitiesFromFile(fileName);

    double Tf = 1.0, r = .99999;

    // Open a file to save the results
    std::ofstream outputFile("../data/results.csv");
    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file to save results." << std::endl;
        return 1;
    }

    // Write the header for the CSV file
    outputFile << "Ti,Result\n";

    // Loop over the temperature range
    for (double Ti = 10; Ti <= 200; Ti += 1) {
        double result = simulatedAnnealing(cities, Ti, Tf, r);
        outputFile << Ti << "," << result << "\n";  // Save Ti and result
    }

    outputFile.close();  // Close the file after writing
    return 0;
}

