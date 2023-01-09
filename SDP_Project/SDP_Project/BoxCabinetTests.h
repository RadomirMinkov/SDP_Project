#ifndef _BOXCABINET_TESTS
#define _BOXCABINET_TESTS
#include "doctest.h"
#include "BoxCabinet.h"

TEST_CASE("Проверка дали оптимизирането работи за целия списък от файлове")
{
	BoxCabinet cabinet;
	Box<std::string> box{ "MainBox" };
	Box<std::string> plovdivBox{ "PlovdivBox" };
	plovdivBox.addSouvenir("Magnet");
	plovdivBox.addSouvenir("Book");
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
	theatreBox->addBox(theatreSouvenirs);
	artBox->addBox(drawings);
	plovdivBox.addBox(artBox);
	plovdivBox.addBox(theatreBox);
	Box<std::string>* emptyBox = new Box<std::string>{ "EmptyBox" };
	plovdivBox.addBox(emptyBox);
	cabinet.addElement(plovdivBox);
	Box<std::string> staraZagoraBox{ "StaraZagoraBox" };
	staraZagoraBox.addSouvenir("Postcard");
	Box<std::string>* figurines = new Box<std::string>{ "Figurines" };
	figurines->addSouvenir("AncientFigurine");
	Box<std::string>* cups = new Box<std::string>{ "Cups" };
	cups->addSouvenir("TraditionalCup");
	staraZagoraBox.addBox(figurines);
	staraZagoraBox.addBox(cups);
	cabinet.addElement(staraZagoraBox);
	cabinet.optimizeBoxCabinet();
}
TEST_CASE("Проверка дали оптимизирането работи за целия списък от файлове като прочита информацията от файл")
{
	BoxCabinet cabinet;
	cabinet.readInformation();
}
#endif // !_BOXCABINET_TESTS
