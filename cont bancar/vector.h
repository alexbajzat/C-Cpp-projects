#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include "domain.h"

typedef struct{
    Element* elementVector;
    unsigned len;
    unsigned cap;
}DynVector;

DynVector initVector();

#endif // VECTOR_H_INCLUDED
