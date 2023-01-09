#include "TrainStops.h"

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
	if (curr)
		result =result + shortestPathBetweenTwoCitites(curr, pathBetweenCitites.getEnd(),"") + pathBetweenCitites.getEnd()->data;
	return result;
}

std::string TrainStops::readInformation()
{
	unsigned stops;
	std::cout << "Enter the number of the cities:";
	std::cin >> stops;
	std::string stopsList;
	std::cin.get();
	std::vector<std::string> result;
	std::getline(std::cin, stopsList);
	std::stringstream stringS{ stopsList };
	for (unsigned i = 0; i < stops; i++)
	{
		std::string currWord;
		stringS >> currWord;
		result.push_back(currWord);
	}
	for (unsigned i = 0; i < stops; i++)
	{
		pathBetweenCitites.addElementEnd(result[i]);
	}
	std::getline(std::cin, stopsList);
	while (stopsList != "")
	{
		std::stringstream stringsToSplit{ stopsList };
		std::string from;
		stringsToSplit >> from;
		std::string to;
		stringsToSplit >> to;
		pathBetweenCitites.addSkipToElement(from, to);
		std::getline(std::cin, stopsList);
	}
	std::getline(std::cin,stopsList);
	std::stringstream stringsToSplit{ stopsList };
	std::string word;
	std::vector<std::string> path;
	while (stringsToSplit >> word)
	{
		path.push_back(word);
	}
	return shortestPath(path);
}