#ifndef _TRAIN_STOPS_HPP
#define _TRAIN_STOPS_HPP
#include <string>
#include <vector>

#include "SkipList.h"
class TrainStops
{
private:
	SkipList<std::string> cityPath;
	void readInformation();
	TrainStops() = default;
	TrainStops(TrainStops const&) = delete;
	TrainStops const& operator=(TrainStops const&) = delete;
	~TrainStops() {}
public:
	std::string shortestPath(std::vector<std::string> toVisit) const;
};
#endif

