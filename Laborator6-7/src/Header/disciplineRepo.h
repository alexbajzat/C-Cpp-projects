/*
 * disciplineRepo.h
 *
 *  Created on: Mar 27, 2016
 *      Author: alex-bajzat
 */

#ifndef DISCIPLINEREPO_H_
#define DISCIPLINEREPO_H_

#include "../Header/dynamicVector.h"
#include "../Header/domain.h"

typedef Discipline Element;

class DiscRepository{
friend class Test;
private:
	DynamicVector<Element> dynamicVector;
public:

	/*
	 * no params constructor, init values
	 */
	DiscRepository(){
		dynamicVector=new DynamicVector<Element>();
	}

	/*
	 * 1 param constructor, custom capacity of array
	 */
	DiscRepository(int cap){
		dynamicVector=new DynamicVector<Element>(cap);
	}

	~DiscRepository(){

	}

	/*
	 * this function adds and element to the repository
	 */
	void addElement(Element* elem){
		dynamicVector+=elem;
	}

	/*
	 * this function deletes and element for a given position
	 */
	void deleteElement(int pos){
		dynamicVector.deleteAtPos(pos);
	}

	void modifyElement(int pos,Element* element);



	/*
	 * this function returns the element array
	 * dynamicVector
	 */
	DynamicVector<Element>* getElementList(){
		return &dynamicVector;
	}


};



#endif /* DISCIPLINEREPO_H_ */
