//Amber Liu
//al7bf
//List.cpp
//09/07/2018
//description: the methods to implement for List
#include <iostream>
#include "List.h"
using namespace std;

//default constructor
List::List(){
	count = 0;
	head = new ListNode();
	tail = new ListNode();
  	head-> next = tail;
  	tail-> previous = head;
  	tail->next = NULL;
}

//the provided copy constructor
List::List(const List& source){
	head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}
//destructor
List::~List(){
	makeEmpty();
	delete head;
	delete tail;
}
//the provided copy assignment operator
List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

//Returns true if empty; else then false
bool List::isEmpty() const{
	if(head->next == NULL){
		return true;
	}
	else{
		return false;
	}
}

//Removes all items except blank head and tail
void List::makeEmpty(){
	ListItr tmp = head->next;//the next node after head
 	while (!tmp.isPastEnd()){
 		delete tmp.current;
 		tmp.moveForward();
 	}
 	count = 0;
}
//element after the head ListNode
ListItr List::first(){
	ListItr after;
	after = head->next;
	return after;
}
//element before the tail ListNode
ListItr List::last(){
	ListItr before;
	before = tail->previous;
	return before;
}
//inserts x after the current iterator position position
void List::insertAfter(int x, ListItr position){
	ListNode * tmp = new ListNode;//new node
	tmp->value = x;//put in data
	///////the above is ok////////
	tmp->next = position.current->next;//the next node of tmp is the next node of current position
 	position.current->next = tmp;//the next node of current position is tmp
 	position.current->next->previous = tmp; 
	count++;//increase count after adding node
}
void List::insertBefore(int x, ListItr position){
	ListNode * tmp = new ListNode;//new node
	tmp->value = x;//put in data
	///////the above is ok////////
	tmp->next = position.current; //the next node of tmp is current position
	tmp->previous = position.current->previous;//the previous node of current position is the new node
	position.current->previous->next = tmp; //reestablish the relationship
	position.current->previous = tmp; //the node before current is the new node
	count++; 
}
//inserts x at tail of list
//use insert before tail?
void List::insertAtTail(int x){
	insertBefore(x, ListItr(tail));
	//Mark Floryan's solution he talked about in class
	//listNode * newNode = new ListNode();
	//newNode->value = x;
	//listnode *prev = tail->previous;
	//prev->next = newNode;
	//tail->previous = newNode;
	//newNode->previous = prev;
	//newNode->next = tail;
}
//Removes the first occurrence of x 
void List::remove(int x){
	ListNode * tmp = head->next;
	while(tmp != NULL){
		if(tmp->value == x){
			tmp->previous->next = tmp->next;
			tmp->next->previous = tmp->previous;
			count--;
			delete tmp;
			break;
		}
		else{
			tmp = tmp->next;
		}
	}
}
//find element 
//When the parameter is not in the list, return a ListItr object, where the current pointer points to the dummy tail node
ListItr List::find(int x){
	ListItr location = ListItr(head);
  	while (!location.isPastEnd()){
	    if (location.current->value == x){
	      return location;
	    }
	    else{
	    	location.moveForward();
	    }
	}
	location = ListItr(tail);
	return location;//not in the list, return a listItr object, point to Null
}

int List::size() const{
	return count;
}
//check over this
void printList(List& source, bool direction){
	ListItr itr1= source.first();
  	ListItr itr2= source.last();
  	if (direction == true){
  		while(!itr1.isPastEnd()){
  			cout << itr1.retrieve() << endl;
  			itr1.moveForward();
  		}
   }
    else{
    	while(!itr2.isPastBeginning()){
    		cout << itr2.retrieve() << endl;
    		itr2.moveBackward();
    	}
    }
}


