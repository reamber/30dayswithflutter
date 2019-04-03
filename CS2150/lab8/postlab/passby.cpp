#include <iostream>
#include <cstdlib>

using namespace std;

// int passByRef(int &x, int&y){
// 	return (x * y);
// }

int passByVal(int x, int y){
	return (x + y);
}

int main(){
	// int a = 2;
	// int b = 3;
	// int refans = passByRef(a, b);
	// cout << refans << endl;

	int c = 1;
	int d = 8;
	int valans = passByVal(c, d);
	cout << valans << endl;
	return 0;
}