#pragma once


#include "repository.h"

class ActionUndo {
protected:
	Repository *repo;
	Element elem;
public:
	explicit ActionUndo(Repository *repo, Element elem) {
		this->repo = repo;
		this->elem = elem;
	}

	virtual void doUndo() = 0;
	virtual ~ActionUndo() {}

};

class AddUndo : public ActionUndo {
public:
	using ActionUndo::ActionUndo;

	void doUndo() {
		repo->deleteElement(elem.getId());
	}
};

class DeleteUndo : public ActionUndo {
public:
	using ActionUndo::ActionUndo;
	void doUndo() {
		repo->addElement(elem);
	}
};

class ModifyUndo : public ActionUndo {
public:
	using ActionUndo::ActionUndo;
	void doUndo() {
		repo->modifyElement(elem.getId(), elem);
	}
};