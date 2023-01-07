#ifndef _CITY_TOUR_HPP
#define _CITY_TOUR_HPP
#include "Graph.h"
class CityTour
{
private:
	Graph<int, int> locations;
public:
	CityTour() = default;
	CityTour(CityTour const&) = delete;
	CityTour const& operator=(CityTour const&) = delete;
	~CityTour() {}

	std::string visitedLocations(int timeToSpare) const;
};
#endif // !_CITY_TOUR_HPP


