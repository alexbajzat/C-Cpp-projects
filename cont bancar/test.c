#include "test.h"
#include "domain.h"
#include "vector.h"
#include "repository.h"
#include "controller.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

/*
* this function tests the Element`s structure consistency
*/

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

/*
* this function tests the DynVector structure consistency
*/

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

/*
* this function tests the repositor structure and the initRepository function
*/

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

/*
* this function tests the controllerInit function
*/

void testControllerInit(){
    Controller* controller;
    controller=initController();
    assert(sizeof(*controller)==sizeof(Controller));
    controller->repository.elementList.cap=0;
    assert(controller->repository.elementList.cap==0);

}

/*
*this function tests the validateDynVector function
*/

void testValidateDynVector(){
    DynVector dynVector;
    dynVector.cap=20;
    dynVector.len=0;
    assert(validateDynVector(dynVector)==1);

    dynVector.cap=20;
    dynVector.len=20;

    assert(validateDynVector(dynVector)==0);

    dynVector.cap=20;
    dynVector.len=25;

    assert(validateDynVector(dynVector)==0);
}

void testReallocVector(){
    DynVector vector;
    vector.cap=20;
    vector.len=20;
    reallocVector(&vector);
    assert(vector.cap==40);
    vector.elementVector[39].day=2;
    assert(vector.elementVector[39].day==2);

    free(vector.elementVector);

}

/*
* this function runs all the tests
*
*/

void testAll(){
    testElement();
    testDynamicVector();
    testRepository();
    testControllerInit();
    testValidateDynVector();
    testReallocVector();
    printf("Tests ran ok!");
}
