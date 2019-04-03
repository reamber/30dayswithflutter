//Amber Liu
//al7bf
//postfixCalculator.h
//09/15/2018

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include <iostream>
#include "stack.h"

using namespace std;

class postfixCalculator{
	public:
		postfixCalculator();
		void pushnum(int e);
		int gettop();
		// void pop();
		// bool empty();
		void add();
		void subtract();
		void multiply();
		void divide();
		void negate();
	private:
		stack * astack;
};

#endif
