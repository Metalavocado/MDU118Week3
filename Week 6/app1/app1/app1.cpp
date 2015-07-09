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



int _tmain(int argc, _TCHAR* argv[])
{
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