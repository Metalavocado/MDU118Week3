// InClassApp2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef std::string string;

typedef struct MeshInfo
{
	MeshInfo(const std::string& _name = "", int _numVerts = 0, int _numTris = 0, float _scale = 0)
	{
		name = _name;
		numVerts = _numVerts;
		numTris = _numTris;
		scale = _scale;
	}

	std::string name;
	int numVerts;
	int numTris;
	float scale;

};


typedef std::vector<MeshInfo> MeshInfos;

std::ostream& operator << (std::ostream& os, const MeshInfo& meshInfo)
{
	return os	<< meshInfo.name << ","
				<< meshInfo.numVerts << ","
				<< meshInfo.numTris << ","
				<< meshInfo.scale;
}

int _tmain(int argc, _TCHAR* argv[])
{
	MeshInfos meshSet1;
	{
		meshSet1.push_back(MeshInfo("a", 1, 2, 1.2f));
		meshSet1.push_back(MeshInfo("b", 8, 3, 3.6f));
		meshSet1.push_back(MeshInfo("c", 4, 2, 3.2f));
		meshSet1.push_back(MeshInfo("d", 5, 1, 1.4f));

		{
			std::ofstream meshCSV("mesh.csv", std::ios::app);

			for (MeshInfos::iterator meshIt = meshSet1.begin(); meshIt != meshSet1.end(); ++meshIt)
			{
				MeshInfo& meshInfo = *meshIt;

				meshCSV << meshInfo << std::endl;
			}
		}


		{																													//Saving in Binary
			std::ofstream meshBinary("mesh.bin", std::ios::binary);

			for (MeshInfos::iterator meshIt = meshSet1.begin(); meshIt != meshSet1.end(); ++meshIt)
			{
				MeshInfo& meshInfo = *meshIt;

				size_t nameSize = meshInfo.name.size();
				meshBinary.write(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));										//Adding the size of the string allows for easier identification and use etc.
				meshBinary.write(meshInfo.name.c_str(), meshInfo.name.size);

				meshBinary.write(reinterpret_cast<char*>(&meshInfo.numTris), sizeof(meshInfo.numTris));						//requires casting, reinterpret_cast does no safety/sanity checking, it will cast it anyway
				meshBinary.write(reinterpret_cast<char*>(&meshInfo.numVerts), sizeof(meshInfo.numVerts));
				meshBinary.write(reinterpret_cast<char*>(&meshInfo.scale), sizeof(meshInfo.scale));

			}

		}

		{
			std::ifstream meshBinary("mesh.bin", std::ios::binary);

			MeshInfo meshInfo;

			size_t nameSize;

			meshBinary.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));

			char* nameData = new char[nameSize + 1];
			meshBinary.read(nameData, nameSize);
			nameData[nameSize] = '\0';
			meshInfo.name = std::string(nameData);

			meshBinary.read(reinterpret_cast<char*>(&meshInfo.numTris), sizeof(meshInfo.numTris));
			meshBinary.read(reinterpret_cast<char*>(&meshInfo.numVerts), sizeof(meshInfo.numVerts));
			meshBinary.read(reinterpret_cast<char*>(&meshInfo.scale), sizeof(meshInfo.scale));


		}

	}
	
	
	return 0;
}

