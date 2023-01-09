#include "BoxCabinet.h"

bool BoxCabinet::addElement(Box<std::string> box)
{
	for (Box<std::string> boxEl : cabinet)
	{
		if (box.getName() == boxEl.getName())
		{
			return false;
		}
	}
	cabinet.push_back(box);
	return true;
}
void BoxCabinet::optimizeBoxCabinet()
{
	typename std::vector<Box<std::string>>::iterator it;
	it = cabinet.begin();
	while (it != cabinet.end())
	{
		(*it).optimizeBox();
		++it;
	}
}
bool existInList(std::string element, std::list<Box<std::string>*> vector)
{
	for (Box<std::string>* box : vector)
	{
		if (element == box->getName())
			return true;
	}
	return false;
}
Box<std::string>* getElementInList(std::string element, std::list<Box<std::string>*> vector)
{
	for (Box<std::string>* box : vector)
	{
		if (element == box->getName())
			return box;
		Box<std::string>* temp = getElementInList(element, box->getInsideBoxes());
		if (temp)
			return temp;
	}
	return nullptr;
}
void BoxCabinet::readInformation()
{
	std::ifstream file;
	file.open("boxesList.txt", std::ios::in);
	unsigned boxCount{ 0 };
	file >> boxCount;
	std::string buffer;
	std::getline(file, buffer);
	for (unsigned i = 0; i < boxCount; i++)
	{
		std::string inputString;
		Box<std::string>* currBox = new Box<std::string>();
		file >> inputString;
		typename std::vector<Box<std::string>>::iterator it;
		it = cabinet.begin();
		while (it != cabinet.end())
		{
			currBox = getElementInList(inputString, (*it).getInsideBoxes());
			if (currBox)
				break;
			++it;
		}
		if (!currBox || currBox->getName().empty())
		{
			if (inputString.empty())
				continue;
			Box<std::string>* newBox = new Box<std::string>{ inputString };
			unsigned souvenirsCount{ 0 };
			file >> souvenirsCount;
			for (unsigned i = 0; i < souvenirsCount; i++)
			{
				file >> inputString;
				newBox->addSouvenir(inputString);
			}
			unsigned insideBoxesCount{ 0 };
			file >> insideBoxesCount;
			for (unsigned i = 0; i < insideBoxesCount; i++)
			{
				file >> inputString;
				Box<std::string>* newInsideBox = new Box<std::string>{ inputString };
				newBox->addBox(newInsideBox);
			}
			cabinet.push_back(newBox);
		}
		else {
			unsigned souvenirsCount{ 0 };
			file >> souvenirsCount;
			for (unsigned i = 0; i < souvenirsCount; i++)
			{
				file >> inputString;
				currBox->addSouvenir(inputString);
			}
			unsigned insideBoxesCount{ 0 };
			file >> insideBoxesCount;
			for (unsigned i = 0; i < insideBoxesCount; i++)
			{
				file >> inputString;
				Box<std::string>* newInsideBox = new Box<std::string>{ inputString };
				currBox->addBox(newInsideBox);
			}
		}
	}
	optimizeBoxCabinet();
}
void BoxCabinet::print()
{
	unsigned i{ 0 };
	for (Box<std::string> box : cabinet)
	{
		std::cout << "Box " << i++ << '\n';
		box.print(0);
	}
}