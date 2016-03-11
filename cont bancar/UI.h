#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

typedef struct{
    char optionList[250];
    int option;
}MenuRO;

void initMenuRo(MenuRO* menu);
int pickOption();
void showMenu();



#endif // UI_H_INCLUDED
