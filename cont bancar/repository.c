#include "repository.h"
#include "vector.h"

Repository initRepository(){
    Repository repository;
    repository.elementList=initVector();
    return repository;
}

void addElementToRepo(Repository* repository, Element element){
    reallocVector(&repository->elementList);
    repository->elementList.elementVector[repository->elementList.len]=element;
    repository->elementList.len++;
}
