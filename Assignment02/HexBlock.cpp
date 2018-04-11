//
// Created by Hoang Viet Nguyen.
// Student ID: 101272826
// File: HexBlock.cpp
//

#include "HexBlock.h"
#include <iomanip>

using namespace std;

//initialise the variables
HexBlock::HexBlock() : fBuffer{ 0 }, fSize{ 16 } {}

istream& HexBlock::read(istream& aIStream) {
	aIStream.read(reinterpret_cast<char *>(fBuffer), 16); //read into buffer with up to 16 bytes
	fSize = (unsigned long)aIStream.gcount(); //obtain the actual amount when file may not contain enough data anymore
	return aIStream;
}

unsigned long HexBlock::size() const {
	return fSize;
}

ostream& operator<<(std::ostream& aOStream, const HexBlock& aObject) {
	//when data is enough to be read by 16 bytes
	for (unsigned long i = 0; i < aObject.fSize; i++) {
		if (i == 8) {
			aOStream << "| ";
		}
		//formatting the output to be uppercase with 2 hex digits, filling up the first digit with 0
		//and a single blank space after each couple.
		aOStream << uppercase << hex << setw(2) << setfill('0') << (int)aObject.fBuffer[i] << " ";
	}
	//when data is not enough (last line)
	for (unsigned long i = aObject.fSize; i < 16; i++) {
		if (i == 8) {
			aOStream << "  "; //pretend that at index 8, there is an invisible | character.
		}
		aOStream << "   "; //for the rest of, filling up with blank spaces.
	}

	aOStream << "  ";

	for (unsigned long i = 0; i < aObject.fSize; i++) {
		if (isgraph(aObject.fBuffer[i])) { //isgraph function to check if the characters are printable
			aOStream << aObject.fBuffer[i]; //if yes, print them
		}
		else {
			aOStream << "."; //if not, print the dot instead.
		}
	}
	return aOStream;
}