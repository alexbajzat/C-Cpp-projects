#include "repository.h"
#include "vector.h"

Repository initRepository(){
    Repository repository;
    repository.elementList=initVector();
    return repository;
}

