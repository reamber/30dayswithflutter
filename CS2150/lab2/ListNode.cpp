//Amber Liu
//al7bf
//ListNode.cpp
//09/07/2018
//description: class implementation for ListNode
#include <iostream>
#include "ListNode.h"
using namespace std;

//default constructor
ListNode::ListNode(){
	value = 0;
	next = NULL; //for doubly linked lists
	previous = NULL;
}

