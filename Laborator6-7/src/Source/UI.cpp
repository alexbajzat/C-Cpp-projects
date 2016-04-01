/*
 * UI.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: alex-bajzat
 */

#include "../Header/UI.h"

void UI::pickSecondOptions() {
	std::string prof;
	int dir;
	switch (secondOption) {
	case 1:
		std::cout << "Number of Hours: ";
		int hours;
		std::cin >> hours;
		printList(controller.filterByHours(hours));

		break;
	case 2:
		std::cout << "Name of professor: ";

		std::cin >> prof;
		printList(controller.filterByProf(prof));

		break;
	case 3:
		std::cout << " reverse ? 1/0";
		std::cin >> dir;

		printList(
				controller.sort(dir, Discipline::cmpHours,
						controller.getElementList()));
		break;
	case 4:
		std::cout << " reverse ? 1/0";
		std::cin >> dir;
		printList(
				controller.sort(dir, Discipline::cmpName,
						controller.getElementList()));
		break;

	case 5:
		std::cout << " reverse ? 1/0";
		std::cin >> dir;
		printList(
				controller.sort(dir, Discipline::cmpProf,
						controller.getElementList()));
		break;
	case 6:
		std::cout << " reverse ? 1/0";
		std::cin >> dir;
		printList(
				controller.sort(dir, Discipline::cmpType,
						controller.getElementList()));
		break;

	}

}

UI::UI() {
	option = -1;
	secondOption = -1;
	optionList = "";
	optionList += "\n1.Add Discipline";
	optionList += "\n2.Modify input";
	optionList += "\n3.Delete input";
	optionList += "\n4.Print Discipline List\n";
	optionList += "\n5.more...\n";

	secondOptionList = "";

	secondOptionList += "\n1.Filter by number of hours";
	secondOptionList += "\n2.Filter by name";
	secondOptionList += "\n3.Sort by number of hours";
	secondOptionList += "\n4.Sort by  name";
	secondOptionList += "\n5.Sort by professor";
	secondOptionList += "\n6.Sort by type";
}

void UI::pickOption(int opt) {
	if (opt < 0 || opt > 55) {
		std::cout << "Invalid option! ";
		option = -1;
	} else
		option = opt;
}

void UI::pickSecondOption(int opt) {
	if (opt < 0 || opt > 6) {
		std::cout << "Invalid option! ";
		secondOption = -1;
	} else
		secondOption = opt;

	pickSecondOptions();
}

void UI::pickPromptF() {
	std::cout << "\nYour option: ";
	int opt;
	std::cin >> opt;
	pickOption(opt);

}

void UI::pickPromptS() {
	std::cout << "\nYour option: ";
	int opt;
	std::cin >> opt;
	pickSecondOption(opt);

}

void UI::pickOption() {
	int id, type, hours;
	std::string name, prof;
	switch (option) {
	case 1:
		std::cout << "Discipline(id, type, hours, name, professor: ) \n";
		std::cout << "id: ";
		std::cin >> id;
		std::cout << "\ntype: ";
		std::cin >> type;
		std::cout << "\nhours: ";
		std::cin >> hours;
		std::cout << "\nname: ";
		std::cin >> name;
		std::cout << "\nprof: ";
		std::cin >> prof;

		//catch exception
		controller.addElement(id, type, hours, name, prof);
		break;
	case 2: {
		std::cout << "Position of element: ";
		int pos;
		std::cin >> pos;
		std::cout << "new id: ";
		std::cin >> id;
		std::cout << "\nnew type: ";
		std::cin >> type;
		std::cout << "\nnew hours: ";
		std::cin >> hours;
		std::cout << "\nnew name: ";
		std::cin >> name;
		std::cout << "\nnew prof: ";
		std::cin >> prof;
		controller.modifyElement(id, type, hours, name, prof, pos);
	}
		break;
	case 3: {
		printList(controller.getElementList());
		int pos;
		std::cout << " Position of element: ";
		std::cin >> pos;
		controller.deleteElement(pos);
	}
		break;

	case 4: {
		//print list
		printList(controller.getElementList());
	}
		break;

	case 5: {
		std::cout << secondOptionList;
		pickPromptS();
		break;
	}

	case 0:
		option = 0;
		break;
	}
}

void UI::rule() {
	while (option) {
		std::cout << optionList;
		pickPromptF();
		pickOption();
	}
}

void UI::printList(DynamicVector<Element> list) {
	for (int i = 0; i < list.size(); i++) {
		std::cout << i << "| " << " id: " << list.getElementAtPos(i)->getId()
				<< "  " << " type: " << list.getElementAtPos(i)->getType()
				<< "  " << "hours: " << list.getElementAtPos(i)->getHours()
				<< "  " << "name: " << list.getElementAtPos(i)->getName()
				<< "  " << "profsessor: " << list.getElementAtPos(i)->getProf()
				<< "\n";
	}
}

