//Amber Liu
//al7bf
//testPostfixCalc.cpp
//09/15/2018
#include<string>
#include <iostream>
//#include <stack>
#include <cstdlib>
#include "postfixCalculator.h"
#include "stack.h"
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

int main() {
	//use isdigit or atoi
	//atoi works on array of characters
	//c_str()
    cout << "enter values and operators, hit enter and then control + d to get result" << endl;
    postfixCalculator p;
    string s;
    while (cin >> s) {
    	if(s == ""){ //if empty then break
    		break;
    	}
    	const char* input = s.c_str();//convert string to character

    	if(isdigit(input[0])){//if the input is a number
    		int a = atoi(input);//change char to int
    		p.pushnum(a);//push into stack
    	}
    	if(s == "+"){
    		p.add();
    	}
    	if(s == "-"){
    		p.subtract();
    	}
    	if(s[0] == '-' && s.length()>1){//if starts with -, but is not subtraction
    		int a = atoi(input);//negative number
    		p.pushnum(a);//push negative number
    	}
    	if(s == "*"){
    		p.multiply();
    	}
    	if(s == "/"){
    		p.divide();
    	}
    	if(s == "~"){
    		p.negate();
    	}

    }

    cout << p.gettop()<<endl;


	 
	// p.pushnum(1);
	// p.pushnum(2);
	// p.pushnum(3);
	// p.pushnum(4);
	// p.pushnum(5);
	// p.add();
	// p.add();
	// p.add();
	// p.add();
	// cout << "Result of adding is: " << p.gettop() << endl;
    
	// postfixCalculator p1;
	// p1.pushnum(1);
	// p1.pushnum(2);
	// p1.pushnum(3);
	// p1.subtract();
	// p1.subtract();
	// cout << "Result of subtracting is: " << p1.gettop() << endl;

	// postfixCalculator p2;
	// p2.pushnum(1);
	// p2.pushnum(2);
	// p2.pushnum(3);
	// p2.multiply();
	// p2.multiply();
	// cout << "Result of multiplying is: " << p2.gettop() << endl;

	// postfixCalculator p3;
	// p3.pushnum(4);
	// p3.pushnum(3);
	// p3.pushnum(2);
	// p3.divide();
	// p3.divide();
	// cout << "Result of division is: " << p3.gettop() << endl;

	// postfixCalculator p4;
	// p4.pushnum(-5);
	// p4.pushnum(2);
	// p4.negate();
	// cout << "Result of negation is: " << p4.gettop() << endl;

	return 0;
}
