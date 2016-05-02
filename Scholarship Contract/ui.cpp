#include "stdafx.h"
#include "ui.h"
#include "ui.h"
#include <exception>
#include "validator.h"

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
	case 7:
		std::cout << " reverse ? 1/0";
		std::cin >> dir;
		printList(
			controller.sortMul(dir, Discipline::cmpProf,
				Discipline::cmpType, controller.getElementList()));

	}

}

UI::UI() {
	//hardcoded adds for easy use
	controller.addElement(1, 2, 20, "mate", "barbatei");
	controller.addElement(2, 1, 5, "romana", "nadis");
	controller.addElement(3, 3, 15, "engleza", "negrea");
	controller.addElement(4, 2, 100, "maghiara", "boss");
	controller.addElement(5, 2, 5, "poloneza", "altprof");
	
	notChosen = true;
	option = -1;
	secondOption = -1;
	contractOption = -1;
	optionList = "";
	optionList += "\n1.Add Discipline";
	optionList += "\n2.Modify input";
	optionList += "\n3.Delete input";
	optionList += "\n4.Print Discipline List";
	optionList += "\n5.Find discipline\n";
	optionList += "\n6.more...\n";
	optionList += "\n --7. CONTRACT --/n";
	optionList += "\n 8.undo \n";

	secondOptionList = "";

	secondOptionList += "\n1.Filter by number of hours";
	secondOptionList += "\n2.Filter by name";
	secondOptionList += "\n3.Sort by number of hours";
	secondOptionList += "\n4.Sort by  name";
	secondOptionList += "\n5.Sort by professor";
	secondOptionList += "\n6.Sort by type";
	secondOptionList += "\n7.Sort by professor+type";

	contractOptionList = "";

	contractOptionList += "\n1.Generate contract";
	contractOptionList += "\n2.Print contract";
	contractOptionList += "\n3.Add Discipline";
	contractOptionList += "\n4.Erase contract";
	contractOptionList += "\n5.Export contract";
}

void UI::pickOption(int opt) {
	if (opt < 0 || opt > 8) {
		std::cout << "Invalid option! ";
		option = -1;
	}
	else
		option = opt;
}

void UI::pickSecondOption(int opt) {
	if (opt < 0 || opt > 7) {
		std::cout << "Invalid option! ";
		secondOption = -1;
	}
	else
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

void UI::pickContractPrompt() {
	std::cout << "\nYour Options";
	int opt;
	std::cin >> opt;
	pickContractOption(opt);
}

void UI::pickContractOption(int opt) {
	switch (opt) {
	case 1:
		int i;
		try {
			std::cout << "Number of disciplines: ";
			std::cin >> i;
			contractController->generateContract(i, controller);
		}
		catch (OutOfBoundExcepion& e) {
			std::cout << e.what();
		}
		break;
	case 2:
		this->printList(contractController->getContract());
		break;
	case 3:
		printList(controller.getElementList());
		std::cout << "Id of discipline: ";
		int id;
		std::cin >> id;
		try {
			contractController->add(controller.getElementById(id));
		}
		catch (IdException& e) {
			std::cout << e.what();
		}

		break;
	case 4:
		contractController->erase();
		break;
	case 5:
		std::string file_name;
		std::cout << "file name(no extension): ";
		std::cin >> file_name;
		try {
			if (file_name.find('.') == std::string::npos) {
				
				contractController->exportContract(file_name);
			}
			else
				throw "Error: Invalid name!";
		}
		catch (char const *msg) {
			std::cout << msg;
		}
	}

}

void UI::pickOption() {
	int id, type, hours, pos;
	std::string name, prof, errList;
	switch (option) {
	case 1:

		errList = "";
		std::cout << "Discipline(id, type, hours, name, professor: ) \n";
		std::cout << "id: ";
		std::cin >> id;
		if (!validateId(id))
			errList += "invalid id!\n";
		std::cout << "\ntype: ";
		std::cin >> type;
		if (!validateType(type)) {
			errList += "invalid type!\n";
		}
		std::cout << "\nhours: ";
		std::cin >> hours;
		std::cout << "\nname: ";
		std::cin >> name;
		std::cout << "\nprof: ";
		std::cin >> prof;
		if (errList.length() == 0)
			//catch exception
			try {
			controller.addElement(id, type, hours, name, prof);
		}
		catch (IdException& e) {
			std::cout << e.what();
		}
		else
			std::cout << errList << "\n";
		break;
	case 2: {

		std::cout << "Id of element: ";
		std::cin >> pos;
		id = pos;
		std::cout << "\nnew type: ";
		std::cin >> type;
		if (!validateType(type))
			errList += "Invalid type!\n";
		std::cout << "\nnew hours: ";
		std::cin >> hours;
		std::cout << "\nnew name: ";
		std::cin >> name;
		std::cout << "\nnew prof: ";
		std::cin >> prof;
		if (errList.length() == 0)
			try {
			controller.modifyElement(id, type, hours, name, prof, pos);
		}
		catch (IdException& e) {
			std::cout << e.what();
		}
		else
			std::cout << errList;
	}
			break;
	case 3: {
		printList(controller.getElementList());
		std::cout << " Id of element: ";
		std::cin >> id;
		try {
			controller.deleteElement(id);
		}catch(IdException e){
			std::cout << e.what();
		}
	}
			break;

	case 4: {
		//print list
		printList(controller.getElementList());
	}
			break;
	case 5: {
		std::cout << "Find by id: ";
		std::cin >> id;
		try {
			printElement(controller.getElementById(id));
		}
		catch (IdException e) {
			std::cout << e.what();
		}
	}
			break;

	case 6: {
		std::cout << secondOptionList;
		pickPromptS();
		break;
	}
	case 7: {
		int type;
		if (notChosen) {
			std::cout << "Choose contract export type: CSV/HTML (1/2)\n";
			std::cin >> type;

			if (type > 0 && type < 3) {
				contractController =new ContractController(type);
				notChosen = false;
			}
		}
		std::cout << contractOptionList;
		pickContractPrompt();
	}
			break;
	case 8: {
		controller.undo();
	}
			break;
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

void UI::printList(std::vector<Element> list) {
	for (int i = 0; i < list.size(); i++) {
		std::cout << i;
		printElement(list[i]);
	}
}

void UI::printElement(Element elem) {
	std::cout << " id: " << elem.getId() << "  " << " type: "
		<< elem.getType() << "  " << "hours: " << elem.getHours() << "  "
		<< "name: " << elem.getName() << "  " << "profsessor: "
		<< elem.getProf() << "\n";
}
