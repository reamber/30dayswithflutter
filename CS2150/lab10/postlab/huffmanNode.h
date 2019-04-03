//Amber Liu
//al7bf
//11/26/2018
//huffmanNode.h

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>
#include <iostream>
using namespace std;

class huffmanNode {
public:
	huffmanNode(int f, char c);
	huffmanNode *left;
	huffmanNode *right;
	int freq;
	char character;
	string prefix;
	unsigned int getFreq() const;
	char getChar();
	string getPrefix();
	bool operator<(const huffmanNode& n) const;
};
#endif
