#include "test.h"
#include "domain.h"
#include "vector.h"
#include "repository.h"
#include "controller.h"
#include "UI.h"

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
    dynVector.cap=20;https://www.facebook.com/MKXUnofficial/videos/975803022508142/
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

void testCreateElement(){
    Element element=createElement(1,50,0,0,"ceva");

    assert(element.id==1);
    assert(element.sum==50);
    assert(element.day==0);
    assert(element.io==0);
    assert(strcmp(element.description,"ceva")==0);
}

void testAddElementToRepo(){
    Repository repository=initRepository();
    Element element;
    element.id=0;
    addElementToRepo(&repository,element);
    assert(repository.elementList.elementVector[0].id==0);
    assert(repository.elementList.len==1);
    free(repository.elementList.elementVector);

}
/*
* this function tests controller`s addElement method
*/
void testAddElement(){
    Controller* controller=initController();
    addElement(controller,1,250,0,0,"ceva");
    assert(controller->repository.elementList.elementVector[0].id==1);
    assert(controller->repository.elementList.elementVector[0].sum==250);
    assert(controller->repository.elementList.elementVector[0].day==0);
    assert(controller->repository.elementList.elementVector[0].io==0);
    assert(strcmp(controller->repository.elementList.elementVector[0].description,"ceva")==0);

    free(controller->repository.elementList.elementVector);
}


void testInitMenuRO(){
    MenuRO* menu;
    initMenuRo(menu);
    assert(menu->controller->repository.elementList.len==0);
}


void testGetElementList(){
    Controller* controller=initController();

    addElement(controller,1,150,2,0,"ceva");
    addElement(controller,2,200,0,0,"altceva");
    addElement(controller,3,400,1,1,"pa");

    DynVector list;

    list=getElementList(controller);


    assert(list.elementVector[0].id==1);
    assert(list.elementVector[1].sum==200);
    assert(strcmp(list.elementVector[2].description,"pa")==0);


    free(controller->repository.elementList.elementVector);

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
    testCreateElement();
    testAddElementToRepo();
    testAddElement();
    testInitMenuRO();
    testGetElementList();
    printf("Tests ran ok!");
}
