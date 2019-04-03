//Amber Liu
//al7bf
//11/18/2018
//threexinput.cpp

#include<iostream>
#include <cstdlib>
#include "timer.h"

using namespace std;
extern "C" long threexplusone (long);

int main(){
	int input;
	cout << "enter a number: " << endl;
	cin >> input;

	int num;
	cout << "enter number of times to run: " << endl;
	cin >> num;

	timer totaltimer;
	totaltimer.start();
	for(int i = 0; i<num;i++){
		threexplusone(input);
	}
	totaltimer.stop();

	cout<< "Average time was: "<< totaltimer.getTime()*1000/num << endl;
	cout << "total steps is: " << threexplusone(input) << endl;

	return 0;
}