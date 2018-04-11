//
// Created by Hoang Viet Nguyen.
// Student ID: 101272826
// File: HexDump.cpp
//

#include "HexDump.h"
#include <iomanip>

using namespace std;

bool HexDump::open(const string& aInputFileName) {
	fInput.open(aInputFileName, ios::in | ios::binary); //open file in binary mode
	if (!fInput) {
		cerr << "File cannot be opened: " << aInputFileName << endl; //print error message
		return false; //return false value for this method
	}
	else {
		return true;
	}
}

void HexDump::close() {
	fInput.close(); //close the file
}

void HexDump::processInput() {
	long offset = 0; //the counter variable to indicate hex format of the absolute address of the analysed unit.
					  //run the loop until data is not enough to read by 16 bytes
	do {
		fData.read(fInput); //read the input
							//format the display of this information with hex, setw, setfill. Then print the counter and corresponded data
							//print to the console with cout.
		cout << uppercase << hex << setw(8) << setfill('0') << offset << ":  " << fData << endl;
		offset += 16; //increase the counter
	} while (fData.size() == 16); //loop condition
}

bool HexDump::operator()(const string &aInputFileName) {
	if (open(aInputFileName)) { //take the file name as parameter
		this->processInput(); //call processInput method.
		this->close(); //close the file.
		return true; //return true when the input could be opened
	}
	else {
		return false; //or return false when not.
	}
}