#ifndef REPOSITORY_H_INCLUDED
#define REPOSITORY_H_INCLUDED
#include "vector.h"
typedef struct{
    DynVector elementList;
}Repository;


Repository initRepository();
void addElementToRepo(Repository* repository, Element element);
#endif // REPOSITORY_H_INCLUDED
