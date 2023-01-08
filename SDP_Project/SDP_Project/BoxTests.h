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
TEST_CASE("Добавяне и премахване на кутия")
{
	Box<std::string>* box = new Box<std::string>{ "GameBox" };
	Box<std::string>* boxOne = new Box<std::string>{ "MusicBox" };
	Box<std::string>* boxTwo = new Box<std::string>{ "SportBox" };
	Box<std::string>* boxThree = new Box<std::string>{ "ClothesBox" };
	box->addBox(boxOne);
	boxOne->addBox(boxTwo);
	box->addBox(boxTwo);
	box->addBox(boxThree);
	unsigned i{ 0 };
	for (Box<std::string>* boxEl : box->getInsideBoxes())
	{
		CHECK((boxEl->getName() == "MusicBox" || boxEl->getName() == "SportBox" || boxEl->getName() == "ClothesBox"));
		i++;
	}
	CHECK_EQ(i, 3);
	box->removeBox("MusicBox");
	//box->removeBox(boxo);
	//box->getInsideBoxes().remove(boxTwo);
	CHECK_EQ(2, box->getInsideBoxes().size());
	
}
TEST_CASE("Проверка за споделяне на памет")
{
	Box<std::string> box{ "GameBox" };// = new Box<std::string>{ "GameBox" };
	Box<std::string>* boxOne = new Box<std::string>{ "MusicBox" };
	Box<std::string>* boxTwo = new Box<std::string>{ "SportBox" };
	Box<std::string>* boxThree = new Box<std::string>{ "ClothesBox" };
	box.addBox(boxOne);
	boxOne->addBox(boxTwo);
	box.addBox(boxTwo);
	box.addBox(boxThree);
	Box<std::string>* copiedBox= new Box<std::string>{ boxOne };
	boxOne->removeBox("SportBox");
	CHECK_EQ(copiedBox->getInsideBoxes().size(),1);
	Box<std::string> otherBox{ box };
	box.removeBox("MusicBox");
	CHECK_EQ(otherBox.getInsideBoxes().size(), 3);
}
#endif // !_BOX_TESTS_HPP

