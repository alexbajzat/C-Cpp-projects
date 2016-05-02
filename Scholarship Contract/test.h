#pragma once

#include "domain.h"
#include "repository.h"
#include "controller.h"
#include "contract.h"
#include <assert.h>


/*
* testing the class Element and it`s methods
*/

class Test {
public:
	void testElement() {
		Element disc =Element(1, 2, 20, "romana", "vancea");
		assert(disc.getHours() == 20);
		assert(disc.getType() == 2);
		assert(disc.getId() == 1);
		assert(disc.getName() == "romana");
		assert(disc.getProf() == "vancea");

	}

	void testDomainOperatorE() {
		Element disc = Element(1, 2, 3, "romana", "vasile");
		Element disc2 =Element();
		disc2 = disc;
		assert(disc.getHours() == disc2.getHours());
		assert(disc.getType() == disc2.getType());
		assert(disc.getId() == disc2.getId());
		assert(disc.getName() == disc2.getName());
		assert(disc.getProf() == disc2.getProf());

		disc.setHours(5);

		assert(disc2.getHours() == 3);
		assert(disc.getHours() == 5);

	}



	void testAddAndGetAllRepository() {
		Repository repository;
		Element elem = Element(1, 20, 3, "ana", "mere");
		repository.addElement(elem);
		std::vector<Element> list = repository.getElementList();
		assert(list.size() == 1);
		std::vector<Element> vector;
		vector = repository.getElementList();
		assert(vector.size() == 1);
		assert(vector[0].getId() == 1);
		assert(vector[0].getType() == 20);
		assert(vector[0].getHours() == 3);
		assert(vector[0].getName() == "ana");
		assert(vector[0].getProf() == "mere");

	}

	void testDeleteERepository() {
		Repository repository;
		Element elem = Element(1, 20, 3, "ana", "mere");
		repository.addElement(elem);
		repository.deleteElement(1);
		assert(repository.getElementList().size() == 0);
	}

	void testAddElementAndGetAllController() {
		Controller controller;
		controller.addElement(1, 2, 10, "romana", "vancea");
		std::vector<Element> list = controller.getRepo()->getElementList();
		assert(list.size()==1);
		assert(controller.getElementById(1).getName() == "romana");

	}

	void testGetElementListController() {
		Controller controller;
		controller.addElement(1, 2, 20, "b", "a");
		controller.addElement(2, 2, 20, "c", "d");
		controller.addElement(3, 2, 20, "b", "k");
		std::vector<Element> vector = controller.getRepo()->getElementList();

		assert(vector.size() == 3);
		assert(&vector != &controller.getRepo()->getElementList());

		assert(vector[0].getId() == 1);
		assert(vector[0].getType() == 2);
		assert(vector[1].getId() == 2);
		assert(vector[2].getId() == 3);
	}

	void testModifyElementRepository() {
		Controller controller;
		controller.addElement(1, 2, 10, "ceva", "altceva");
		controller.modifyElement(2, 0, 20, "altceva", "bla bla", 1);

		assert(controller.getRepo()->getElementList()[0].getId() == 2);
		assert(controller.getRepo()->getElementList()[0].getType() == 0);
		assert(
			controller.getRepo()->getElementList()[0].getHours()
			== 20);
		assert(
			controller.getRepo()->getElementList()[0].getName()
			== "altceva");
		assert(
			controller.getRepo()->getElementList()[0].getProf()
			== "bla bla");

	}

	void testGetElementById() {
		Controller controller;
		controller.addElement(1, 2, 3, "ceva", "altceva");
		controller.addElement(2, 5, 2, "e binie", "pappa");
		controller.addElement(3, 2, 3, "ceva", "altceva");
		
		Element check = controller.getElementById(2);

		assert(check.getName() == "e binie");
		

	}

	void testFilterByHours() {
		Controller controller;

		controller.addElement(1, 2, 10, "ceva", "altceva");
		controller.addElement(2, 5, 5, "e binie", "pappa");
		controller.addElement(3, 2, 2, "ceva", "altceva");

		std::vector<Element> vector = controller.filterByHours(8);

		assert(vector.size() == 2);
		assert(vector[0].getId() == 2);
		assert(vector[1].getId() == 3);
	}

	void testFilterByProf() {
		Controller controller;

		controller.addElement(1, 2, 10, "ceva", "altceva");
		controller.addElement(2, 5, 5, "e binie", "pappa");
		controller.addElement(3, 2, 2, "ceva", "altceva");

		std::vector<Element> vector = controller.filterByProf("altceva");

		assert(vector.size() == 2);
		assert(vector[0].getId() == 1);
		assert(vector[1].getId() == 3);
	}

	void testSortByHours() {
		Controller controller;
		controller.addElement(1, 2, 10, "cev", "");
		controller.addElement(2, 2, 8, "cev", "");
		controller.addElement(3, 2, 5, "cev", "");

		std::vector<Element> vector = controller.sort(0, Discipline::cmpHours,
			controller.getElementList());

		assert(vector[0].getId() == 3);
		assert(vector[1].getId() == 2);
		assert(vector[2].getId() == 1);

		std::vector<Element> vector2 = controller.sort(-1,
			Discipline::cmpHours, controller.getElementList());

		assert(vector2[0].getId() == 1);
		assert(vector2[1].getId() == 2);
		assert(vector2[2].getId() == 3);
	}

	void testDeleteAllContract() {
		HTMLContract contract;
		Element elem = Element(1, 2, 3, "ceva", "at");
		contract.add(elem);
		contract.cleanContract();

		assert(contract.getNrOfDisc()== 0);
		
	}

	void testGenerate() {
		HTMLContract contract;
		Controller controller;
		controller.addElement(1, 2, 3, "", "");
		controller.addElement(2, 2, 3, "", "");
		controller.addElement(3, 2, 3, "", "");
		controller.addElement(4, 2, 3, "", "");

		contract.generate(*controller.getRepo(), 2);
		assert(contract.getNrOfDisc() == 2);
		try {
			contract.generate(*controller.getRepo(), 5);
		}
		catch (OutOfBoundExcepion& e) {
			assert(e.what() == "Error: Out of bounds! ");
		}
	}
//
//	void testSortStl() {
//		DisciplineController controller;
//		controller.addElement(1, 2, 25, "abc", "ceva");
//		controller.addElement(2, 3, 50, "bcs", "fain");
//		controller.addElement(3, 1, 1, "bca", "ckas");
//
//		/*DynamicVector<Element> list =
//		controller.getRepo()->dynamicVector.sortSTL(
//		Discipline::cmpHours, controller.getElementList());
//		assert(list.getElementAtPos(0)->getId() == 3);
//		assert(list.getElementAtPos(1)->getId() == 1);
//		assert(list.getElementAtPos(2)->getId() == 2);*/
//	}
//
	void testExportContract() {
		Contract* contract;
		Controller controller;
		controller.addElement(1, 1, 3, "Matematica", "Barbatei");
		controller.addElement(2, 2, 20, "Romana", "Nadis");
		controller.addElement(3, 3, 15, "Engleza", "Yueri");
		controller.addElement(4, 2, 2, "Istorie", "Leucutea");

		HTMLContract htmlContract = HTMLContract();
		CSVContract csvContract = CSVContract();
		contract = &htmlContract;
		contract->generate(*controller.getRepo(), 4);
		contract->exportContract("test.html");

		contract = &csvContract;
		contract->generate(*controller.getRepo(), 4);
		contract->exportContract("test.txt");
	}

	void testUndo() {
		Controller controller;
		controller.addElement(1, 1, 3, "Matematica", "Barbatei");
		controller.addElement(2, 2, 20, "Romana", "Nadis");
		controller.addElement(3, 3, 15, "Engleza", "Yueri");
		controller.addElement(4, 2, 2, "Istorie", "Leucutea");

		controller.undo();

		assert(controller.getRepo()->getElementList().size()==3);
	}

//	void testReadToRepo() {
//		DisciplineController controller;
//		controller.getRepo()->readToRepo("repoIN.txt");
//		controller.getRepo()->writeFromRepo("repoOUT.txt");
//	}
};

void testAll() {
	Test test;
	test.testElement();
	test.testDomainOperatorE();
	test.testAddAndGetAllRepository();
	test.testDeleteERepository();
	test.testAddElementAndGetAllController();
	test.testGetElementListController();
	test.testModifyElementRepository();
	test.testGetElementById();
	test.testFilterByHours();
	test.testFilterByProf();
	test.testSortByHours();
	test.testDeleteAllContract();
	test.testGenerate();
	test.testExportContract();
	test.testUndo();
//	test.testReadToRepo();
}