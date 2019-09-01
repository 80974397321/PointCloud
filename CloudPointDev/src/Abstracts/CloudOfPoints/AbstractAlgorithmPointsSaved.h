/*
 * AbstractAlgorithmPointsSaved.h
 *
 *  Created on: Aug 25, 2019
 *      Author: u1
 */

#include "AbstractAlgorithm.h"
#include <vector>

#ifndef ABSTRACTALGORITHMPOINTSSAVED_H_
#define ABSTRACTALGORITHMPOINTSSAVED_H_



template <class ItemsType, class AnswerType>
class AbstractAlgorithmPointsSaved:AbstractAlgorithm<ItemsType,AnswerType> {
private:
	vector<ItemsType> items;
public:
	AbstractAlgorithmPointsSaved(){}
	virtual bool add(ItemsType item)
	{
		items.push_back(item);
		return true;
	}
	virtual bool clear()
	{
		items.clear();
		return true;
	}
	virtual AnswerType getResult()=0;
	virtual ~AbstractAlgorithmPointsSaved(){}
};

#endif /* ABSTRACTALGORITHMPOINTSSAVED_H_ */
