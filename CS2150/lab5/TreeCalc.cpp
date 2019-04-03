// Insert your header information here
//Amber Liu
//al7bf
//10/11/2018
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
    mystack = stack<TreeNode*>();
}
//Destructor- frees memory
TreeCalc::~TreeCalc() {
    if(!mystack.empty()){
        cleanTree(mystack.top());
        mystack.pop();
    }
}
//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
    if(ptr->left != NULL){
        cleanTree(ptr->left);
        cleanTree(ptr->right);
    }
    else{
        delete ptr;
    }
}
//Gets data from user
//DO NOT ALTER
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    if(val == "+" || val == "-" || val == "*" || val == "/"){//if operator, pop 2 nodes
        TreeNode *x = new TreeNode(val);
        x->right = mystack.top();
        mystack.pop();
        x->left = mystack.top();
        mystack.pop();
        mystack.push(x);
    }
    else{//if just a number, just insert
        TreeNode *y = new TreeNode(val);
        mystack.push(y);
    }
}

//Prints data in prefix form
//node first, then children
void TreeCalc::printPrefix(TreeNode* ptr) const {
    // print the tree in prefix format
    if(ptr->left == NULL || ptr->right == NULL){//other treenodes are null
        cout << ptr->value; //current node
    }
    else{
        cout << ptr->value << " ";
        printPrefix(ptr->left);//iterate through other nodes, left first
        cout << " ";
        printPrefix(ptr->right);
    }
}

//Prints data in infix form
//left node first, then self, then right
void TreeCalc::printInfix(TreeNode* ptr) const {
    // print tree in infix format with appropriate parentheses
    if(ptr->left == NULL){
        cout << ptr->value;
    }
    else if(ptr -> value == "+" || ptr -> value == "-" || ptr -> value == "*" || ptr -> value == "/"){
      cout << "("; //()
      printInfix(ptr->left);
      cout << " " << ptr->value << " ";
      printInfix(ptr->right);
      cout << ")";
  }
}

//Prints data in postfix form
//children first, then node
void TreeCalc::printPostfix(TreeNode* ptr) const {
    // print the tree in postfix form
    if(ptr->left == NULL || ptr->right == NULL){
        cout << ptr->value;
    }
    else{
        printPostfix(ptr->left);
        cout << " ";
        printPostfix(ptr->right);
        cout << " " << ptr->value;
    }
}
// Prints tree in all 3 (pre,in,post) forms
void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        // call your implementation of printPostfix()
        printPostfix(mystack.top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
        printInfix(mystack.top());
        // call your implementation of printInfix()
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        printPrefix(mystack.top());
        // call your implementation of printPrefix()
        cout << endl;
    } else{
        cout<< "Size is 0." << endl;
    }
}
//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
    // Traverse the tree and calculates the result
    int count = 0;
    if(ptr -> right == NULL || ptr->left == NULL){
        count = atoi((ptr->value).c_str());
        return count;
    }
    else if(ptr->value =="+"){
        count = calculate(ptr->left)+calculate(ptr->right);
        return count;
    }
    else if(ptr->value =="-"){
        count = calculate(ptr->left)-calculate(ptr->right);
        return count;
    }
    else if(ptr->value =="*"){
        count = calculate(ptr->left)*calculate(ptr->right);
        return count;
    }
    else if(ptr->value =="/"){
        count = calculate(ptr->left)/calculate(ptr->right);
        return count;
    }

}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate(){
    int i = 0;
    // call private calculate method here
    while(
        mystack.size() != 0){//while not empty
        i = i+calculate(mystack.top());
        mystack.pop();
    }
    return i;
}
