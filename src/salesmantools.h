#ifndef SALESMANTOOLS_H
#define SALESMANTOOLS_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <random>


class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x = 0, double y = 0);

    double distance(const Vector2D &destination) const;

    double getX() const;
    double getY() const;
};

double totalDistance(const std::vector<int> &path, const std::vector<Vector2D> &cities);

std::vector<int> generateNewPath(const std::vector<int> &currentPath);

std::pair<double, std::vector<int>> simulatedAnnealing(const std::vector<Vector2D>& cities, double Ti, double Tf, double r);

std::vector<Vector2D> readCitiesFromFile(const std::string& fileName);

#endif // SALESMANTOOL_H