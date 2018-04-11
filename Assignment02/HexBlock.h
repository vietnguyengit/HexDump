//
// Created by Viet Nguyen on 4/7/18.
//

#ifndef ASSIGNMENT02_HEXBLOCK_H
#define ASSIGNMENT02_HEXBLOCK_H

#include <iostream>

class HexBlock {
private:
	unsigned char fBuffer[16];
	unsigned long fSize;
public:
	HexBlock();

	std::istream& read(std::istream& aIStream);

	unsigned long size() const;

	friend std::ostream& operator<<(std::ostream& aOStream, const HexBlock& aObject);
};

#endif //ASSIGNMENT02_HEXBLOCK_H
