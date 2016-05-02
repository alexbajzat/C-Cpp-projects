#pragma once


bool validateType(int type) {
	return type>0 && type <= 3;
}

bool validateId(int id) {
	return id>0;
}
