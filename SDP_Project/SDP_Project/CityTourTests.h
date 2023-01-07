#ifndef _CITY_TOUR_TESTS_HPP
#define _CITY_TOUR_TESTS_HPP
#include "doctest.h"
#include "CityTour.h"
TEST_CASE("Тестване на помошните функции за максимален елемент и съществуване на елемент")
{
	std::vector<std::pair<std::string, int>> vector;
	vector.push_back(std::make_pair("Theatre", 2));
	vector.push_back(std::make_pair("Stadium", 4));
	vector.push_back(std::make_pair("University", 1));
	CHECK_EQ(maximumPath(vector), "Stadium");

	std::vector<std::string> test;
	test.push_back("Gallery");
	test.push_back("Zoopark");
	test.push_back("Lunapark");
	CHECK(existElemInVector("Gallery", test));
	CHECK(!existElemInVector("Gallerry", test));
}
TEST_CASE("Превръщанбе на вектор от стрингове в стринг")
{
	std::vector<std::string> vector;
	CHECK(convertFromVectorToString(vector)=="");
	vector.push_back("Railstation");
	vector.push_back("Museum");
	vector.push_back("Stadium");
	CHECK(convertFromVectorToString(vector) == "Railstation Museum Stadium ");

}
TEST_CASE("Проверка дали алгоритъма за намиране на най-много посетени обекти за дадено време работи")
{
	CityTour city;
	std::vector<std::string> path;
	city.getLocations().addEdge("Railstation", "ArtGallery", 26);
	city.getLocations().addEdge("Railstation", "RomanStadium", 20);
	city.getLocations().addEdge("ArtGallery", "DzhumayaSquare", 5);
	city.getLocations().addEdge("ArtGallery", "HistoricalMuseum", 14);
	city.getLocations().addEdge("ArtGallery", "AntiqueTheatre", 7);
	city.getLocations().addEdge("RomanStadium", "DzhumayaSquare", 4);
	city.getLocations().addEdge("DzhumayaSquare", "HistoricalMuseum", 18);
	city.getLocations().addEdge("HistoricalMuseum", "AntiqueTheatre", 12);
	std::string test = city.visitedLocations(68);
	CHECK(test=="Railstation ArtGallery DzhumayaSquare ArtGallery DzhumayaSquare RomanStadium Railstation ");
	CHECK(city.visitedLocations(12) == "Railstation");
	//Railstation ArtGallery AntiqueTheatre ArtGallery AntiqueTheatre ArtGallery ArtGallery DzhumayaSquare ArtGallery ArtGallery ArtGallery ArtGallery Railstation
}
#endif // !_CITY_TOUR_TESTS_HPP

