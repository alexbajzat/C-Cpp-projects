#include "stdafx.h"
#include "domain.h"

void Discipline::operator=(Discipline disc) {
	setId(disc.getId());
	setType(disc.getType());
	setHours(disc.getHours());
	setProf(disc.getProf());
	setName(disc.getName());
}