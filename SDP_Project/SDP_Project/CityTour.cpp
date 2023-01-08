#include "CityTour.h"

bool existElemInVector(std::string elem, std::vector<std::string> vector) 
{
	for (std::string currElem : vector)
	{
		if (elem == currElem)
			return true;
	}
	return false;
}

std::string maximumPath(std::vector<std::pair<std::string, int>> paths)
{
	if (paths.size() == 0)
		return "";
	std::pair<std::string,int> currMaximum = paths[0];
	for (std::pair<std::string,int> path : paths)
	{
		if (path.second > currMaximum.second)
			currMaximum = path;
	}
	return currMaximum.first;
}
std::string convertFromVectorToString(std::vector<std::string> vector)
{
	std::string result;
	for (unsigned i = 0; i < vector.size(); i++)
	{
		result = result + vector[i] + " ";
	}
	return result;
}
std::string CityTour::visitedLocations(int timeToSpare)
{
	for (std::string neigbour : locations.getNeighbours("Railstation"))
	{
		std::pair<std::string, std::string> temp{ "Railstation", neigbour };
		if (timeToSpare - locations.getWeight(temp) <= 0)
			return "Railstation";
	}
	std::vector<std::string> path;
	std::vector<std::pair<std::string, int>> allPaths;
	visitedLocationsHelper("Railstation", timeToSpare, path, 0,allPaths);
	return maximumPath(allPaths);
}
void CityTour::visitedLocationsHelper(std::string currentLocation,int timeToSpare,std::vector<std::string> path,unsigned uniqueLocations, std::vector<std::pair<std::string, int>>& allPaths)
{
	//if wanted can be added shortest path
	if (timeToSpare == 0 && currentLocation == "Railstation")
	{
		path.push_back(currentLocation);
		std::pair<std::string, int> temp{ convertFromVectorToString(path),uniqueLocations };
		allPaths.push_back(temp);
		return;
	}
	if (timeToSpare <= 0)
		return;
	if (!existElemInVector(currentLocation, path))
		uniqueLocations++;
	path.push_back(currentLocation);
	if (currentLocation == "Railstation")
	{
		std::pair<std::string, int> temp{ convertFromVectorToString(path),uniqueLocations };
		allPaths.push_back(temp);
	}
	for (std::string neighbour : locations.getNeighbours(currentLocation))
	{
		if (timeToSpare == 68)
			unsigned l{ 0 };
		std::pair<std::string,std::string> currentEdge{ currentLocation,neighbour };
	    visitedLocationsHelper(neighbour, timeToSpare - locations.getWeight(currentEdge), path, uniqueLocations,allPaths);
	}
	return;
	
}

std::string CityTour::readInformation() 
{
	std::cout << "Enter the city for which you want to see the path:";
	std::string input;
	std::cin >> input;
	input += ".txt";
	std::ifstream file;
	file.open( input, std::ios::in);
	if (!file.is_open())
	{
		return "You entered an nonexisting file";
	}
	std::string inputFile;
	std::getline(file, inputFile);
	std::stringstream str{ inputFile };
	unsigned vertices;
	str >> vertices;
	unsigned edges;
	str >> edges;

	for (unsigned i = 0; i < edges; i++)
	{
		std::getline(file, inputFile);
		std::stringstream edgeStream{ inputFile };
		std::string from;
		edgeStream >> from;
		std::string to;
		edgeStream >> to;
		int weight;
		edgeStream >> weight;
		locations.addEdge(from, to,weight);
	}
	int timeToSpare;
	file >> timeToSpare;
	return visitedLocations(timeToSpare);
}