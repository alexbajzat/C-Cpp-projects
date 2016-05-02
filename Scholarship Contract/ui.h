#pragma once
#include "controller.h"
#include "domain.h"
#include <iostream>

class UI {
private:
	int option, secondOption, contractOption;
	bool notChosen;
	std::string optionList;
	std::string secondOptionList;
	std::string contractOptionList;
	Controller controller;
	ContractController *contractController;
public:
	UI();
	~UI() {
		delete contractController;
	}
	void pickContractPrompt();
	/*
	* set the contractOption to user input
	*/
	void pickContractOption();

	/*
	* choose what action to do
	*/
	void pickContractOption(int opt);
	/*
	* set this option to user input
	*/
	void pickOption(int opt);

	/*
	* set this secondOption to user input
	*/
	void pickSecondOption(int opt);

	/*
	* output for user input
	*/
	void pickPromptF();

	void pickPromptS();

	void pickOption();

	void pickSecondOptions();

	/*
	* the cycle
	*/
	void rule();

	/*
	* prints the list of Element types
	*/
	void printList(std::vector<Element> list);
	void printElement(Element elem);
};