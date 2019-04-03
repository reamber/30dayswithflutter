//Amber Liu
//al7bf
//bitCounter.cpp
//09/27/2018

#include<climits>
#include<string>
#include <iostream>
#include <cstdlib>
#include <math.h>


using namespace std;

int bitCounter(int n){
	if(n == 0){
		return 0;
	}
	if (n == 1){ 
		return 1;
	}
	if(n%2 == 0){//if n is even, the number of 1's in the representation of n is the same as that in n/2
		return bitCounter(n/2);
	}
	else if(n%2 == 1){//if n is odd, the number of 1's is the same as that in floor(n/2) plus 1.
		return bitCounter(floor(n/2)) + 1;
	}
}

int main (int argc, char **argv){
	if(argc == 0){
		cout << "error: problem with input" << endl; //"gracefully exit"?
	}
	else{
		for (int i = 0; i < argc; i++) {
			int x = atoi(argv[i]);
			cout << "bitCounter result: " << bitCounter(x) << endl;
		}
  
    }
	return 0;
}