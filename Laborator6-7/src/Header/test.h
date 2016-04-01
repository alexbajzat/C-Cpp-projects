/*
 * test.h
 *
 *  Created on: Mar 27, 2016
 *      Author: alex-bajzat
 */

#ifndef TEST_H_
#define TEST_H_
#include <iostream>

#include "../Header/domain.h"
#include "../Header/dynamicVector.h"
#include "../Header/disciplineRepo.h"
#include "../Header/controller.h"
#include <assert.h>


/*
 * testing the class Element and it`s methods
 */

class Test {
public:
	void testElement() {
		Element* disc = new Element(1, 2, 20, "romana", "vancea");
		assert(disc->getHours() == 20);
		assert(disc->getType() == 2);
		assert(disc->getId() == 1);
		assert(disc->getName() == "romana");
		assert(disc->getProf() == "vancea");

	}

	void testDynamicVectorConstructors() {
		DynamicVector<Element> vector;
		assert(vector.size() == 0);
		assert(vector.cap == 10);
	}

	void testRealloc() {
		DynamicVector<Element> vector;
		vector.len = vector.cap;
		vector.realloc();
		assert(vector.cap == 20);
	}

	void testAddE() {
		DynamicVector<Element> vector;
		Element* disc = new Element(1, 2, 3, "romana", "vasile");
		vector.addE(disc);

		assert(vector.elems[0].getId() == 1);
		assert(vector.elems[0].getHours() == 3);
		assert(vector.elems[0].getType() == 2);
		assert(vector.elems[0].getName() == "romana");
		assert(vector.elems[0].getProf() == "vasile");
	}

	void testDomainOperatorE() {
		Element* disc = new Element(1, 2, 3, "romana", "vasile");
		Element* disc2 = new Element();
		*disc2 = *disc;
		assert(disc->getHours() == disc2->getHours());
		assert(disc->getType() == disc2->getType());
		assert(disc->getId() == disc2->getId());
		assert(disc->getName() == disc2->getName());
		assert(disc->getProf() == disc2->getProf());

		disc->setHours(5);

		assert(disc2->getHours() == 3);
		assert(disc->getHours() == 5);

	}

	void testOperatorPE() {
		DynamicVector<Element> vector;
		Element* disc = new Element(1, 2, 3, "romana", "vasile");
		vector += disc;

		assert(vector.elems[0].getId() == 1);
		assert(vector.elems[0].getHours() == 3);
		assert(vector.elems[0].getType() == 2);
		assert(vector.elems[0].getName() == "romana");
		assert(vector.elems[0].getProf() == "vasile");
	}

	void testDynamicVectorCopyConstructor() {
		DynamicVector<Element> vector;
		Element* disc = new Element(1, 2, 3, "romana", "vasile");
		vector += disc;

		DynamicVector<Element> vector2 = new DynamicVector<Element>(vector);

		assert(vector2.elems[0].getId() == vector.elems[0].getId());
		assert(vector2.elems[0].getType() == vector.elems[0].getType());
		assert(vector2.elems[0].getHours() == vector.elems[0].getHours());
		assert(vector2.elems[0].getName() == vector.elems[0].getName());
		assert(vector2.elems[0].getProf() == vector.elems[0].getProf());

		vector2.elems[0].setId(2);

		assert(vector2.elems[0].getId() != vector.elems[0].getId());
	}

	void testDynamicVectorClone() {
		DynamicVector<Element> vector = new DynamicVector<Element>();
		Element* disc = new Element(1, 2, 3, "romana", "vasile");
		vector += disc;

		DynamicVector<Element> vector2 = new DynamicVector<Element>();
		vector2.clone(&vector);

		assert(vector2.elems[0].getId() == vector.elems[0].getId());
		assert(vector2.elems[0].getType() == vector.elems[0].getType());
		assert(vector2.elems[0].getHours() == vector.elems[0].getHours());
		assert(vector2.elems[0].getName() == vector.elems[0].getName());
		assert(vector2.elems[0].getProf() == vector.elems[0].getProf());

		vector2.elems[0].setId(2);
		assert(vector2.elems[0].getId() == 2);
		assert(vector.elems[0].getId() == 1);
	}

	void testGetElementAtPos() {
		DynamicVector<Element> vector;
		vector += new Element(1, 2, 3, "romana", "vasile");
		vector += new Element(2, 1, 10, "mate", "ion");
		vector += new Element(3, 3, 50, "engleza", "vancea");

		Element* disc = vector.getElementAtPos(1);
		assert(disc->getId() == 2);
		assert(disc->getHours() == 10);
		assert(disc->getType() == 1);
		assert(disc->getName() == "mate");
		assert(disc->getProf() == "ion");

	}

	void testDynamicVectorOperatorE() {
		DynamicVector<Element> vector = new DynamicVector<Element>();
		Element* disc = new Element(1, 2, 3, "romana", "vasile");
		vector += disc;

		DynamicVector<Element> vector2;
		vector2 = &vector;

		assert(
				vector2.getElementAtPos(0)->getId()
						== vector.getElementAtPos(0)->getId());

		vector2.elems[0].setId(2);
		assert(vector2.elems[0].getId() == 2);
		assert(vector.elems[0].getId() == 1);
	}

	void testDeleteAtPos() {
		DynamicVector<Element> dynamicVector;
		dynamicVector += new Element(1, 20, 3, "ana", "mere");
		dynamicVector += new Element(2, 1, 15, "marcel", "pere");
		dynamicVector += new Element(3, 5, 4, "fain", "asa");

		dynamicVector.deleteAtPos(0);

		assert(dynamicVector.getElementAtPos(0)->getId() == 2);
	}

	void testSetElementAtPos() {
		DynamicVector<Element> dynamicVector;
		Element* disc = new Element(1, 20, 3, "ana", "mere");
		dynamicVector += disc;

		disc->setId(3);
		dynamicVector.setElementAtPos(0, disc);

		assert(dynamicVector.getElementAtPos(0)->getId() == 3);
	}

	void testAddAndGetAllRepository() {
		DiscRepository repository;
		Element* elem = new Element(1, 20, 3, "ana", "mere");
		repository.addElement(elem);
		assert(repository.dynamicVector.size() == 1);
		DynamicVector<Element>* vector;
		vector = repository.getElementList();
		assert(vector->size() == 1);
		assert(vector->getElementAtPos(0)->getId() == 1);
		assert(vector->getElementAtPos(0)->getType() == 20);
		assert(vector->getElementAtPos(0)->getHours() == 3);
		assert(vector->getElementAtPos(0)->getName() == "ana");
		assert(vector->getElementAtPos(0)->getProf() == "mere");

	}

	void testDeleteERepository() {
		DiscRepository repository;
		Element* elem = new Element(1, 20, 3, "ana", "mere");
		repository.addElement(elem);

		repository.deleteElement(0);
		assert(repository.getElementList()->size() == 0);
	}

	void testAddElementAndGetAllController() {
		DisciplineController controller;
		controller.addElement(1, 2, 10, "romana", "vancea");

	}

	void testGetElementListController() {
		DisciplineController controller;
		controller.addElement(1, 2, 20, "b", "a");
		controller.addElement(2, 2, 20, "c", "d");
		controller.addElement(3, 2, 20, "b", "k");
		DynamicVector<Element> vector = controller.getElementList();

		assert(vector.size() == 3);
		assert(&vector != controller.getElementList());

		assert(vector.getElementAtPos(0)->getId() == 1);
		assert(vector.getElementAtPos(0)->getType() == 2);
		assert(vector.getElementAtPos(1)->getId() == 2);
		assert(vector.getElementAtPos(2)->getId() == 3);

		vector.getElementAtPos(0)->setId(2);
		assert(
				controller.getElementList()->getElementAtPos(0)->getId()
						!= vector.getElementAtPos(0)->getId());
	}

	void testModifyElementRepository() {
		DisciplineController controller;
		controller.addElement(1, 2, 10, "ceva", "altceva");
		controller.modifyElement(2, 0, 20, "altceva", "bla bla", 0);

		assert(controller.getElementList()->getElementAtPos(0)->getId() == 2);
		assert(controller.getElementList()->getElementAtPos(0)->getType() == 0);
		assert(
				controller.getElementList()->getElementAtPos(0)->getHours()
						== 20);
		assert(
				controller.getElementList()->getElementAtPos(0)->getName()
						== "altceva");
		assert(
				controller.getElementList()->getElementAtPos(0)->getProf()
						== "bla bla");

	}

	void testGetElementById() {
		DisciplineController controller;
		controller.addElement(1, 2, 3, "ceva", "altceva");
		controller.addElement(2, 5, 2, "e binie", "pappa");
		controller.addElement(3, 2, 3, "ceva", "altceva");

		assert(controller.getElementById(2)->getId() == 2);
		assert(controller.getElementById(2)->getType() == 5);
		assert(controller.getElementById(2)->getHours() == 2);
		assert(controller.getElementById(2)->getName() == "e binie");
		assert(controller.getElementById(2)->getProf() == "pappa");

	}

	void testFilterByHours() {
		DisciplineController controller;

		controller.addElement(1, 2, 10, "ceva", "altceva");
		controller.addElement(2, 5, 5, "e binie", "pappa");
		controller.addElement(3, 2, 2, "ceva", "altceva");

		DynamicVector<Element> vector = controller.filterByHours(8);

		assert(vector.size() == 2);
		assert(vector.getElementAtPos(0)->getId() == 2);
		assert(vector.getElementAtPos(1)->getId() == 3);
	}

	void testFilterByProf() {
		DisciplineController controller;

		controller.addElement(1, 2, 10, "ceva", "altceva");
		controller.addElement(2, 5, 5, "e binie", "pappa");
		controller.addElement(3, 2, 2, "ceva", "altceva");

		DynamicVector<Element> vector = controller.filterByProf("altceva");

		assert(vector.size() == 2);
		assert(vector.getElementAtPos(0)->getId() == 1);
		assert(vector.getElementAtPos(1)->getId() == 3);
	}

	void testSortByHours() {
		DisciplineController controller;
		controller.addElement(1, 2, 10, "cev", "");
		controller.addElement(2, 2, 8, "cev", "");
		controller.addElement(3, 2, 5, "cev", "");

		DynamicVector<Element> vector = controller.sort(0, Discipline::cmpHours,
				controller.getElementList());

		assert(vector.getElementAtPos(0)->getId() == 3);
		assert(vector.getElementAtPos(1)->getId() == 2);
		assert(vector.getElementAtPos(2)->getId() == 1);

		DynamicVector<Element> vector2 = controller.sort(-1,
				Discipline::cmpHours, controller.getElementList());

		assert(vector2.getElementAtPos(0)->getId() == 1);
		assert(vector2.getElementAtPos(1)->getId() == 2);
		assert(vector2.getElementAtPos(2)->getId() == 3);

	}

};

void testAll() {
	Test test;
	test.testElement();
	test.testDomainOperatorE();
	test.testDynamicVectorConstructors();
	test.testRealloc();
	test.testAddE();
	test.testOperatorPE();
	test.testDynamicVectorCopyConstructor();
	test.testDynamicVectorClone();
	test.testGetElementAtPos();
	test.testDynamicVectorOperatorE();
	test.testDeleteAtPos();
	test.testSetElementAtPos();
	test.testAddAndGetAllRepository();
	test.testDeleteERepository();
	test.testAddElementAndGetAllController();
	test.testGetElementListController();
	test.testModifyElementRepository();
	test.testGetElementById();
	test.testFilterByHours();
	test.testFilterByProf();
	test.testSortByHours();
}

#endif /* TEST_H_ */
