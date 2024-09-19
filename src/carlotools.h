#ifndef CARLOTOOLS_H
#define CARLOTOOLS_H

#include <iostream>
#include <random>
#include <cmath>
#include <numeric>
#include <fstream>

double monteCarloVolume(int number, double radius);
std::vector<double> runSimulation(int number, int runs, double radius);
double calculateMean(const std::vector<double> &volumes);
double calculateStdDev(const std::vector<double> &volumes, double mean);
void saveToCSV(const std::vector<double> &volumes, const std::string &fileName);

#endif // CARLOTOOLS_H
