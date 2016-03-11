#include <stdio.h>

#include "UI.h"

void initMenuRo(MenuRO* menu){
    strcpy(menu->optionList,"");
    strcat(menu->optionList,"\n1.Add transaction");
    strcat(menu->optionList,"\n2.Modify transaction");
    strcat(menu->optionList,"\n3.Delete transaction");
    strcat(menu->optionList,"\n4.Print transaction list");
    strcat(menu->optionList,"\n");
}


int pickOption(){
    int option;
    printf("\n ## Your option: ");
    scanf("%d",&option);
    return option;
}


void showMenu(){
    MenuRO menu;
    initMenuRo(&menu);
        printf(menu.optionList);
        pickOption();

}


