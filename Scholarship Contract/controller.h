#pragma once


#include "repository.h"
#include "contract.h"
#include "undo.h"
#include <string>
#include <vector>

class Controller {
private:
	Repository repository;
	std::vector<ActionUndo*> undoList;
	

public:
	/*
	* return the current repository
	*/
	Repository* getRepo() {
		return &repository;
	}
	/*
	* no params
	*
	* in the constructor we initialize the validator class
	*/
	Controller() {
	}

	~Controller() {
		for (auto it : undoList) {
			/* delete undoList*/
		}
	}

	/*
	* undo last action
	*/
	void undo() {
		if (undoList.size() > 0) {
			undoList[undoList.size() - 1]->doUndo();
			undoList.pop_back();
		}
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
		Element element =Element(id, type, hours, name, prof);
		Element	newElement = this->getElementById(pos);
		
		ModifyUndo* undo = new ModifyUndo(this->getRepo(),newElement);
		undoList.push_back(undo);

		repository.modifyElement(pos, element);
	}

	/*
	* delete an element at a given position
	*
	*/
	void deleteElement(int id) {
		Element element = this->getElementById(id);
		DeleteUndo *undo = new DeleteUndo(this->getRepo(), element);
		undoList.push_back(undo);
		repository.deleteElement(id);
	}

	/*
	* returns the dynamicvector object
	*/
	/*vector<Element>* getElementList() {
		return getRepo()->getElementList();
	}
*/
	/*
	* returns a pointer to an element
	* with the given id (unique)
	* the id must be validated!
	*/
	Element getElementById(int id);


	/*
	get the list of elements 
	*/
	
	std::vector<Element> getElementList() {
		return repository.getElementList();
	}

	/*
	* filters a copy of the vector
	* by number of hours
	*/
	std::vector<Element> filterByHours(int hours);

	/*
	* filters a copy of the vector
	* by professor name
	*/

	std::vector<Element> filterByProf(std::string prof);

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

	std::vector<Element> sort(int dir, bool(*f)(Element, Element),
		std::vector<Element> initList);

	/*
	* sort a copy of the vector
	* for two criteria
	*/
	std::vector<Element> sortMul(int dir, bool(*f)(Element, Element),
		bool(*s)(Element, Element), std::vector<Element> initList);

};


class ContractController {
private: 
	Contract *contract;
public:

	ContractController() {
		contract = new HTMLContract();
	}

	ContractController(int type) {

		if (type == 1) {
			
			contract = new CSVContract();
		}
		else
		{
			contract =new HTMLContract();
		}
	}

	~ContractController() {
		delete contract;
	}

	/*
	* generate contract with random disciplines
	* nrElems- int
	* controller - DisciplineController
	*/
	void generateContract(int nrElems, Controller controller) {
		contract->generate(*controller.getRepo(), nrElems);
	}

	/*
	* add Discipline to contract
	*/
	void add(Element elem) {
		contract->add(elem);
	}

	/*
	* erase contract
	*/
	void erase() {
		contract->cleanContract();
	}

	void exportContract(std::string fileName) {
		contract->exportContract(fileName);
	}

	/*
	* return contract
	*/
	std::vector<Element> getContract() {
		return contract->getRepo().getElementList();
	}

	/*
	* number of elements in contract
	*/
	int getContractSize() {
		return contract->getNrOfDisc();
	}

};

