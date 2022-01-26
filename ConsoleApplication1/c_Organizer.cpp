#include "c_Organizer.h"
#include <fstream>
void c_Organizer::show(unsigned int id)
{
	Node* tmp = this->head;
	for (int i = 0; i < id; i++)
	{
		tmp = tmp->next;
	}
	std::cout << *(tmp->value) << "\n";
	delete tmp;
}

void c_Organizer::remove(unsigned int id)
{
	Node* forDelete = NULL;
	if (id == 0) {
		forDelete = this->head;
		this->head = this->head->next;
	}
	else {
		Node* tmp = this->head;
		forDelete = tmp;
		int i = 1;
		while (tmp->next != nullptr) {
			if (i == id && tmp->next != nullptr) {
				forDelete = tmp->next;
				break;
			}
			i++;
			tmp = tmp->next;
		}
		if (tmp->next->next == NULL) {
			tmp->next = NULL;
		}
		else {
			tmp->next = tmp->next->next;
		}
	}
	delete forDelete;
	this->size--;
}

void c_Organizer::edit(unsigned int id, int day, int mounth, int year, std::string message)
{
	Node* tmp = this->head;
	for (int i = 0; i < id; i++)
	{
		if (tmp->next != nullptr) {
			tmp = tmp->next;
		}
	}
	tmp->value->editNote(day,mounth,year,message);
}

void c_Organizer::add(int day, int mounth, int year, std::string message)
{
	Node* tmp = this->head;
	if (tmp == NULL) {
		tmp = new Node;
		tmp->value = new c_Note(day, mounth, year, message);
		tmp->next = nullptr;
		this->head = tmp;
	}
	else {
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}

		tmp->next = new Node;
		tmp->next->value = new c_Note(day, mounth, year, message);
		tmp->next->next = nullptr;
	}
}

c_Organizer::c_Organizer()
{
	this->head = NULL;
	this->size = 0;
}

void c_Organizer::addToList(int day, int mounth, int year, std::string message)
{
	Node* tmp = this->head;
	if (tmp == NULL) {
		tmp = new Node;
		tmp->value = new c_Note(day, mounth, year, message);
		tmp->next = nullptr;
		this->head = tmp;
	}
	else {
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}

		tmp->next = new Node;
		tmp->next->value = new c_Note(day, mounth, year, message);
		tmp->next->next = nullptr;
	}
	this->size++;
}

void c_Organizer::removeFromList(unsigned int id)
{
	if (this->size == 0) {
		std::cout << "Empty";
		return;
	}
	try
	{
		if (id < 0 || id >= this->size) {
			throw std::string("Out of bound list");
		}
		else {
			this->remove(id);
		}
	}
	catch (std::string str)
	{
		std::cout << "Error " << str << "\n";
	}
}

void c_Organizer::editNote(unsigned int id, int day, int mounth, int year, std::string message)
{
	if (this->size == 0) {
		std::cout << "Empty";
		return;
	}
	try
	{
		if (id < 0 || id >= this->size) {
			throw std::string("Out of bound list");
		}
		else {
			this->edit(id,day,mounth,year,message);
		}
	}
	catch (std::string str)
	{
		std::cout << "Error " << str << "\n";
	}
}

void c_Organizer::saveToFile()
{
	if (this->size == 0) {
		std::cout << "Empty";
		return;
	}
	std::ofstream out;
	out.open("data.txt");
	if (out.is_open()) {
		out << this->size << "\n";
		Node* tmp = this->head;

		while (tmp != nullptr)
		{
			out << *(tmp->value) << "\n";
			tmp = tmp->next;
		}
		out.close();
		std::cout << "Done"<< "\n";
	}
	else {
		std::cout << "Error"<<"\n";
	}
}

void c_Organizer::loadFromFile()
{
	std::ifstream in("Data.txt");
	if (in.is_open()) {
		in >> this->size;
		for (int i = 0; i < this->size; i++)
		{
			int d = 0;
			int m = 0;
			int y = 0;
			std::string mes;
			in >> d >> m >> y;
			in >> mes;
			this->add(d,m,y,mes);
		}
		std::cout << "Done";
		in.close();
	}
	else {
		std::cout << "Cannot read file" << "\n";
	}
}

void c_Organizer::showNote(unsigned int id)
{
	if (this->size == 0) {
		std::cout << "Empty";
		return;
	}
	try
	{
		if (id < 0 || id >= this->size) {
			throw std::string("Out of bound list");
		}
		else {
			this->show(id);
		}
	}
	catch (std::string str)
	{
		std::cout << "Error " << str << "\n";
	}
}

void c_Organizer::showAllNotes()
{
	if (this->size == 0) {
		std::cout << "Empty";
		return;
	}
	Node* tmp = this->head;
	while (tmp != nullptr)
	{
		std::cout << *(tmp->value) << "\n";
		tmp = tmp->next;
	}
	delete tmp;
}
