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
	CHECK_EQ(stops.getPath().getEnd()->data, "NovaZagora");
	CHECK(stops.shortestPathBetweenTwoCitites("Sofia", "StaraZagora").compare("Sofia Plovdiv Dimitrovgrad StaraZagora ") == -1);
	CHECK(stops.shortestPathBetweenTwoCitites("Sofia", "StaraZagora")!= "Sofia Plovdiv Dimitrovgrad StaraZagora ");
	CHECK(stops.shortestPathBetweenTwoCitites("Sofia", "NovaZagora").compare("Sofia Plovdiv Dimitrovgrad NovaZagora ")==-1);
}
#endif // !_TRAIN_STOPS_TESTS_HPP

