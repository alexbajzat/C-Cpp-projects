//============================================================================
// Name        : Laborator6-7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../Header/test.h"
#include "../Header/UI.h"
using namespace std;


int main() {
	testAll();
	cout<<"test ran oK! ";
	UI ui;
	ui.rule();
	return 0;
}
