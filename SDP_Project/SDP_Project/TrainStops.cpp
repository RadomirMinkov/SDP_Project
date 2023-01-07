#include "TrainStops.h"

/*std::string TrainStops::shortestPath(std::vector<std::string> path) const
{
	retur
}*/

std::string TrainStops::shortestPathBetweenTwoCitites(Element<std::string>* from,Element<std::string>* to, std::string result) const
{
	if (!from)
		return "";
	if (from == to)
		return result;

	if (!from->skipTo)
	{
		return shortestPathBetweenTwoCitites(from->next, to, result + from->data + " ");
	}
	std::string minPathNext = shortestPathBetweenTwoCitites(from->next, to, result + from->data + " ");
	std::string minPathSkip = shortestPathBetweenTwoCitites(from->skipTo, to, result + from->data + " ");
	if (minPathNext.empty() && minPathSkip.empty())
		return "";
	if (minPathNext.empty())
		return minPathSkip;
	if (minPathSkip.empty())
		return minPathNext;
	if (minPathNext.length() < minPathSkip.length())
		return minPathNext;
	return minPathSkip;
}
std::string TrainStops::shortestPath(std::vector<std::string> citiesToVisit) const
{
	std::vector<std::string> vector;
	Element<std::string>* curr = pathBetweenCitites.getStart();
	Element<std::string>* from = curr;
	for (unsigned i = 0; i < citiesToVisit.size(); i++)
	{
		while (curr->data != citiesToVisit[i])
			curr = curr->next;
		vector.push_back(shortestPathBetweenTwoCitites(from, curr, ""));
		from = curr;
	}
	std::string result;
	for (unsigned i = 0; i < vector.size(); i++)
	{
		result += vector[i];
	}
	while (curr)
	{
		result = result + curr->data + " ";
		curr = curr->next;
	}
	return result;
}