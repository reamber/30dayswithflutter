//Amber Liu
//al7bf
//10/26/2018
//hashtable.cpp

#include "hashTable.h"
#include <vector>
#include <algorithm>

//constructor
hashTable::hashTable(int size){
 	bucket = new vector<list<string> >;
 	maxWords = 0;
 	size = size + 1;

 	if(!(checkprime(size))){//for resize
 		int newcapacity = getNextPrime(size)*2;//next prime
 		bucket->resize(newcapacity);
 		capacity = newcapacity;//change capacity

 		for(int i = 0;i < newcapacity; i++){
 			list<string> tmp;
 			bucket->push_back(tmp);
 		}
 	}
 }
//destructor
hashTable::~hashTable() {
 	delete bucket;
 }

bool hashTable::contains( const string & str ){
 	list<string>& thelist = bucket->at(hash(str));
 	return(find(thelist.begin(),thelist.end(),str) != (thelist.end()));
 }

bool hashTable::insert(const string & str){
 	 if(!(this->contains(str))){//if it doesn't contain already
		list<string>& thelist = bucket->at(hash(str));
		thelist.push_back(str);
		if(str.length() > maxWords){
			maxWords = str.length();
			return true;
		}
	}
	return false;
}

int hashTable::hash(const string & str){
	// int hashvalue = 1;
	// for(int i = 0; i < str.length(); i++){
	// 	hashvalue += hashvalue + ((int)str[i]);
	// }
	// hashvalue %= capacity;

//////////bad hash//////////////////
	// int hashvalue = 0;
	// for(int i = 0; i<str.length(); i++){
	// 	hashvalue += hashvalue * i;
	// }
	// hashvalue = hashvalue % capacity;

	// int hashvalue = 0;
	// for(int i = 0; i<str.length();i++){
	// 	hashvalue = 3 * str[i] % capacity;
	// }

	// int hashvalue = 1;
	// for(int i = 0; i<str.length();i++){
	// 	hashvalue = 3*hashvalue + str[i];
	// }
	// hashvalue %= capacity;

	// return hashvalue;

	// unsigned int hashvalue = 0;
 //  	for (int i = 0; i < str.length(); i++) {
 //     	hashvalue = (37*hashvalue) + str[i];
 //     }
	// return hashvalue%capacity;
	int hashvalue = 0;
	for(int i = 0; i< str.length(); i++){
		hashvalue = hashvalue + str[i];
	}
	return hashvalue%bucket->size();

}

int hashTable::getNextPrime (unsigned int n){
	while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
bool hashTable::checkprime(unsigned int p){
	if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}