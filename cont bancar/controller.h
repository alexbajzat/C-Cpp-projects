#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "repository.h"

typedef struct {
    Repository repository;
}Controller;

Controller* initController();
void addElement(Controller* controller,unsigned id,float sum, unsigned day, unsigned io,char description[]);
DynVector getElementList(Controller* controller);

#endif // CONTROLLER_H_INCLUDED
