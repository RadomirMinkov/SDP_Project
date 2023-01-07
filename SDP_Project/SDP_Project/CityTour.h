#ifndef _CITY_TOUR_HPP
#define _CITY_TOUR_HPP
#include "Graph.h"
class CityTour
{
private:
	Graph<std::string, int> locations;
public:
	CityTour() = default;
	CityTour(CityTour const&) = delete;
	CityTour const& operator=(CityTour const&) = delete;
	~CityTour() {}
	std::string visitedLocationsHelper(std::string, int, std::vector<std::string>, unsigned);
	std::string visitedLocations(int);
	Graph<std::string, int> const& getLocations() const { return locations; }
	Graph<std::string, int>& getLocations() { return locations; }
};
std::string convertFromVectorToString(std::vector<std::string>);
bool existElemInVector(std::string, std::vector<std::string>);
std::string maximumPath(std::vector<std::pair<std::string, int>>);
#endif // !_CITY_TOUR_HPP


