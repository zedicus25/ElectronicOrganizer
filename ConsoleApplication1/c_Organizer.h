#pragma once
#include "c_Note.h"
struct Node
{
	c_Note* value;
	Node* next;
};
class c_Organizer
{
private:
	Node* head;
	unsigned int size;
	void show(unsigned int id);
	void remove(unsigned int id);
	void edit(unsigned int id, int day, int mounth, int year, std::string message);
	void add(int day, int mounth, int year, std::string message);
public:
	explicit c_Organizer();

	void addToList(int day, int mounth, int year, std::string message);
	void removeFromList(unsigned int id);
	void editNote(unsigned int id, int day, int mounth, int year, std::string message);
	void saveToFile();
	void loadFromFile();
	void showNote(unsigned int id);
	void showAllNotes();


	~c_Organizer()
	{
		delete head;
	}
};

