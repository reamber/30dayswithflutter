//Amber Liu
//al7bf
//inlab4.cpp
//09/25/2018

#include<climits>
#include<string>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	 int a = 0;
	double b = 0.0;
	char c = 'a';
	bool d = false;
	unsigned int e = 0;
	float f = 2;

	 int* g = NULL;
	 double* xi = NULL;

	// // int y = 1;
	// // double y1 = 1.0;
	// // char y2 = '1';
	// // bool y3 = true;
	// // unsigned int y4 = 1;
	// // float y5 = 1;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;
	cout << g << endl;
	cout << xi << endl;

	// cout << "The value stored in the bool is : " << x << endl;
	// cout << "The value stored in the char is : " << y << endl;
	// cout << "The value stored in the int is : " << z << endl;
	// cout << "The value stored in the double is : " << a << endl;
	// cout << "The value stored in the int* is : " << b << endl;

	//cout<< INT_MAX <<endl;
	//cout<< DBL_MAX <<endl;
	//cout<< FLT_MAX <<endl;
	
	// for(int i = 0; i < 10; i++){
	// 	IntArray[i]=i;
	// }
	int IntArray[10] = {0,1,2,3,4,5,6,7,8,9};
	char CharArray[10] = {'a','m','b','e','r','l','i','u','x','z'};

	int IntArray2D[6][5] = {{10,11,12,13,14}, {15,16,17,18,19},{20,21,22,23,24},{25,26,27,28,29},{30,31,32,33,34},{35,36,37,38,39}};
	char CharArray2D[6][5] = {{'h','i','j','k','l'},{'p','q','r','s','t'},{'u','v','w','m','n'},{'o','A','B','C','D'},{'E','F','G','H','I'},{'J','K','L','M','N'}};
	//cout << sizeof(IntArray2D[6][5]) << endl;
	return 0;
}