#ifndef CARLOTOOLS_H
#define CARLOTOOLS_H

#include <iostream>
#include <random>
#include <cmath>
#include <numeric>
#include <fstream>

// Calculate volume based on placing points
double monteCarloVolume(int number, double radius);

// Runs the simulation M times
std::vector<double> runSimulation(int number, int runs, double radius);

// Calculate mean of the result
double calculateMean(const std::vector<double> &volumes);

// Calculate the Standard Deviation, uses mean
double calculateStdDev(const std::vector<double> &volumes, double mean);

// Saves output
void saveToCSV(const std::vector<double> &volumes, const std::string &fileName);

#endif // CARLOTOOLS_H
