#include "salesmantools.h"

Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

double Vector2D::distance(const Vector2D &destination) const {
    double dx = x - destination.x;
    double dy = y - destination.y;
    return std::sqrt(dx * dx + dy * dy);
}

double Vector2D::getX() const {return x;}
double Vector2D::getY() const {return y;}

double totalDistance(const std::vector<int> &path, const std::vector<Vector2D> &cities) {
    double total = 0;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        total += cities[path[i]].distance(cities[path[i + 1]]);
    }
    total += cities[path.back()].distance(cities[path[0]]);
    return total;
}

std::vector<int> generateNewPath(const std::vector<int> &currentPath) {
    std::vector<int> newPath = currentPath;
    int i = rand() % newPath.size(); // ARRGH!
    int j = rand() % newPath.size();
    std::swap(newPath[i], newPath[j]);
    return newPath;
}

double simulatedAnnealing(const std::vector<Vector2D> &cities, double Ti, double Tf, double r) {
    int Number = cities.size();
    std::vector<int> currentPath(Number);
    std::iota(currentPath.begin(), currentPath.end(), 0);

    double currentDistance = totalDistance(currentPath, cities);
    double T = Ti;
    double bestDistance = 1000;

    while (T > Tf) {
        std::vector<int> newPath = generateNewPath(currentPath);
        double newDistance = totalDistance(newPath, cities);
        double delta = newDistance - currentDistance;

        //if ((delta < 0 || exp(-delta / T) > (0.5 + (double)std::rand() / RAND_MAX * 0.5))) {
        if (delta < 0 || exp(-delta / T) > (rand() / (RAND_MAX + 1.0))) {
            currentPath = newPath;
            currentDistance = newDistance;
            if (newDistance < bestDistance) {
                bestDistance = newDistance;
            }
        } 
        T *= r;
    }
    //std::cout << "Final distance: " << currentDistance << std::endl;
    //std::cout << "Best distance: " << bestDistance << std::endl;
    return currentDistance;
}

// Function to read city data from a file into a std::vector<Vector2D>
std::vector<Vector2D> readCitiesFromFile(const std::string& fileName) {
    std::vector<Vector2D> cities;
    std::ifstream inputFile(fileName);

    if (!inputFile) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return cities;
    }

    double x, y;
    while (inputFile >> x >> y) {
        cities.emplace_back(x, y);  // Add a Vector2D to the vector
    }

    inputFile.close();
    return cities;
}