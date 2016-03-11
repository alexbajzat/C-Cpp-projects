#include "test.h"
#include "domain.h"
#include "vector.h"
#include "repository.h"
#include "controller.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

void testElement(){
    Element element;

    element.id=0;
    assert(element.id==0);
    element.day=0;
    assert(element.day==0);
    element.io=0;
    assert(element.io==0);
    strcpy(element.description,"ceva");
    assert(strcmp(element.description,"ceva")==0);
}

void testDynamicVector(){
    DynVector vector=initVector();
    assert(vector.cap==20);
    assert(vector.len==0);
    assert(sizeof(*vector.elementVector)==sizeof(Element));

    vector.elementVector[0].day=0;
    assert(vector.elementVector[0].day==0);

    vector.elementVector[19].day=0;
    assert(vector.elementVector[19].day==0);

    free(vector.elementVector);

}

void testRepository(){
    Repository repository;
    assert(sizeof(repository.elementList)==sizeof(DynVector));
    repository=initRepository();
    repository.elementList.cap=0;
    assert(repository.elementList.cap==0);

    repository.elementList.elementVector[0].day=0;
    assert(repository.elementList.elementVector[0].day==0);

    free(repository.elementList.elementVector);

}


void testControllerInit(){
    Controller* controller;
    controller=initController();
    assert(sizeof(*controller)==sizeof(Controller));
    controller->repository.elementList.cap=0;
    assert(controller->repository.elementList.cap==0);

}


void testAll(){
    testElement();
    testDynamicVector();
    testRepository();
    testControllerInit();
    printf("Tests ran ok!");
}
