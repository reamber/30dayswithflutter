//Amber Liu
//al7bf
//11/26/2018
//huffmanTree.cpp

#include <iostream>
#include "huffmanTree.h"
#include "huffmanNode.h"

using namespace std;

huffmanTree::huffmanTree(){
	root = NULL;
}
heap huffmanTree::createHuffmanTree(heap heap1){
	while(heap1.size >= 2){
    huffmanNode* x = heap1.findMin();
    heap1.deleteMin();
    huffmanNode* y = heap1.findMin();
    heap1.deleteMin();
    huffmanNode* combo = combine(x, y);
    heap1.insert(combo);
  }
  return heap1;
}
huffmanNode* huffmanTree::combine(huffmanNode* n1, huffmanNode* n2) {
  int total = 0;
  total +=  n1->getFreq() + n2->getFreq();
  huffmanNode* retVal = new huffmanNode(total, '1');
  retVal->left = n1; //n1 is smaller so insert left
  retVal->right = n2;
  
  return retVal;
}

void huffmanTree::printPrefix(huffmanNode* root, string code){
	if (root->character == ' '){
    cout << "space" << " " << code << endl;
  }
  	if (root->left == NULL && root->right == NULL && root->character != ' '){
    cout << root->character << " "<< code <<endl;
  }
  	if (root->left){
    printPrefix(root->left, code + "0");
  }
  	if (root->right) {
    printPrefix(root->right, code + "1");
  }
}
void huffmanTree::setPrefix(huffmanNode* root, string code){
	if (root->left == NULL && root->right == NULL){
    root->prefix = code;
  }
  	if (root->right) {
    setPrefix(root->right, code+"1");
  }
  	if (root->left){
    setPrefix(root->left, code+"0");
  }
}
