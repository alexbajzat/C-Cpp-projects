#include "controller.h"
#include "repository.h"
#include "domain.h"

Controller* initController(){
    Controller* controller;
    controller=malloc(sizeof(Controller));
    controller->repository=initRepository();
    return controller;
}

void addElement(Controller* controller,unsigned id,float sum, unsigned day, unsigned io,char description[]){

    Element newElement=createElement(id,sum,day,io,description);
    addElementToRepo(&controller->repository,newElement);

}

DynVector getElementList(Controller* controller){
    return controller->repository.elementList;

}
