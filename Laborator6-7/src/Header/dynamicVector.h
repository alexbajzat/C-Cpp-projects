/*
 * dynamicVector.h
 *
 *  Created on: Mar 27, 2016
 *      Author: alex-bajzat
 */

#ifndef DYNAMICVECTOR_H_
#define DYNAMICVECTOR_H_






#define INIT_CAPACITY 10
template <class T>
class DynamicVector{

friend class Test;

private:
	int cap;
	int len;
	T* elems;
public:
	/*
	 * Constructor with no parameters
	 */
	DynamicVector(){
		cap=INIT_CAPACITY;
		len=0;
		elems=new T[cap];
	}

	/*
	 * Constructor with 2 parameters
	 */
	DynamicVector(int cap){
		this->cap=cap;
		len=0;
		elems=new T[cap];
	}

	/*
	 * Copy constructor
	 */
	DynamicVector(DynamicVector<T>* dynamicVector){
		this->cap=dynamicVector->cap;
		this->len=dynamicVector->len;

		T* newElems=new T[dynamicVector->cap];
		for(int i=0;i<dynamicVector->len;i++){
			newElems[i]=dynamicVector->elems[i];
		}

		this->elems=newElems;
	}

	/*
	 * Destructor
	 */

	~DynamicVector(){
		delete[] elems;
	}

	/*
	 * This function returns the length of the list
	 * integer- len
	 */
	int size(){
		return this->len;
	}

	/*
	 * operator += overloaded to add T element to list
	 */
	void operator+=(T* element){
				addE(element);
	}

 /*
  * this function overloades = to create another dynamic array
  *
  * parameter *dynamicVector
  */

	void operator=(DynamicVector *dynamicVector){
		clone(dynamicVector);
	}

	/*
	 * This function deletes an element
	 * at a given position pos- integer
	 */
	void deleteAtPos(int pos){
		for(int i=pos;i<len-1;i++)
				elems[i]=elems[i+1];
		len--;
	}


	/*
	 * This function returns pointer to an element
	 * at a int pos
	 */
	T* getElementAtPos(int pos){
		return &elems[pos];
	}

	void setElementAtPos(int pos,T* element){
		elems[pos]=element;
	}


private:
	/*
		 *  operator = overloaded to return a copy of the current
		 *  dynamicVector
		 *
		 *  the parameter must be an address
		 */


		void clone(DynamicVector<T>* dynamicVector){
			this->cap=dynamicVector->cap;
			this->len=dynamicVector->len;

			T* newElems=new T[dynamicVector->cap];
			for(int i=0;i<dynamicVector->len;i++){
					newElems[i]=dynamicVector->elems[i];
			}
			delete[] elems;
			this->elems=newElems;
		}



	/*
	 * This functions reallocates the memory when the capacity has been
	 * filled
	 */
	void realloc(){
		if(cap==len){
			cap*=2;
			T* newElems=new T[cap];
			for(int i=0;i<len;i++){
				newElems[i]=elems[i];
			}
			delete[] elems;
			elems=newElems;
		}
	}


	/*
	 * This functions adds and T element to the list
	 */
	void addE(T* element){
		realloc();
		elems[len]=*element;
		len++;
	}


};





#endif /* DYNAMICVECTOR_H_ */
