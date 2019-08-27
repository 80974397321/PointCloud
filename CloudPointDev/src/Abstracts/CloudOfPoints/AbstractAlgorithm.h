/*
 * AbstractAlgorithm.h
 *
 *  Created on: Aug 25, 2019
 *      Author: u1
 */

#ifndef ABSTRACTALGORITHM_H_
#define ABSTRACTALGORITHM_H_

#include <iostream>
#include <fstream>
#include <string>

typedef double AlgDouble;
typedef int AlgInt;
typedef string AlgString;

template<class ItemsType, class AnswerType>
class AbstractAlgorithm {
public:
	/*template <class T>
	static bool loadPointToAlgFromFile(AlgString text, AbstractAlgorithm<T, AlgDouble>* alg)
	{
		ifstream infile(text);
			if (! infile)
			{
				return false;
			}
			string str;
			vector<string> temp;
			while(std::getline(infile,str))
			{
				MyFunctions::split(str,temp,' ');
				T p;
				p[0] = stod(temp[0]);
				p[1] = stod(temp[1]);
				temp.clear();
				alg->add(p);
			}
			infile.close();
			return true;
	}
	*/
	virtual bool add(ItemsType item)
	{
		return true;
	}
	virtual bool clear()
	{
		return true;
	}
	virtual AnswerType getResult(){return AnswerType();};
};

#endif /* ABSTRACTALGORITHM_H_ */
