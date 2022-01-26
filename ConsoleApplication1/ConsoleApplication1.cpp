#include <iostream>
#include "c_Organizer.h"
int main()
{
    c_Organizer* org = new c_Organizer();
    int userInput = -1;
	int id = 0;
	int day;
	int mounth;
	int year;
	std::string messsage;
	do
	{
		system("cls");
		std::cout << "1 - Add note" << "\n";
		std::cout << "2 - Edit note" << "\n";
		std::cout << "3 - Delete note" << "\n";
		std::cout << "4 - Show note" << "\n";
		std::cout << "5 - Show notes" << "\n";
		std::cout << "6 - Save to file" << "\n";
		std::cout << "7 - Load from file" << "\n";
		std::cout << "0 - Exit" << "\n";
		std::cin >> userInput;
		switch (userInput)
		{
		case 1: 
			system("cls");
			std::cout << "Enter date: ";
			std::cin >> day >> mounth >> year;
			std::cin.ignore();
			std::cout << "Enter message: ";
			std::getline(std::cin, messsage);
			org->addToList(day,mounth,year,messsage);
			system("cls");
			std::cout << "added\n";
			system("pause");
			break;
		case 2:
			system("cls");
			std::cout << "Enter date: ";
			std::cin >> day >> mounth >> year;
			std::cin.ignore();
			std::cout << "Enter message: ";
			std::getline(std::cin, messsage);
			std::cout << "Enter id ";
			std::cin >> id;
			org->editNote(id, day, mounth, year, messsage);
			system("cls");
			std::cout << "Edited\n";
			system("pause");
			break;
		case 3:
			system("cls");
			std::cout << "Enter id ";
			std::cin >> id;
			org->removeFromList(id);
			system("cls");
			std::cout << "Removed\n";
			system("pause");
			break;
		case 4:
			system("cls");
			std::cout << "Enter id ";
			std::cin >> id;
			org->showNote(id);
			system("pause");
			break;
		case 5:
			system("cls");
			org->showAllNotes();
			system("pause");
			break;
		case 6:
			system("cls");
			org->saveToFile();
			system("pause");
			break;
		case 7:
			system("cls");
			org->loadFromFile();
			system("pause");
			break;
		case 0:
			break;
		default:
			std::cout << "Incorrect input" << "\n";
			break;
		}
	} while (userInput != 0);
}