#include "stdafx.h"
#include "repository.h"

void Repository::modifyElement(int pos, Element element) {
	for (int i = 0;i < list.size();i++) {
		if (list[i].getId() == pos) {
			list[i] = element;
		}
	}
}