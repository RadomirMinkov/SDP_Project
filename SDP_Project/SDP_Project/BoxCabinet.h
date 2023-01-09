#ifndef _BOXCABINET_HPP
#define _BOXCABINET_HPP
#include <vector>
#include <sstream>
#include <iostream>
#include "Box.h"
class BoxCabinet
{
private:
	std::vector<Box<std::string>> cabinet;
public:
	BoxCabinet() = default;
	BoxCabinet(BoxCabinet const& other) = delete;
	BoxCabinet const& operator=(BoxCabinet const&) = delete;
	~BoxCabinet() {};

	bool addElement(Box<std::string>);
	void optimizeBoxCabinet();
	void readInformation();
	std::vector<Box<std::string>> const& getCabinet() const { return cabinet; }
	std::vector<Box<std::string>>& getCabinet() { return cabinet; }
	void print();
};

bool existInList(std::string element, std::list<Box<std::string>*> vector);
Box<std::string>* getElementInList(std::string element, std::list<Box<std::string>*> vector);
#endif

