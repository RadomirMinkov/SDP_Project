#ifndef _CITY_TOUR_HPP
#define _CITY_TOUR_HPP
#include "Graph.h"
class CityTour
{
private:
	Graph<std::string, int> locations;
	bool existElemInVector(std::string, std::vector<std::string>) const;
	std::string maximumPath(std::vector<std::pair<std::string,int>>)const;
public:
	CityTour() = default;
	CityTour(CityTour const&) = delete;
	CityTour const& operator=(CityTour const&) = delete;
	~CityTour() {}
	std::string visitedLocations(std::string,int ,std::vector<std::string>&,unsigned);
};
#endif // !_CITY_TOUR_HPP


