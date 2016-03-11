#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include "domain.h"

typedef struct{
    Element* elementVector;
    unsigned len;
    unsigned cap;
}DynVector;

DynVector initVector();
int validateDynVector(DynVector dynVector);
void reallocVector(DynVector *dynVector);

#endif // VECTOR_H_INCLUDED
