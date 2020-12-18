/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

//trys to open filename, and return its contents in contents
//it will strip out only \n's (char return\line feed)
//returns:
//SUCCESS all worked, contents string contains all in the file
//COULD_NOT_OPEN_FILE_TO_READ contents string is cleared
int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	//TODO fill in

	fstream myInputfile;
	myInputfile.open(filename.c_str());

	if (!myInputfile.is_open()){
		return COULD_NOT_OPEN_FILE_TO_READ;
	}

	string line;
	while (!myInputfile.eof()){
		getline(myInputfile, line);
		contents += line;
	}

	myInputfile.close();
	return SUCCESS;

}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	//TODO fill in

	fstream myOutputfile;
	myOutputfile.open(filename.c_str(), ios_base::out);
	if(!myOutputfile.is_open()){
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}

	for (unsigned int i = 0; i < myEntryVector.size(); i++){
		myOutputfile << myEntryVector[i] << endl;
	}

	myOutputfile.close();
	return SUCCESS;

}


