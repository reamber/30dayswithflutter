//Amber Liu
//al7bf
//10/21/2018
//hashtable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <algorithm>
#include<list>

using namespace std;

class hashTable{
	public:
		hashTable(int size);
	    ~hashTable();
	    bool contains( const string & str );
	    bool insert( const string & str );
	    int hash( const string & str );
	    bool checkprime( unsigned int p );
	    int getNextPrime( unsigned int n );
	    int maxWords; 
	    int capacity; 
	private: 
		vector<list <string> > *bucket;
};

#endif