/*
 * AlgorithmFindTheCenterOfTheMass.h
 *
 *  Created on: Aug 25, 2019
 *      Author: u1
 */

#ifndef ALGORITHMFINDTHECENTEROFTHEMASS_H_
#define ALGORITHMFINDTHECENTEROFTHEMASS_H_

#include "AbstractAlgorithm.h"
template<class ItemsType, class AnswType>
class AlgorithmFindTheCenterOfTheMass: public AbstractAlgorithm<ItemsType, AnswType> {
private:
	ItemsType sum;
	AlgInt count;

public:
	AlgorithmFindTheCenterOfTheMass(){
		count=0;
	}
	bool add(ItemsType item)
	{
		sum=sum+item;
		count++;
		return true;
	}
	virtual AnswType getResult()
	{
		AnswType answer;
		answer=sum/count;
		return answer;
	}
	ItemsType getItem()
	{
		return sum;
	}
	virtual bool clear()
	{
		sum = ItemsType();
		count=0;
		return true;
	}
	virtual ~AlgorithmFindTheCenterOfTheMass(){}
};

#endif /* ALGORITHMFINDTHECENTEROFTHEMASS_H_ */
