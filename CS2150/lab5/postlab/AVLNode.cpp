//Amber Liu
//al7bf
//10/17/2018
//AVLNode.cpp
#include "AVLNode.h"
#include <string>
using namespace std;

AVLNode::AVLNode() {
  value = "?";
  left = NULL;
  right = NULL;
  height = 0;
}

AVLNode::~AVLNode() {
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}