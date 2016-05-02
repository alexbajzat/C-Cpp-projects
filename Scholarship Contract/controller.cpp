#include "stdafx.h"
#include "controller.h"
#include <algorithm>
#include <vector>
#include "exceptions.h"


void Controller::addElement(int id, int type, int hours,
	std::string name, std::string prof) {
	Element element = Element(id, type, hours, name, prof);
	repository.addElement(element);
	AddUndo* undo =new AddUndo(this->getRepo(), element);
	undoList.push_back(undo);

}

Element Controller::getElementById(int id) {
	std::vector<Element> list = repository.getElementList();
	for (auto elem : list)
		if (elem.getId() == id)
			return elem;

	throw IdException(); // no id exception
}

std::vector<Element> Controller::filterByHours(int hours) {
	std::vector<Element> vector;
	std::vector<Element> initList = repository.getElementList();

	for (auto elem : initList)
		if (elem.getHours() < hours)
			vector.push_back(elem);
	return vector;
}

std::vector<Element> Controller::filterByProf(std::string prof) {	
	std::vector<Element> vector;
	std::vector<Element> initList = repository.getElementList();

	for (auto elem : initList)
		if (elem.getProf() == prof)
			vector.push_back(elem);
	return vector;
}

std::vector<Element> Controller::sort(int dir,
	bool(*f)(Element, Element), std::vector<Element> initList) {
	std::vector<Element> vector;

	vector = initList;

	for (int i = 0; i < vector.size() - 1; i++)
		for (int j = i + 1; j < vector.size(); j++)
			if (direction(
				f(vector[i], vector[j]),
				dir)) {
				Element aux = vector[i];
				vector[i]=vector[j];
				vector[j]=aux;

			}
	return vector;
}

std::vector<Element> Controller::sortMul(int dir,
	bool(*f)(Element, Element), bool(*s)(Element, Element),
	std::vector<Element> initList) {
	std::vector<Element> vector;

	vector = initList;

	for (int i = 0; i < vector.size() - 1; i++)
		for (int j = i + 1; j < vector.size(); j++)
			if (direction(
				f(vector[i], vector[j]),
				dir)) {
				Element aux = vector[i];
				vector[i] = vector[j];
				vector[j] = aux;

			}
	for (int i = 0; i < vector.size() - 1; i++) {
		int startIndex = i, endIndex = i;
		while (i + 1 < vector.size()
			&& vector[i].getProf()
			== vector[i + 1].getProf()) {
			endIndex++;
			i++;
		}

		for (int j = startIndex; j < endIndex - 1; j++)
			for (int k = startIndex + 1; k < endIndex; k++)
				if (direction(
					f(vector[i], vector[j]),
					dir)) {
					Element aux = vector[i];
					vector[i] = vector[j];
					vector[j] = aux;

				}
	}
	return vector;
}