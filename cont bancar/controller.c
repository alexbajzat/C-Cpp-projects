#include "controller.h"
#include "repository.h"

Controller* initController(){
    Controller* controller;
    controller=malloc(sizeof(Controller));
    controller->repository=initRepository();
    return controller;
}
