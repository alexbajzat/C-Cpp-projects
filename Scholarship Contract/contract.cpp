#include "stdafx.h"
#include "contract.h"
#include <fstream>

void HTMLContract::exportContract(std::string fileName) {
	fileName += ".html";
	std::ofstream file;
	file.open(fileName);
	file << "<!DOCTYPE html><html><head><title>Contract</title></head>";
	file << "<body><div><h1>List of disciplines</h1>";
	file << "<div margins=\"4 px\"><table border=\"1\" style=\"width=100%\">";
	file
		<< " <tr><th>ID</th><th>DISCIPLINE</th><th>PROFESSOR</th><th>TYPE</th><th>HOURS</th></tr>";
	for (int i = 0; i < repository.getElementList().size(); i++) {
		Element elem = repository.getElementList()[i];
		file << "<tr>";
		file << "<td>" << elem.getId() << "</td>";
		file << "<td>" << elem.getName() << "</td>";
		file << "<td>" << elem.getProf() << "</td>";
		file << "<td>" << elem.getType() << "</td>";
		file << "<td>" << elem.getHours() << "</td>";
		file << "</tr>";
	}

	file << "</table></div></body></html>";
	file.close();
}

void CSVContract::exportContract(std::string fileName) {
	fileName += ".txt";
	std::ofstream file;
	file.open(fileName);

	for (int i = 0; i < repository.getElementList().size(); i++) {
		Element elem = repository.getElementList()[i];
		file << elem.getId() << ",";
		file << elem.getName() << ",";
		file << elem.getProf() << ",";
		file << elem.getType() << ",";
		file << elem.getHours() << ",";
		file << "\n";
	}

	file.close();
}