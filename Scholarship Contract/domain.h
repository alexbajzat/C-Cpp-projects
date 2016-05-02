#pragma once
#include <string>

class Discipline{
public:
	int getHours() const {
		return hours;
	}

	void setHours(int hours) {
		this->hours = hours;
	}

	int getId() const {
		return id;
	}

	void setId(int id) {
		this->id = id;
	}

	const std::string& getName() const {
		return name;
	}

	void setName(const std::string& name) {
		this->name = name;
	}

	const std::string& getProf() const {
		return prof;
	}

	void setProf(const std::string& prof) {
		this->prof = prof;
	}

	int getType() const {
		return type;
	}

	void setType(int type) {
		this->type = type;
	}

	/*
	* Constructor with no params
	*/
	Discipline() {
		id = -1;
		type = -1;
		hours = -1;
		name = "";
		prof = "";

	}

	/*
	* Constructor with 5 params
	*/
	Discipline(int id, int type, int hours, std::string name,
		std::string prof) {
		this->id = id;
		this->hours = hours;
		this->name = name;
		this->prof = prof;
		this->type = type;
	}

	/*
	* Copy constructor for disc - Discipline parameter
	* This constructor copies the values from disc in the object
	*/
	Discipline(const Discipline& disc) {
		id = disc.getId();
		hours = disc.getHours();
		type = disc.getType();
		name = disc.getName();
		prof = disc.getProf();
	}

	void operator=(Discipline disc);

	static bool cmpHours(Discipline disc1, Discipline disc2) {
		return (disc1.getHours() >= disc2.getHours());
	}

	static bool cmpName(Discipline disc1, Discipline disc2) {
		return (disc1.getName() >= disc2.getName());
	}

	static bool cmpProf(Discipline disc1, Discipline disc2) {
		return (disc1.getProf() >= disc2.getProf());
	}

	static bool cmpType(Discipline disc1, Discipline disc2) {
		return (disc1.getType() >= disc2.getType());
	}

	
private:
	int id, hours, type;
	std::string name, prof;

};