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

int validateDynVector(DynVector dynVector){
    if(dynVector.cap<=dynVector.len)
        return 0;
    return 1;

}

/* this functions reallocates memory for dynamic vector
* the DynVector parameter should be sent by refference
*/

void reallocVector(DynVector *dynVector){
    if(!validateDynVector(*dynVector)){
        DynVector* item=realloc(dynVector->elementVector,2*dynVector->len*sizeof(Element));
        if(item!=NULL){
            dynVector->cap*=2;
            free(dynVector->elementVector);
            dynVector->elementVector=item;
        }
        else{
            printf("Error in reallocing");
        }
    }
}

