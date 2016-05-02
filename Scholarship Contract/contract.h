#pragma once

#include "repository.h"
#include "exceptions.h"
#include <fstream>
#include <string>

class Contract {
	friend class Test;

protected:
	Repository repository;
public:

	/*
	* constructor with 0 params
	*/
	Contract() {}

	/*
	* delete all input
	*/
	void cleanContract() {
		std::vector<Element> list = repository.getElementList();
		list.clear();
		repository.clone(list);
		
	}

	/*
	* add element to contract
	*/

	void add(Element elem) {
		for (auto each : repository.getElementList()) {
			if (each.getId() == elem.getId())
				throw IdException();
		}
		repository.addElement(elem);
	}

	void generate(Repository repository, int nr) {
		if (nr > repository.getElementList().size())
			throw OutOfBoundExcepion();

		cleanContract();

		this->repository.clone(repository.shuffleList());
		this->repository.clone(repository.subDiv(0, nr));
		

	}


	/*
	* virtual function for export mode
	*/
	virtual void exportContract(std::string fileName) = 0;

	Repository getRepo() {
		return repository;
	}

	virtual ~Contract() {}

	int getNrOfDisc() {
		return repository.getElementList().size();
	}


	
};

class HTMLContract : public Contract {
public:
	HTMLContract() {
	}

	void exportContract(std::string fileName);

};

class CSVContract : public Contract {
public:
	CSVContract() {
	}
	void exportContract(std::string fileName);

};