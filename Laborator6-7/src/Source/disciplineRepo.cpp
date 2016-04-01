/*
 * disciplineRepo.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: alex-bajzat
 */
#include "../Header/disciplineRepo.h"

void DiscRepository::modifyElement(int pos,Element* element){
		dynamicVector.setElementAtPos(pos,element);
	}

