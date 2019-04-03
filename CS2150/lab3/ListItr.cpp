//Amber Liu
//al7bf
//ListItr.cpp
//09/08/2018
//description: methods that are implemented in listIte header file
#include <iostream>
#include "ListItr.h"
using namespace std;

//default constructor
ListItr::ListItr(){
	current = new ListNode();
}

ListItr::ListItr(ListNode* theNode){
	current = theNode;
}
//Returns true if the iterator is currently pointing past the end 
bool ListItr::isPastEnd() const{
	if(current->next == NULL){
		return true;
	}
	else{
		return false;
	}
}
//Returns true if the iterator is currently pointing before the first position
bool ListItr::isPastBeginning() const{
	if(current->previous == NULL){
		return true;
	}
	else{
		return false;
	}
}
//Advances the current pointer to the next position in the list, unless already past end
void ListItr::moveForward(){
	if(!isPastEnd()){
		current = current->next;
	}
}
//Move current back to the previous position in the list (unless already past the beginning of the list
void ListItr::moveBackward(){
	if(!isPastBeginning()){
		current = current->previous;
	}
}

//Returns item in current position
int ListItr::retrieve() const{
	return current->value;
}


