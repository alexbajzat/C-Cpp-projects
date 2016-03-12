#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "UI.h"
#include "controller.h"

void initMenuRo(MenuRO* menu){

    strcpy(menu->optionList,"");
    strcat(menu->optionList,"\n1.Add transaction");
    strcat(menu->optionList,"\n2.Modify transaction");
    strcat(menu->optionList,"\n3.Delete transaction");
    strcat(menu->optionList,"\n4.Print transaction list");
    strcat(menu->optionList,"\n");

    menu->controller=initController();

}


int pickOption(){
    int option;
    printf("\n ## Your option: ");
    scanf("%d",&option);
    return option;
}


void showMenu(){
    MenuRO menu;
    int option=1;
    initMenuRo(&menu);
    while(option!=0){
        printf(menu.optionList);
        option=pickOption();
        executeOption(&menu,option);
    }

    free(menu.controller->repository.elementList.elementVector);


}

void executeOption(MenuRO* menu,int option){
    if(option==1){
        unsigned id, day ,io;
        float sum;
        char description[20];

        printf("Add a transaction (id, sum, day ,input/output(0/1), description (one word): ");
        printf("\n id: ");
        scanf("%d",&id);

        printf("\n sum: ");
        scanf("%f",&sum);

        printf("\n day: ");
        scanf("%d",&day);

        printf("\n input/output: ");
        scanf("%d",&io);

        printf("\n description: ");
        scanf("%s",description);

        addElement(menu->controller,id,sum,day,io,description);
        printf("succesfull! ");
    }else if(option==4){
        DynVector list=getElementList(menu->controller);

        int i;

        for(i=0;i<menu->controller->repository.elementList.len;i++)
            printf("id:%d, sum:%f, day:%d, i/o:%d, description:%s \n",menu->controller->repository.elementList.elementVector[i].id,menu->controller->repository.elementList.elementVector[i].sum
                            ,menu->controller->repository.elementList.elementVector[i].day,menu->controller->repository.elementList.elementVector[i].io,menu->controller->repository.elementList.elementVector[i].description);

    }

}
