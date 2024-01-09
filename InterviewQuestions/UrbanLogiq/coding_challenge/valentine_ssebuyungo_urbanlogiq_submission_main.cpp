/**
 * @file valentine_ssebuyungo_urbanlogiq_submission_main.cpp
 * @author Valentine Ssebuyungo
 * @brief 
 * Find optimal route for US presidential campaign
 * - optimise for distance
 * - Round trip
 * 
 * Edge cases
 *  Empty cities list
 *  Cities with same name but different location
 *  Duplicate cities
 *  Single City in List
 *  Very far cities
 *  Invalid coordinates
 * 
 * @version 0.1
 * @date 2023-12-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <set>
#include <algorithm>

using namespace std;

/**
 * @brief Struct to contain the data for a city. Supports the ==, <, > operators
 * 
 */
struct City {
    string name;
    string state;
    double latitude;
    double longitude;

    // Overload the == operator
    bool operator==(const City& other) const {
        return name == other.name && state == other.state && latitude == other.latitude && longitude == other.longitude;
    }

    //this will help with sorting
    bool operator<(const City& other) const {
        return name < other.name;
    }

    //this will help with sorting
    bool operator>(const City& other) const {
        return name > other.name;
    }
};

/**
 * @brief Remove duplicates from a vector of cities
 * 
 * @param cities 
 */
void removeDuplicates(std::vector<City>& cities) {
    // Sort cities based on the '<' operator, which compares names
    std::sort(cities.begin(), cities.end());

    // std::unique will move duplicates to the end and return a new end iterator
    auto newEnd = std::unique(cities.begin(), cities.end());

    // Erase the duplicates
    cities.erase(newEnd, cities.end());
}

/**
 * @brief This function parses a csv file in the format shown below into a vector containing structs of the Cities
 * 
 * City,State,Latitude,Longitude
 * San Francisco,California,37.7749295,-122.4194155
 * Aliso Viejo,California,33.5676842,-117.7256083
 * Rapid City,South Dakota,44.0805434,-103.2310149
 * Coon Rapids,Minnesota,45.1732394,-93.3030063
 * 
 * @param filename 
 * @return vector<City> 
 */
vector<City> parseCSV(const string& filename) {
    vector<City> cities;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return cities;
    }

    string line;
    // Skip the header line
    getline(file, line);

    while (getline(file, line)) {
        istringstream iss(line);
        string token;
        vector<string> tokens;

        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() == 4) {
            City city;
            city.name = tokens.at(0);
            city.state = tokens.at(1);
            city.latitude = stod(tokens.at(2));
            city.longitude = stod(tokens.at(3));
            cities.push_back(city);
        }
    }

    file.close();
    return cities;
}

/**
 * @brief Converts degrees to Radians
 * 
 * @param degree 
 * @return double 
 */
double toRadians(double degree) {
    return degree * (M_PI / 180.0);
}

/**
 * @brief Calculates the distance in Kilometres between 2 cities. Uses 
 *          the Haversine formula:	a = sin²(Δφ/2) + cos φ1 ⋅ cos φ2 ⋅ sin²(Δλ/2)
 *          c = 2 ⋅ atan2( √a, √(1−a) ) 
 *          d = R ⋅ c  
 * 
 * @param city1 
 * @param city2 
 * @return double 
 */
double calculateDistance(const City& city1, const City& city2) {
    // Radius of the Earth in kilometers
    const double earthRadiusKm = 6371.0;

    // Convert latitude and longitude from degrees to radians
    double lat1Rad = toRadians(city1.latitude);
    double lon1Rad = toRadians(city1.longitude);
    double lat2Rad = toRadians(city2.latitude);
    double lon2Rad = toRadians(city2.longitude);

    // Calculate the differences between the latitudes and longitudes
    double dLat = lat2Rad - lat1Rad;
    double dLon = lon2Rad - lon1Rad;

    // Implement the Haversine formula
    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1Rad) * cos(lat2Rad) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return earthRadiusKm * c;
}


/**
 * @brief This functions finds the optimal route using the nearest neighbor algorithm
 * @note Time Complexity O(n^2),  Space Complexity O(n)
 * 
 * @param cities Vector of cities to visit
 * @param startingCity 
 * @return vector<City> 
 */
vector<City> optimizedRouteFinder(const vector<City>& cities, City startingCity){
    vector<City> optimizedRoute; //solution vector
    vector<bool> visitedCities(cities.size(), false); //boolean vector to track visited cities

    //Check for empty cities list
    if (cities.empty()) {
        cerr << "Empty City list" << endl;
        return {};
    }
    
    // Find the index of the starting city
    int currentCityIndex = -1;
    for (int i = 0; i < cities.size(); ++i) {
        if (cities.at(i) == startingCity) {
            currentCityIndex = i;
            break;
        }
    }

    //Ensure starting city is found
    if (currentCityIndex == -1) {
        cerr << "Starting city not found in the list." << endl;
        return optimizedRoute;
    }

    optimizedRoute.push_back(startingCity);
    visitedCities.at(currentCityIndex) = true;

    while(optimizedRoute.size() < cities.size()){
        //find Next nearest city
        double nearestDistance = numeric_limits<double>::max(); //set distance to max
        int nearestCityIndex = -1;
        
        for(int i = 0; i < cities.size(); i++){
            if(visitedCities.at(i) == false){ //only consider unvisited cities
                double distance = calculateDistance(optimizedRoute.back(), cities.at(i));
                if (distance < nearestDistance) {
                    nearestDistance = distance;
                    nearestCityIndex = i;
                }
            }
        }

        //we have found our nearest city here
        if(nearestCityIndex != -1){
            optimizedRoute.push_back(cities.at(nearestCityIndex));
            visitedCities.at(nearestCityIndex) = true;
        }
    }

    //only return to start city if we have more than 1 city
    if(optimizedRoute.size() > 1){
        optimizedRoute.push_back(startingCity); 
    }

    return optimizedRoute;
}

int main() {
    string startingCityName = "San Francisco";
    string csvFileName = "cities_all.csv";
    vector<City> cities = parseCSV(csvFileName);

    City startingCity;
    for(int i = 0; i < cities.size(); i++){
        if(cities.at(i).name == startingCityName) {
            startingCity = cities.at(i);
        }
    }

    //Remove duplicate cities
    removeDuplicates(cities);

    vector<City> optimizedRoute = optimizedRouteFinder(cities, startingCity); //Find optimized route

    double totalDistance = 0;
    for (size_t i = 0; i < optimizedRoute.size() - 1; ++i) {
        totalDistance += calculateDistance(optimizedRoute.at(i), optimizedRoute.at(i+1));
    }

    // Output the route and total distance
    for (const City currentCity : optimizedRoute) {
        std::cout << currentCity.name << endl;
    }
    std::cout << fixed << setprecision(5);
    std::cout << totalDistance << endl;

    return 0;
}
