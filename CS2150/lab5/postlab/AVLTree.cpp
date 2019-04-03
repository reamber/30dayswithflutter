//Amber Liu
//al7bf
//10/17/2018
//AVLTree.cpp
#include "AVLTree.h"
#include <iostream>
#include <string>
#include "AVLNode.h"
using namespace std;

AVLTree::AVLTree() { root = NULL; countNodes = 0;}

AVLTree::~AVLTree() {
  delete root;
  root = NULL;
  countNodes = 0;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
  insert(root, x);
}
// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) { root = remove(root, x); countNodes--;}
// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  return pathToHelp(root,x);

}
string AVLTree::pathToHelp(AVLNode* n, const string& x) const{
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
bool AVLTree::find(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  return findHelp(root, x);
}
bool AVLTree::findHelp(AVLNode* n, const string& x) const{
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
int AVLTree::numNodes() const {
  // YOUR IMPLEMENTATION GOES HERE
  return countNodes;
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  if(n == NULL){
    return;
  }
  if(balancefactor(n) > 1){
    if(height(n->left->left) >= height(n->left->right)){
      rotateLeft(n);
    }
    else{
      rotateRight(n->left);
      rotateLeft(n);
    }
  }
  else if(balancefactor(n) < -1){
    if(height(n->right->right)>= height(n->right->left)){
      rotateRight(n);
    }
    else{
      rotateLeft(n->right);
      rotateRight(n);
    }
  }
  n->height = max(height(n->left), height(n->right))+1;
}
int AVLTree::balancefactor(AVLNode*& n) {//gets the balance factor of the tree
  if(n == NULL){
    return 0;
  }
  else{
    return height(n->left) - height(n->right);
  }
}
// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  AVLNode *y = n->left;
  n->left = y->right;
  y->right = n;
  n->height = max(height(n->left), height(n->right))+1;
  y->height = max(height(y->left), n->height)+1;
  n = y;
  return n;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  AVLNode *y = n->right;
  n->right = y->left;
  y->left = n;
  n->height = max(height(n->left), height(n->right))+1;
  y->height = max(height(y->right), n->height)+1;
  n = y;
  return n;
}
// private helper for remove to allow recursion over different nodes. returns
// an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
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
      AVLNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    if (n->right == NULL) {
      AVLNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children -- tree may become unbalanced after deleting n
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);
  return n;
}
AVLNode* AVLTree::insert(AVLNode*& n, const string& x){
  //helper code for insert
  if(root == NULL){
    n = new AVLNode;
    n->value = x;
    root = n;
    countNodes++;
  }
  else if(n == NULL){
    n = new AVLNode;
    n->value = x;
    countNodes++;
  }
  else if (x < n->value){
    insert(n->left, x);
  }
  else if (x > n->value){
    insert(n->right, x);
    }
  n->height = max(height(n->left), height(n->right))+1;
  balance(n);
  return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(AVLNode* node) const {
  if (node == NULL) {
    return -1;
  }
  return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == NULL) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isLeft) {
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

void AVLTree::printTree() { printTree(root, NULL, false); }