// Week 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>


int _tmain(int argc, _TCHAR* argv[])
{
	{	
		// Vector Example
		typedef std::vector<int> IntegerVector;				//Defines a type allowing for simpler code and ease-of-use
		typedef IntegerVector::iterator IntegerVectorIt;

		IntegerVector intVector;

		intVector.push_back(0); //adding to the vector
		intVector.push_back(1);
		intVector.push_back(2);
		intVector.push_back(3);
		intVector.push_back(2);
		intVector.push_back(1);

		for (int index = 0; index < intVector.size(); ++index)
		{
			std::cout << intVector[index] << std::endl;
		}

		for (IntegerVectorIt intIt = intVector.begin();	//When working with iterators, use pre-incement or pre-decrement to avoid excess memory usage
			intIt != intVector.end(); 
			++intIt)
		{
			int& intRef = *intIt;						//Dereferences the iterator and provides the actual value that is stored within the vector (in this case)

			std::cout << intRef << std::endl;
		}

		for (IntegerVector::reverse_iterator intIt = intVector.rbegin();	//reverse_iterator processes the data in the reverse order. .begin and .end will become .rbegin and .rend
			intIt != intVector.rend();
			++intIt)
		{
			int& intRef = *intIt;

			std::cout << intRef << std::endl;
		}
	}
	{	
		// List Example
		typedef std::list<int> IntegerList;							//Defines a type allowing for simpler code and ease-of-use
		typedef IntegerList::iterator IntegerListIt;

		IntegerList intList;

		intList.push_back(0); //adding to the vector
		intList.push_back(1);
		intList.push_back(2);
		intList.push_back(3);
		intList.push_back(2);
		intList.push_back(1);

		for (int index = 0; index < intList.size(); ++index)
		{
			//std::cout << intVector[index] << std::endl;				//Lists cannot refer to a specific value without iterating to it
		}

		for (IntegerListIt intIt = intList.begin();					//When working with iterators, use pre-incement or pre-decrement to avoid excess memory usage
			intIt != intList.end();
			++intIt)
		{
			int& intRef = *intIt;										//Dereferences the iterator and provides the actual value that is stored within the vector (in this case)

			std::cout << intRef << std::endl;
		}

		for (IntegerList::reverse_iterator intIt = intList.rbegin();	//reverse_iterator processes the data in the reverse order. .begin and .end will become .rbegin and .rend
			intIt != intList.rend();
			++intIt)
		{
			int& intRef = *intIt;

			std::cout << intRef << std::endl;
		}
	}

	{
		typedef std::map <int, std::string > IntStringMap;

		IntStringMap numberMap;

		numberMap[3] = "Three";
		numberMap[6] = "Six";
		numberMap[1] = "One";
		numberMap[4] = "Four";
		numberMap[7] = "Seven";
		numberMap[9] = "Nine";
		numberMap[2] = "Two";

		std::cout << numberMap[1] << std::endl;

		IntStringMap::iterator findResult = numberMap.find(5);

		if (findResult != numberMap.end())								//.end is any value not within the list
		{
			std::string& numberString = (*findResult).second;			//.second returns the value from the second column of the map, .first provides the key

			std::cout << numberString << std::endl;
		}

	}




	return 0;
}

