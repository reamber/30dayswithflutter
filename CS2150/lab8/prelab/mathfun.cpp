//Amber Liu
//al7bf
//11/05/2018
//mathfun.cpp


#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);

int main(){
	int x;
	int y;
	int productAns;
	int powerAns;

	cout << "enter a integer: " << endl;
	cin >> x;
	cout << "enter another integer: " << endl;
	cin >> y;

	productAns = product(x, y);
	cout << "product of the two numbers are: " << productAns << endl;
	powerAns = power(x, y);
	cout << "x to the power of y is:  " << powerAns << endl;

	return 0;
}