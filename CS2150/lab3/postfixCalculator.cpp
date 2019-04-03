//Amber Liu
//al7bf
//postfixCalculator.cpp
//09/15/2018

#include <iostream>
#include <cstdlib>
#include "postfixCalculator.h"
#include "stack.h"
using namespace std;

postfixCalculator::postfixCalculator(){
	astack = new stack();
}
void postfixCalculator::pushnum(int e){
    astack->push(e);
}
int postfixCalculator::gettop(){
    if(astack->empty()){
        exit(-1);
    }
    else{
        return astack->top();
    }
}
void postfixCalculator::add(){
	int first = astack->top();//num of top one
	astack->pop();//get rid of top one
	int second = astack->top();//num of top two
	astack->pop();//get rid of the top two
	astack->push(first+second);//add the top two together
}
void postfixCalculator::subtract(){
	int first = astack->top();//num of top one
	astack->pop();//get rid of top one
	int second = astack->top();//num of top two
	astack->pop();//get rid of the top two
	astack->push(second-first);//subtract the two, lower value in the stack minus higher
}
void postfixCalculator::multiply(){
	int first = astack->top();//num of top one
	astack->pop();//get rid of top one
	int second = astack->top();//num of top two
	astack->pop();//get rid of the top two
	astack->push(first*second);//multiply
}
void postfixCalculator::divide(){
	int first = astack->top();//num of 
	astack->pop();//get rid of top one
	int second = astack->top();//num of top two
	astack->pop();//get rid of the top two
	astack->push(second/first);//divide, lower value in the stack divide by higher
}
void postfixCalculator::negate(){
	int first = astack->top();//num of top one
	astack->pop();//get rid of top one
	astack->push(first*-1);//negate
}



