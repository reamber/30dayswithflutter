//Amber Liu
//al7bf
//stack.h
//09/18/2018

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstdlib>
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"

using namespace std;
class stack{
	public:
		stack();
		void push(int e);
		void pop();
		int top();
		bool empty();
	private:
		List * thestack;
};

#endif