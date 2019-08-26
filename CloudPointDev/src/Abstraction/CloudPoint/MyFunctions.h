/*
 * MyFunctions.h
 *
 *  Created on: Aug 20, 2019
 *      Author: u1
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>

#ifndef MYFUNCTIONS_H_
#define MYFUNCTIONS_H_

using namespace std;

//!  Utilities collection
/*!
  Container for static utility member functions
*/
class MyFunctions {
private:
	MyFunctions();
public:

    //! My function to split a string by separator character
    /*!
      \param txt string to split.
      \param strs resulting vector of strings.
      \return number of lexems extracted
    */
	static size_t split(const string &txt, vector<string> &strs, char sep)
	{
		size_t pos=txt.find(sep);
		size_t initialPos=0;
		strs.clear();

		while(pos!=string::npos)
		{
			strs.push_back(txt.substr(initialPos, pos-initialPos));
			initialPos=pos+1;
			pos=txt.find(sep,initialPos);
		}
		strs.push_back(txt.substr(initialPos, min(pos, txt.size())-initialPos+1));
		return strs.size();
	}

	virtual ~MyFunctions();
};

#endif /* MYFUNCTIONS_H_ */
