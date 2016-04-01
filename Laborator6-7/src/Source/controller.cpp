/*
 * controller.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: alex-bajzat
 */

#include "../Header/controller.h"

void DisciplineController::addElement(int id, int type, int hours,
		std::string name, std::string prof) {
	Element* element = new Element(id, type, hours, name, prof);
	repository.addElement(element);

}

Element* DisciplineController::getElementById(int id) {
	DynamicVector<Element>* list = repository.getElementList();
	for (int i = 0; i < list->size(); i++)
		if (list->getElementAtPos(i)->getId() == id)
			return list->getElementAtPos(i);

	return new Element; // this return is never used
}

DynamicVector<Element> DisciplineController::filterByHours(int hours) {
	DynamicVector<Element> vector;
	DynamicVector<Element>* initList = repository.getElementList();

	for (int i = 0; i < initList->size(); i++)
		if (initList->getElementAtPos(i)->getHours() < hours)
			vector += initList->getElementAtPos(i);
	return vector;
}

DynamicVector<Element> DisciplineController::filterByProf(std::string prof) {
	DynamicVector<Element> vector;
	DynamicVector<Element>* initList = repository.getElementList();

	for (int i = 0; i < initList->size(); i++)
		if (initList->getElementAtPos(i)->getProf() == prof)
			vector += initList->getElementAtPos(i);
	return vector;
}

DynamicVector<Element> DisciplineController::sort(int dir, bool (*f)(Element*, Element*),
		DynamicVector<Element>* initList) {
	DynamicVector<Element> vector;

	vector = initList;

	for (int i = 0; i < vector.size() - 1; i++)
		for (int j = i + 1; j < vector.size(); j++)
			if (direction(
					f(vector.getElementAtPos(i), vector.getElementAtPos(j)),
					dir)) {
				Element aux = *vector.getElementAtPos(i);
				vector.setElementAtPos(i, vector.getElementAtPos(j));
				vector.setElementAtPos(j, &aux);

			}
	return vector;
}

