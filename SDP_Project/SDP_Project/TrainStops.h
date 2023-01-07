#ifndef _TRAIN_STOPS_HPP
#define _TRAIN_STOPS_HPP
#include <string>
#include <vector>
#include <queue>

#include "SkipList.h"
class TrainStops
{
private:
	SkipList<std::string> pathBetweenCitites;
public:
	TrainStops() = default;
	TrainStops(TrainStops const&) = delete;
	TrainStops const& operator=(TrainStops const&) = delete;
	~TrainStops() {}
	std::string shortestPath(std::vector<std::string> toVisit) const;
	std::string shortestPathBetweenTwoCitites(Element<std::string>* from, Element<std::string>* to,std::string result) const;

	SkipList<std::string>& getPath() { return pathBetweenCitites; }
	SkipList<std::string> const& getPath() const { return pathBetweenCitites; }
};
#endif

