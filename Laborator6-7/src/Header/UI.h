/*
 * UI.h
 *
 *  Created on: Mar 28, 2016
 *      Author: alex-bajzat
 */

#ifndef UI_H_
#define UI_H_
#include "../Header/controller.h"
#include "../Header/domain.h"
#include <iostream>

class UI {
private:
	int option, secondOption;
	std::string optionList;
	std::string secondOptionList;
	DisciplineController controller;
public:
	UI();
	/*
	 * set this option to user input
	 */
	void pickOption(int opt) ;

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
	void printList(DynamicVector<Element> list);
};

#endif /* UI_H_ */
