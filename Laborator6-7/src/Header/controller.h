/*
 * controller.h
 *
 *  Created on: Mar 28, 2016
 *      Author: alex-bajzat
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "../Header/disciplineRepo.h"
#include <string>



class DisciplineController {
private:
	DiscRepository repository;

	/*
	 * return the current repository
	 */
	DiscRepository* getRepo() {
		return &repository;
	}
public:

	/*
	 * no params
	 *
	 * in the constructor we initialize the validator class
	 */
	DisciplineController() {
	}

	/*
	 * this function validates input data, and
	 * creates an element
	 */
	void addElement(int id, int type, int hours, std::string name,
			std::string prof);
	/*
	 * This function modifies and element for the
	 * specified position
	 */

	void modifyElement(int id, int type, int hours, std::string name,
			std::string prof, int pos) {
		Element* element = new Element(id, type, hours, name, prof);
		repository.modifyElement(pos, element);
	}

	/*
	 * delete an element at a given position
	 *
	 */
	void deleteElement(int pos) {
		repository.deleteElement(pos);
	}

	/*
	 * returns the dynamicvector object
	 */
	DynamicVector<Element>* getElementList() {
		return getRepo()->getElementList();
	}

	/*
	 * returns a pointer to an element
	 * with the given id (unique)
	 * the id must be validated!
	 */
	Element* getElementById(int id);


	/*
	 * filters a copy of the vector
	 * by number of hours
	 */

	DynamicVector<Element> filterByHours(int hours);

	/*
	 * filters a copy of the vector
	 * by professor name
	 */

	DynamicVector<Element> filterByProf(std::string prof);


	bool direction(bool initial, int dir) {
		if (dir == 0)
			return initial;
		else
			return !initial;
	}

	/*
	 * sorts a copy of the vector
	 * by number of hours
	 */

	DynamicVector<Element> sort(int dir, bool (*f)(Element*, Element*),
			DynamicVector<Element>* initList) ;

	/*DynamicVector<Element> sortMultiple(int dir,
			bool (*first)(Element*, Element*),
			bool (*second)(Element*, Element*),
			DynamicVector<Element>* initList) {

		DynamicVector<Element> fSorted = sort(dir, first, initList);

			wat
		return new DynamicVector<Element> ;
	}*/
};

#endif /* CONTROLLER_H_ */
