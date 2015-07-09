// app1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

namespace GoodName
{
	class ExampleClass
	{

	};
}

namespace GoodName
{
	class ExampleClass2
	{
		ExampleClass variable;
	public:
		void ExampleFunction()
		{
			// Localised declaration
			using namespace std;
		}
	};

	class string
	{

	};
}

using namespace GoodName;

// Adds an additional name to the namespace allowing for ease-of-use
namespace GN = GoodName;

void ExampleFn_Value(std::string stringVal)
{

}

void ExampleFn_Reference(std::string& stringVal)
{

}

void ExampleFn_ConstReference(const std::string& stringVal)
{

}

void ExampleFn_Pointer(std::string* stringVal)
{

}

void ExampleFn_ConstPointer(const std::string* stringVal)
{

}

/// 4 main ways to pass data
/// by value					(int, float, double etc.)				(can't be edited)
/// by reference				(both those above and below)			(can be edited)
/// by const reference			(complex objects (vectors etc.) etc.)
/// by pointer					(for non-existant objects (null or arbitrary), real-existent object)	
/// by const pointer	

//int* badPtr;				//sets the pointer to an arbitrary space in memory
//int* badPtr = nullptr;	//sets the pointer to a known nothing



////////////////////SINGLETON///////////////////// 
//Can only create itself once//only created once//
class ExampleSingleton
{
private:
	ExampleSingleton()
	{

	}

public:
	static ExampleSingleton& Instance()
	{
		static ExampleSingleton instance;

		return instance;
	}	// Static applies to the function alone, not the current instance

	void Function()
	{

	}
};		

#define ExampleSingletonInstance ExampleSingleton::Instance()

int _tmain(int argc, _TCHAR* argv[])
{
	ExampleSingletonInstance.Function();


	//GoodName::ExampleClass example;
	//using namespace GoodName;
	//ExampleClass example1;

	GN::ExampleClass blah;

	{
		std::vector<int> intArray;

		intArray.push_back(3);
		intArray.push_back(8);
		intArray.push_back(6);
		intArray.push_back(4);

		//lambda function
		auto displayInt = [](int intValue){
			std::cout << intValue << std::endl;
		};

		displayInt(5);

		std::for_each(intArray.begin(), intArray.end(), displayInt);
	}

	{
		std::string prefix = "----";

		std::vector<int> intArray;

		intArray.push_back(3);
		intArray.push_back(8);
		intArray.push_back(6);
		intArray.push_back(4);

		// If nothing is captured [], the lambda can't see anything outside of itself
		// & is required to allow modification of the captured value
		auto displayInt = [&prefix](int intValue){
			std::cout << prefix << intValue << std::endl;
		};

		std::for_each(intArray.begin(), intArray.end(), displayInt);

	}

	return 0;
}