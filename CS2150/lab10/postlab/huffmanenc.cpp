//Amber Liu
//al7bf
//11/26/2018
//huffmanenc.cpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "heap.h"
#include "huffmanTree.h"
#include "huffmanNode.h"

using namespace std;
//referenced fileio.cpp

int main (int argc, char **argv) {
	if(argc != 2){
		cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");

    if(fp == NULL){
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }

    int freq[128];
    for(int i=0;i<128;i++){
      freq[i]=0;
    } 
    //While we have not hit end of file, incease num
    char g;
    int ascii;
    int numLetters = 0;
    while ((g = fgetc(fp)) != EOF ){
        ascii =(int) g; //cast char to int 
        if(ascii < 128 && ascii > 31){ //range desired 
    		freq[ascii]++;
            numLetters++;
      }
    }
    //Inserting characters into the heap 
    int diffChars = 0;
    heap h1;
    for(int i = 1;i < 128; i++){
        if(freq[i] > 0){
            diffChars++;
            huffmanNode* tmp = new huffmanNode(freq[i],(char) i);
    		h1.insert(tmp);
        }
    }
    //print prefix 
    huffmanTree* newtree = new huffmanTree();
    heap newheap = newtree -> createHuffmanTree(h1);
    newtree->printPrefix(newheap.findMin(),"");
    
    //separator 
cout << "----------------------------------------" << endl;
    newtree->setPrefix(newheap.findMin(),"");
    rewind(fp);

    //Calculating compressed value
    vector<huffmanNode*> v1 = h1.getVector();
    int compressed = 0; 
    while ((g = fgetc(fp)) != EOF ){
      for(int i = 1; i <= h1.size; i++){
          if(g == v1[i]->getChar()){
		    cout << v1[i]->getPrefix() << " ";
		    compressed += v1[i]->getPrefix().size();
		}
      }
    }
    cout << endl;
cout << "----------------------------------------" << endl;
// results!
     int uncompressed = numLetters*8;
     double ratio = (double) uncompressed/compressed;
     double cost = (double) compressed/numLetters;
     cout<<"There are a total of " << numLetters << " symbols that are encoded." << endl;
     cout<<"There are " << diffChars << " distinct symbols used." << endl;
     cout<<"There were " << uncompressed << " bits in the original file." << endl;
     cout<<"There were " << compressed << " bits in the compressed file." << endl;
     cout<<"This gives a compression ratio of "<< ratio <<"." << endl;
     cout<<"The cost of the Huffman Tree is "<< cost <<" bits per character." << endl;
    
     fclose(fp);
     return 0;
 }


