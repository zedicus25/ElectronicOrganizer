#pragma once
#include <string>
#include <iostream>
class c_Note
{
private:
	int day;
	int mounth;
	int year;
	std::string message;
	

	inline int getDay() const {
		return this->day;
	}
	inline int getMounth() const {
		return this->mounth;
	}
	inline int getYear() const {
		return this->year;
	}
	inline std::string getMessage() const {
		return this->message;
	}
public:
	c_Note();
		
	void setDay(int day);
	void setMounth(int mounth);
	void setYear(int year);
	void setMessage(std::string message);

	void createNote(int day, int mounth, int year, std::string message);
	
	friend std::ostream& operator<<(std::ostream& out, const c_Note& note);
};

