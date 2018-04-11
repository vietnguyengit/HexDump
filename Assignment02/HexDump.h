//
// Created by Viet Nguyen on 4/7/18.
//

#ifndef ASSIGNMENT02_HEXDUMP_H
#define ASSIGNMENT02_HEXDUMP_H

#include <fstream>
#include <string>
#include "HexBlock.h"

class HexDump {
private:
	HexBlock fData;
	std::ifstream fInput;
public:
	bool open(const std::string& aInputFileName);

	void close();

	void processInput();

	bool operator()(const std::string& aInputFileName);
};

#endif //ASSIGNMENT02_HEXDUMP_H
