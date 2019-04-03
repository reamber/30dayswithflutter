//Amber Liu
//al7bf
//11/26/2018
//huffmanTree.h

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include "huffmanNode.h"
#include "heap.h"

using namespace std;
class huffmanTree{
public:
	huffmanTree();
	heap createHuffmanTree(heap heap1);
	void printPrefix(huffmanNode* root, string code);
	void setPrefix(huffmanNode* root, string code);
	huffmanNode* combine(huffmanNode* n1, huffmanNode* n2);
	huffmanNode *root;
};

#endif