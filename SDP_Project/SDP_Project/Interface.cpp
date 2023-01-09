#include "Interface.h"

void Interface::startProgram()
{
	unsigned commandNumber{ 0 };
	std::cout << "Enter one of the following commands:\n";
	Interface::commandPrint();
	std::cout << "Number of the command:";
	std::cin >> commandNumber;
	while (commandNumber != 5)
	{
		if (commandNumber == 1)
		{
			TrainStops stops;
			std::cout << stops.readInformation()<<'\n';

		}
		else if (commandNumber == 2)
		{
			CityTour locations;
			std::cout << locations.readInformation()<<'\n';
		}
		else if (commandNumber == 3)
		{
			BoxCabinet cabinet;
			cabinet.readInformation();
			cabinet.print();
		}
		else if (commandNumber == 4)
		{
			Interface::commandPrint();
		}
		else
			std::cout << "There is no such command!";
		std::cout << "Number of the command:";
		std::cin >> commandNumber;
	}
	std::cout << "Thank you and have a great day!\n";
}

void Interface::commandPrint()
{
	std::cout << "Enter 1 for the task with the train stops to load!\n";
	std::cout << "Enter 2 for the task with the path to landmarks to load!\n";
	std::cout << "Enter 3 for the task with the optimizing the boxes to load!\n";
	std::cout << "Enter 4 to see the available commands!\n";
	std::cout << "Enter 5 to exit!\n";
}