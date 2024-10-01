#include "carlotools.h"

// This is a function to calculate the volume based on points placed
double monteCarloVolume(int N, double radius) {
    std::random_device random;
    std::mt19937 gen(random());
    std::uniform_real_distribution<> dis(-radius, radius);

    int number_inside_sphere = 0;

    // Generate N random points and check to see if they are inside the sphere, 
    // increment if they are
    for (int point = 0; point < N; point++) {
        double x = dis(gen);
        double y = dis(gen);
        double z = dis(gen);
        if (x*x + y*y + z*z <= radius*radius) {
            ++ number_inside_sphere;
        }
    }
    double volume_cube = std::pow(2 * radius, 3);
    return (static_cast<double>(number_inside_sphere) / N) * volume_cube;
}

// This function runs an input number of simulations and stores the results (runs = M)
std::vector<double> runSimulation(int N, int runs, double radius) {
    std::vector<double> volumes(runs);
    for (int run = 0; run < runs; ++run) {
        volumes[run] = monteCarloVolume(N, radius);
    }
    return volumes;
}

// This function calulates the mean of a vector of values
double calculateMean(const std::vector<double> &volumes) {
    double sum = std::accumulate(volumes.begin(), volumes.end(), 0.0);
    return sum / volumes.size();
}

// This function calculates the standard deviation of a vector of values
double calculateStdDev(const std::vector<double> &volumes, double mean) {
    double sigma = 0.0;
    for (const auto &vol : volumes) {
        sigma += (vol - mean) * (vol - mean);
    }
    return std::sqrt(sigma / volumes.size());
}

// Function to save the results to a CSV file for plotting with gnuPlot or other 
void saveToCSV(const std::vector<double> &volumes, const std::string &fileName) {
    std::ofstream file(fileName);
    if (file.is_open()) {
        for (const auto &vol : volumes) {
            file << vol << "\n";
        }
        file.close();
        std::cout << "Results saved to " << fileName << "\n";
    } else {
        std::cerr << "Error opening file for writing.\n";
    }
}