//Amber Liu
//al7bf
//11/27/2018
//huffmandec.cpp

//modified inlab-skeletop.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "huffmanNode.h"
using namespace std;

void createTree(huffmanNode*& node, string prefix, char c){
	if(prefix.length() == 0){
		node->character = c;
	}
	if (prefix[0] == '0' && node->left==NULL){
    	node->left = new huffmanNode(0, '\0');
    }
    if (prefix[0] == '1' && node->right == NULL){
    	node->right = new huffmanNode(0, '\0');
    }
    if (prefix[0] == '0'){
    	createTree(node->left, prefix.substr(1, prefix.length()-1), c);
    }
    if (prefix[0] == '1'){
    	createTree(node->right, prefix.substr(1, prefix.length()-1), c);
    }
}
// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in the first section of the file: the prefix codes
    char ascii[256];
    huffmanNode *n1 = new huffmanNode(0, '\0');
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        prefix = string(ascii);
        file >> prefix;
        createTree(n1, prefix, character[0]);
        // do something with the prefix code
        // cout << "character '" << character << "' has prefix code '"
        //      << prefix << "'" << endl;
    }
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
       
        sstm << bits;
    }
    string allbits = sstm.str();
    char bit;
    huffmanNode* current = n1;
    for (int i = 0; i < allbits.length(); i++){
    	bit = allbits.at(i);
    	if ((bit!= '0') && (bit!='1')){
        	continue;
        }
        if (current->left != NULL && bit == '0'){
        	current = current->left;
        }
        if (current->right != NULL && bit =='1') {
        	current = current->right;
        }
        if (current->left == NULL && current->right == NULL){
        	cout << current->getChar();
        	current = n1;
        }
    }
    cout << endl;
    //string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
   // cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();
}
