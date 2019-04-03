//Amber Liu
//al7bf
//11/26/2018
//heap.h

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <string>
#include "huffmanNode.h"

using namespace std;

class heap{
public:
	heap();
	void insert(huffmanNode* n);
	void percolateup(int hole, huffmanNode* n);
	void deleteMin();
	void percolatedown(int hole);
	huffmanNode* findMin() const;
	unsigned int size;
	void print();
	void printTree(huffmanNode* root);
	vector<huffmanNode*> heap1;
	vector<huffmanNode*> getVector();
};
#endif