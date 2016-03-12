#include<string.h>

#include "domain.h"

/*
* this function creates a new item of Element type and returns it
* id- unsigned
* sum- float
* day- unsigned
* description- string
* return Element type
*/

Element createElement(unsigned id, float sum, unsigned day ,unsigned io, char description[]){
        Element element;
        element.id=id;
        element.sum=sum;
        element.day=day;
        element.io=io;
        strcpy(element.description,description);

        return element;
}
