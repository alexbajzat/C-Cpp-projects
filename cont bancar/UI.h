#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED
#include "controller.h"

typedef struct{
    char optionList[500];
    Controller* controller;
}MenuRO;

void initMenuRo(MenuRO* menu);
int pickOption();
void showMenu();
void executeOption(MenuRO* menu,int option);



#endif // UI_H_INCLUDED
