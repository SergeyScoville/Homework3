#include "salesmantools.h"

// Vector2D class member function definitions
Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

// Calculate distance between two cities
double Vector2D::distance(const Vector2D &destination) const {
    double dx = x - destination.x;
    double dy = y - destination.y;
    return std::sqrt(dx * dx + dy * dy);
}

// Getter methods
double Vector2D::getX() const {return x;}
double Vector2D::getY() const {return y;}


// Add up total distance for a path
double totalDistance(const std::vector<int> &path, const std::vector<Vector2D> &cities) {
    double total = 0;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        total += cities[path[i]].distance(cities[path[i + 1]]);
    }
    total += cities[path.back()].distance(cities[path[0]]);
    return total;
}


std::vector<int> generateNewPath(const std::vector<int>& currentPath) {
    std::vector<int> newPath = currentPath;
    
    // Use a better random engine and distribution
    std::random_device rd;
    std::mt19937 e(rd());  // Seed with a random value
    std::uniform_int_distribution<int> u(0, newPath.size() - 1);

    // Generate two distinct random indices
    int i = u(e);
    int j = u(e);
    while (i == j) {
        j = u(e);  // Ensure i and j are not the same
    }

    std::swap(newPath[i], newPath[j]);  // Swap the two cities
    return newPath;
}


std::pair<double, std::vector<int>> simulatedAnnealing(const std::vector<Vector2D>& cities, double Ti, double Tf, double r) {
    int Number = cities.size();

    std::vector<int> currentPath(Number);
    std::iota(currentPath.begin(), currentPath.end(), 0);
    
    // Calculate the initial distance
    double currentDistance = totalDistance(currentPath, cities);

    double T = Ti;
    double bestDistance = currentDistance;
    std::vector<int> bestPath = currentPath;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> probDist(0.0, 1.0);

    while (T >= Tf) {

        std::vector<int> newPath = generateNewPath(currentPath);
        double newDistance = totalDistance(newPath, cities);
        double delta = newDistance - currentDistance;
        // Accept new path based on criteria
        if (delta < 0 || exp(-delta / T) > probDist(gen)) {
            currentPath = newPath;
            currentDistance = newDistance;

            if (newDistance < bestDistance) {
                bestDistance = newDistance;
                bestPath = newPath;
            }
        }
        T *= r;
    }

    // Return the current hopefully best distance found and 
    //the corresponding path
    return {currentDistance, currentPath};
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