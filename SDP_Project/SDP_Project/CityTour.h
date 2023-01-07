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
	void visitedLocationsHelper(std::string, int, std::vector<std::string>, unsigned, std::vector<std::pair<std::string, int>>&);
	std::string visitedLocations(int);

	Graph<std::string, int> const& getLocations() const { return locations; }
	Graph<std::string, int>& getLocations() { return locations; }
};
std::string maximumPath(std::vector<std::pair<std::string, int>>);
 std::string convertFromVectorToString(std::vector<std::string>);
bool existElemInVector(std::string, std::vector<std::string>);

#endif // !_CITY_TOUR_HPP


