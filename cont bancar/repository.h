#ifndef REPOSITORY_H_INCLUDED
#define REPOSITORY_H_INCLUDED
#include "vector.h"
typedef struct{
    DynVector elementList;
}Repository;


Repository initRepository();

#endif // REPOSITORY_H_INCLUDED
