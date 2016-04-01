/*
 * domain.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author: alex-bajzat
 */

#include "../Header/domain.h"

Discipline& Discipline::operator=(Discipline* disc) {

		id = disc->getId();
		type = disc->getType();
		hours = disc->getHours();
		name = disc->getName();
		prof = disc->getProf();
		return *this;
	}
