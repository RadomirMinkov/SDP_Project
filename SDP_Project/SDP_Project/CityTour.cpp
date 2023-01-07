#include "CityTour.h"
bool CityTour::existElemInVector(std::string elem, std::vector<std::string> vector) const
{
	for (std::string currElem : vector)
	{
		if (elem == currElem)
			return true;
	}
	return false;
}

std::string CityTour::maximumPath(std::vector<std::pair<std::string, int>> paths)const
{
	std::pair<std::string,int> currMaximum = paths[0];
	for (std::pair<std::string,int> path : paths)
	{
		if (path.second > currMaximum.second)
			currMaximum = path;
	}
	return currMaximum.first;
}
std::string CityTour::visitedLocations(std::string currentLocation,int timeToSpare,std::vector<std::string>& path,unsigned uniqueLocations) 
{
	if (timeToSpare <= 0 && currentLocation != "Railstation")
		return "";
	std::vector<std::pair<std::string,int>> allPaths;
	for (std::string neighbour : locations.getNeighbours(currentLocation))
	{
		std::pair<std::string,std::string> currentEdge{ currentLocation,neighbour };
		path.push_back(currentLocation);
		if (!existElemInVector(currentLocation, path))
			uniqueLocations++;
		std::string currPath = visitedLocations(neighbour, timeToSpare - locations.getWeight(currentEdge), path, uniqueLocations);
		if (!currPath.empty())
		{
			std::pair<std::string,int> currPair{ currPath,uniqueLocations };
			allPaths.push_back(currPair);
		}
	}
	return "";
	
}