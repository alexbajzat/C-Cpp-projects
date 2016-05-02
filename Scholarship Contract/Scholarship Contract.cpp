// Scholarship Contract.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "test.h"
#include "ui.h"


int main()
{
	testAll();
	std::cout << " test over with succes! \n";	
	UI ui = UI();
	ui.rule();
	system("PAUSE");
    return 0;
}

