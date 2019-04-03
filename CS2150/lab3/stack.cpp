//Amber Liu
//al7bf
//stack.cpp
//09/18/2018

#include<string>
#include <iostream>
#include <cstdlib>
#include "stack.h"
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
using namespace std;

stack::stack(){
	thestack = new List();
}
void stack::push(int e){
	ListItr topone = thestack->first();//gets the one on the top
	thestack->insertBefore(e,topone);
}
void stack::pop(){
	if(thestack->size() == 0){
		exit(-1);//error message if empty
	}
	else{
		int i = thestack->first().retrieve();//gets the one on the top
		thestack->remove(i);//remove it
	}
}
int stack::top(){
	if(thestack->size() == 0){
		exit(-1);
	}
	else{
		return thestack->first().retrieve();
	}
}
bool stack::empty(){
	if(thestack->size() == 0){
		return true;
	}
	else{
		return false;
	}
}


