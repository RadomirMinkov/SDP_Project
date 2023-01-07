#ifndef _BOX_TESTS_HPP
#define _BOX_TESTS_HPP
#include "doctest.h"
#include "Box.h"

TEST_CASE("Тестване на конструктори")
{
	Box<std::string> box{ "GameBox" };
	CHECK_EQ("GameBox", box.getName());
	Box<std::string> otherBox(box);
	CHECK_EQ("GameBox", otherBox.getName());
	Box<std::string> defaultBox;
	CHECK_EQ("", defaultBox.getName());
}
TEST_CASE("Тестване на добавяне и премахване на сувенири")
{
	Box<std::string> box{ "GameBox" };
	box.addSouvenir("God of war");
	CHECK(!box.addSouvenir("God of war"));
	box.addSouvenir("Puzzle");
	box.addSouvenir("Bracelet");
	unsigned i{ 0 };
	for (std::string souvenir : box.getSouvenirs())
	{
		CHECK((souvenir == "God of war" || souvenir == "Puzzle" || souvenir == "Bracelet"));
		i++;
	}
	CHECK_EQ(i, 3);
	CHECK(box.removeSouvenir("God of war"));
	CHECK(!box.removeSouvenir("God of war"));
	CHECK(box.removeSouvenir("Bracelet"));
	CHECK(box.removeSouvenir("Puzzle"));

	CHECK_EQ(box.getSouvenirs().size(), 0);
}
#endif // !_BOX_TESTS_HPP

