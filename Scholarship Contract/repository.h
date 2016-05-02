#pragma once
#include "domain.h"

typedef Discipline Element;

#include "domain.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include "exceptions.h"
#include <chrono>
#include <random>


typedef Discipline Element;

class Repository {
	friend class Test;
protected:
	std::vector<Element> list;
public:

	/*
	* no params constructor, init values
	*/
	Repository() {}

	/*
	* constructor wich reads from file
	*/

	Repository(std::string fileName) {
		readToRepo(fileName);
	}


	~Repository() {}

	/*
	* this function adds and element to the repository
	*/
	void addElement(Element fElem) {
		for (auto elem : list)
			if (fElem.getId() == elem.getId())
				throw IdException();
		list.push_back(fElem);
	}

	/*
	* this function deletes an element for a given id
	*/
	void deleteElement(int id) {
		for (int i = 0;i < list.size();i++) {
			if (list[i].getId() == id) {
				list.erase(list.begin() + i);
			}
			
		}
	}

	void modifyElement(int pos, Element element);



	/*
	* this function returns the element array
	* vector
	*/
	std::vector<Element> getElementList() {
		return list;
	}

	/*
	* clone the given vector
	*/

	void clone(std::vector<Element> vector) {
		if (vector.size() == 0) {
			list.clear();
		}
		else {
			list = vector;

		}
	}


	/*
	* get subdivided copy of vector
	*/
	std::vector<Element> subDiv(int begin, int end) {

		return std::vector<Element>(list.begin() + begin, list.begin() + end);
		
	}

	/*
	* shuffle list
	*/
	std::vector<Element> shuffleList() {
		auto seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::vector<Element> list = this->list;
		shuffle(list.begin(), list.end(), std::default_random_engine(seed));
		return list;
	}


	/*
	* read elements from file
	* fileName - string
	*/
	void readToRepo(std::string fileName);

	/*
	* write to file , filename given
	* fileName -string
	*/

	void writeFromRepo(std::string fileName);


};
