#include "vector.h"
#include "domain.h"

#include <stdlib.h>

#define INIT_CAPACITY 20

DynVector initVector(){
    DynVector vector;
    vector.len=0;
    vector.cap=INIT_CAPACITY;
    vector.elementVector=malloc(INIT_CAPACITY*sizeof(Element));
    return vector;
}
