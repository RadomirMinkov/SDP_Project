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
	CHECK_EQ(2, box->getInsideBoxes().size());

}
TEST_CASE("Проверка за споделяне на памет")
{
	Box<std::string> box{ "GameBox" };// = new Box<std::string>{ "GameBox" };
	Box<std::string>* boxOne = new Box<std::string>{ "MusicBox" };
	Box<std::string>* boxTwo = new Box<std::string>{ "SportBox" };
	Box<std::string>* boxThree = new Box<std::string>{ "ClothesBox" };
	Box<std::string>* boxFour = new Box<std::string>{ "Drawings" };
	box.addBox(boxOne);
	boxOne->addBox(boxTwo);
	box.addBox(boxFour);
	box.addBox(boxThree);
	Box<std::string>* copiedBox = new Box<std::string>{ boxOne };
	boxOne->removeBox("SportBox");
	CHECK_EQ(copiedBox->getInsideBoxes().size(), 1);
	Box<std::string> otherBox{ box };
	box.removeBox("MusicBox");
	CHECK_EQ(otherBox.getInsideBoxes().size(), 3);
}
TEST_CASE("Проверка на фунцкия оптимизиране на кутия")
{
	Box<std::string> box{ "MainBox" };
	Box<std::string>* plovdivBox= new Box<std::string>{ "PlovdivBox" };
	plovdivBox->addSouvenir("Magnet");
	plovdivBox->addSouvenir("Book");
	Box<std::string>* artBox = new Box<std::string>{ "Artbox" };
	Box<std::string>* drawings = new Box<std::string>{ "Drawings" };
	drawings->addSouvenir("OldPlovdiv");
	Box<std::string>* theatreBox = new Box<std::string>{ "TheatreBox" };
	Box<std::string>* theatreSouvenirs = new Box<std::string>{ "TheatreSouvenirs" };
	Box<std::string>* plates = new Box<std::string>{ "Plates" };
	plates->addSouvenir("DecorativePlate");
	Box<std::string>* bags = new Box<std::string>{ "Bags" };
	theatreSouvenirs->addBox(plates);
	theatreSouvenirs->addBox(bags);
	artBox->addBox(drawings);
	plovdivBox->addBox(artBox);
	plovdivBox->addBox(theatreBox);
	theatreBox->addBox(theatreSouvenirs);
	box.addBox(plovdivBox);
	Box<std::string>* staraZagoraBox = new Box<std::string>{ "StaraZagoraBox" };
	staraZagoraBox->addSouvenir("Postcard");
	Box<std::string>* figurines = new Box<std::string>{ "Figurines" };
	figurines->addSouvenir("AncientFigurine");
	Box<std::string>* cups = new Box<std::string>{ "Cups" };
	cups->addSouvenir("TraditionalCup");
	staraZagoraBox->addBox(figurines);
	staraZagoraBox->addBox(cups);
	box.addBox(staraZagoraBox);
	box.optimizeBox();
	std::string result
	{ "MainBox\n  Box list:\n  PlovdivBox\n   Souvenirs:\n   Book\n   Magnet\n    Box list:\n    Drawings\n     Souvenirs:\n     OldPlovdiv\n    Plates\n     Souvenirs:\n     DecorativePlate\n  StaraZagoraBox\n   Souvenirs:\n   Postcard\n    Box list:\n    Figurines\n     Souvenirs:\n     AncientFigurine\n    Cups\n     Souvenirs:\n     TraditionalCup" };
	//CHECK_EQ(box.printToString(0), result);
}
#endif // !_BOX_TESTS_HPP

