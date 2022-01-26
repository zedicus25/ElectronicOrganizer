#include "c_Note.h"

c_Note::c_Note()
{
	this->day = 0;
	this->mounth = 0;
	this->year = 0;
	this->message = "None";
}

c_Note::c_Note(int day, int mounth, int year, std::string message)
{
	this->setDay(day);
	this->setMounth(mounth);
	this->setYear(year);
	this->setMessage(message);
}

void c_Note::setDay(int day)
{
	try
	{
		if (day < 0 || day > 31) {
			this->day = 0;
			throw std::string("Incorrect day");
		}
		else {
			this->day = day;
		}
	}
	catch (std::string str)
	{
		std::cout << "Error " << str << "\n";
	}
}

void c_Note::setMounth(int mounth)
{
	try
	{
		if (mounth < 0 || mounth > 12) {
			this->mounth = 0;
			throw std::string("Incorrect mounth");
		}
		else {
			this->mounth = mounth;
		}
	}
	catch (std::string str)
	{
		std::cout << "Error " << str << "\n";
	}
}

void c_Note::setYear(int year)
{
	try
	{
		if (year < 1900 || year > 2022) {
			this->year = 0;
			throw std::string("Incorrect year");
		}
		else {
			this->year = year;
		}
	}
	catch (std::string str)
	{
		std::cout << "Error " << str << "\n";
	}
}

void c_Note::setMessage(std::string message)
{
	this->message = message;
}

void c_Note::editNote(int day, int mounth, int year, std::string message)
{
	this->setDay(day);
	this->setMounth(mounth);
	this->setYear(year);
	this->setMessage(message);
}

std::ostream& operator<<(std::ostream& out, const c_Note& note)
{
	out << note.getDay() << " " << note.getMounth() << " " << note.getYear() << "\n";
	out << note.getMessage() << "\n";
	return out;
}
