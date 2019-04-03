//Amber Liu
//al7bf
//11/26/2018
//huffmanNode.cpp
#include <iostream>
#include "huffmanNode.h"

using namespace std;

//Constructor 
huffmanNode::huffmanNode(int f, char c){
  freq  = f;
  character = c;
  prefix = "";
  left = NULL;
  right = NULL;
}

//getFreq
unsigned int huffmanNode::getFreq() const{
  return freq;
}

//getChar
char huffmanNode::getChar(){
  return character;
}

//getPrefix
string huffmanNode::getPrefix(){
  return prefix;
}

//override < operator
bool huffmanNode::operator<(const huffmanNode& n) const{
  return(this->getFreq() < n.getFreq());
}