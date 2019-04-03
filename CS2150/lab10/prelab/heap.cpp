//Amber Liu
//al7bf
//11/26/2018
//heap.cpp
#include <iostream>
#include "heap.h"
#include "huffmanNode.h"
//referenced Bloomfield's 2014 binary_heap.cpp code

using namespace std;

heap::heap():size(0), heap1(101){
}
void heap::insert(huffmanNode* n){
	while(size == heap1.size()-1){
		heap1.resize(heap1.size() * 2);
	}
	percolateup(++size,n);
}
void heap::percolateup(int hole, huffmanNode* n){
	for(; (hole>1) && (*n < *heap1[hole/2]); hole/=2) {
    	heap1[hole] = heap1[hole/2];
    }
  heap1[hole] = n;
}

void heap::deleteMin(){
	if(size == 0){
		cout << "ERROR! Heap is empty" << endl;
	}

	heap1[1] = heap1[size--];
	heap1.pop_back();
	percolatedown(1);
}
void heap::percolatedown(int hole){
	huffmanNode* tmp = heap1[hole];
	while(hole*2 <= size){
		int child = hole*2;
		if((child + 1 <= size) && (heap1[child+1] < heap1[child]) ){
			child++;
		}
		if((*heap1[child])<(*tmp)){
			heap1[hole] = heap1[child];
			hole = child;
		}
		else{
			break;
		}
	}
	heap1[hole] = tmp;
}
huffmanNode* heap::findMin() const{
	if ( size == 0 ){
        throw " empty heap";
  }
    return heap1[1];
}
vector<huffmanNode*> heap::getVector(){
  return heap1;
}