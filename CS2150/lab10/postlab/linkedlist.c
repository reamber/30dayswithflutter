//Amber Liu
//al7bf
//11/29/2018
//linkedlist.c

#include <stdio.h>
struct listnode {
	int value;
	struct listnode *next;
};
int main(){
	//struct listnode* node = NULL; 
	int count = 0;
	printf("Enter number of values to input: ");
	scanf("%d", &count);
	struct listnode* result[count];
	int input[count];
	//enter value
	for(int i = 0; i < count; i++){
		printf("Enter value: ");
    	scanf("%d", &input[i]);
	}
	//allocating values to node
	for(int j = 0; j < count; j++){
		struct listnode* node = malloc(sizeof(struct listnode));
		node->value = input[j];
	    node->next = NULL;
	    result[j] = node;
	}
	//printing out linked list
	for(int x = 0; x<count; x++){
    	printf("%d\n", result[x]->value);
    }
    //deallocate
    for(int y = 0; y < count; y++){
    	free(result[y]);
    }
return 0;

}