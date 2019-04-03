//Amber Liu
//al7bf
//10/16/2018
//binarysearchtree.cpp
#include "BinarySearchTree.h"
#include <string>
#include "BinaryNode.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree() { root = NULL; countNodes = 0;}

BinarySearchTree::~BinarySearchTree() {
  delete root;
  root = NULL;
  countNodes = 0;
}
// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
  insert(root,x);
  //countNodes++;
}
// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) { root = remove(root, x); countNodes--;}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  return pathToHelp(root,x);
}
//pathto helper
string BinarySearchTree::pathToHelp(BinaryNode* n, const string& x) const{
  string result = "";
  if(find(x)){//if x does exist
    if(n == NULL){
      return result;
    }
    if(x == n->value){//if x is the value, then print value
      result += x + " ";
    }
    else if(x < n->value){//if less than, then on left
      result += n->value + " ";
      return result + pathToHelp(n->left, x);
    }
    else if (x > n->value){//if more than, then on right
      result += n->value + " ";
      return result + pathToHelp(n->right, x);
    }
  }
  else{//if does not exist, then return empty string
    return result;
  }
  return result;//return the aggregated string
}
// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  return findHelp(root, x);
}
//helper method for find
bool BinarySearchTree::findHelp(BinaryNode* n, const string& x) const{
  if(n == NULL){
    return false;
  }
  else if(x == n->value){
    return true;
  }
  else if(x < n->value){
    return findHelp(n->left, x);
  }
  else if(x > n->value){
    return findHelp(n->right, x);
  }
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
  // YOUR IMPLEMENTATION GOES HERE
  return countNodes;
}
//helper
// int BinarySearchTree::countNodes(BinaryNode* n) const {
//   int count = 0;
//   if(n == NULL){
//     count = 0;
//   }
//   else{
//     count += 1 + countNodes(root->left) + countNodes(root->right);
//   }
//   return count;
// }
// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      delete n;
      n = NULL;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      BinaryNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    if (n->right == NULL) {
      BinaryNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  return n;
}
//added helper to insert
BinaryNode* BinarySearchTree::insert(BinaryNode*& n, const string& x) {
  if(root == NULL){
    n = new BinaryNode;
    n->value = x;
    root = n;
    countNodes++;
  }
  else if(n == NULL){
    n = new BinaryNode;
    n->value = x;
    countNodes++;
  }
  else if(x < n->value){
    n->left = insert(n->left, x);
  }
  else if(x > n->value){
    n->right = insert(n->right, x);
  }
  return n;
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == NULL) return;
  showTrunks(p->prev);
  cout << p->str;
}
// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isLeft) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->left, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isLeft) {
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->value << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->right, trunk, false);
}

void BinarySearchTree::printTree() { printTree(root, NULL, false); }