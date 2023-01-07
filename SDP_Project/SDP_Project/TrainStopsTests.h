#ifndef _TRAIN_STOPS_TESTS_HPP
#define _TRAIN_STOPS_TESTS_HPP

#include "doctest.h"
#include "TrainStops.h"

TEST_CASE("Проверка за най-кратък път между два града")
{
	TrainStops stops;
	stops.getPath().addElementEnd("Sofia");
	stops.getPath().addElementEnd("Pazardzhik");
	stops.getPath().addElementEnd("Plovdiv");
	stops.getPath().addElementEnd("Dimitrovgrad");
	stops.getPath().addElementEnd("StaraZagora");
	stops.getPath().addElementEnd("NovaZagora");
	stops.getPath().addSkipToElement("Sofia", "Plovdiv");
	stops.getPath().addSkipToElement("Plovdiv", "NovaZagora");
	Element<std::string>* curr= stops.getPath().getStart();
	while (curr->data != "StaraZagora")
		curr = curr->next;
	CHECK_EQ(stops.getPath().getEnd()->data, "NovaZagora");
	std::string path = stops.shortestPathBetweenTwoCitites(stops.getPath().getStart(), curr, "");
	CHECK(stops.shortestPathBetweenTwoCitites(stops.getPath().getStart(), curr,"") == "Sofia Plovdiv Dimitrovgrad ");
	CHECK(stops.shortestPathBetweenTwoCitites(stops.getPath().getStart(), curr->next,"")== "Sofia Plovdiv ");
}
TEST_CASE("Проверка дали алгоритъма за намиране на най-кратък път работи правилно")
{
	TrainStops stops;
	stops.getPath().addElementEnd("Sofia");
	stops.getPath().addElementEnd("Pazardzhik");
	stops.getPath().addElementEnd("Plovdiv");
	stops.getPath().addElementEnd("Dimitrovgrad");
	stops.getPath().addElementEnd("StaraZagora");
	stops.getPath().addElementEnd("NovaZagora");
	stops.getPath().addElementEnd("Yambol");
	stops.getPath().addElementEnd("Karnobat");
	stops.getPath().addElementEnd("Burgas");
	stops.getPath().addSkipToElement("Sofia", "Plovdiv");
	stops.getPath().addSkipToElement("Plovdiv", "NovaZagora");
	stops.getPath().addSkipToElement("Dimitrovgrad", "NovaZagora");
	stops.getPath().addSkipToElement("StaraZagora", "Yambol");
	stops.getPath().addSkipToElement("NovaZagora", "Burgas");
	std::vector<std::string> path;
	path.push_back("Plovdiv");
	path.push_back("StaraZagora");
	path.push_back("Yambol");
	CHECK(stops.shortestPath(path) == "Sofia Plovdiv Dimitrovgrad StaraZagora Yambol Karnobat Burgas ");
}
#endif // !_TRAIN_STOPS_TESTS_HPP

