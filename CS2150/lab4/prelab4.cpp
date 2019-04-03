//Amber Liu
//al7bf
//prelab4.cpp
//09/22/2018

#include <climits>
#include <cfloat>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

// void sizeOfTest(){
// 	cout << "int size " << sizeof(int) << endl;
// 	cout << "unsigned int size " << sizeof(unsigned int) << endl;
// 	cout << "double size " << sizeof(double) << endl;
// 	cout << "bool size " << sizeof(bool) << endl;
// 	cout << "int* size " << sizeof(int*) << endl;
// 	cout << "char* size " << sizeof(char*) << endl;
// 	cout << "double* size " << sizeof(double*) << endl;

// }

// void outputBinary(unsigned int x){
// 	string answer;

// 	for(int i = 31; i >= 0; i--){

// 		if((i+1)%4 == 0){ //space after every four
// 			answer = answer + " ";
// 		}
// 		if( x & (1 << i)){
// 			answer += "1";
// 	    }
// 	    else{
// 	    	answer += "0"; 
// 	    }	    
// 	}
// 	cout << answer << endl;
  	
// }

// void overflow(){
// 	unsigned int y = UINT_MAX + 1;//max of the unsigned int plus 1
// 	cout << "Max value of unsigned int + 1 = " << y << endl; //the out put is 0
// 	//the program did not halt, and i got an output of 0. Unsigned integers do not overflow, instead of creating 33 bit which is nonexistent, it just defaults to 0
// }
// int main(){
// 	int x = 0;
// 	cout << "enter an integer: " << endl;
// 	cin >> x;
// 	sizeOfTest();
// 	outputBinary(x);
// 	overflow();
//   	return 0;
int main ( ){
	int IntArray[3];
	IntArray[7] = 3;
	return 0 ;
}