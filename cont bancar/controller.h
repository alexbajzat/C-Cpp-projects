#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "repository.h"

typedef struct {
    Repository repository;
}Controller;

Controller* initController();

#endif // CONTROLLER_H_INCLUDED
