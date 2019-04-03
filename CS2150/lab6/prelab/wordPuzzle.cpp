//Amber Liu
//al7bf
//10/21/2018
//wordPuzzle.cpp

#include <iostream>
#include<cstdlib>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "hashTable.h"
#include "timer.h"
using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];
timer t;

bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len, int numRows, int numCols);

int main( int argc, char* argv[] ){

  while(true){
    if( argc < 3 ){ //If arguments entered is less than 3, not a valid input
      cout << "Error" << endl;
      break;
    }
    //dictionary file 
    string dFile = argv[1];
    string temp;
    int numline = 0;
    ifstream dict( dFile.c_str() );

    while( getline (dict, temp) ){
      numline++;
    }
    dict.close();

    hashTable *thetable = new hashTable( numline );
    string current; 
    dict.open( dFile.c_str());
    while(dict.good()){
      getline(dict, current);
      if(current.length()>=3){
		thetable->insert(current);
      }
    }

    //grid file 
    string gFile = argv[2];
    //opening up grid file within dictionary 
    dict.open( gFile.c_str());
    int rows; 
    int cols;
    readInGrid(gFile.c_str(), rows, cols);
    int numFound = 0;
    string dir;
    //begin time
    t.start();

    //performing search 
    for( int r = 0; r < rows; r++ ){
      for( int c = 0; c < cols; c++ ){
		for( int newdir = 0; newdir < 8; newdir++ ){
	  		for( int wordLen = 3; wordLen <= thetable->maxWords; wordLen++ ){
			    string thisWord = getWordInGrid( r, c, newdir, wordLen, rows, cols );
			    if( thisWord.length() < wordLen ){
			      break;
			    }
			    else if( thetable->contains( thisWord ) ){
			      numFound++;
			      switch( newdir ){
			      case 0:
					dir = "N";
					break;
			      case 1:
					dir = "NE";
					break;
			      case 2:
					dir = "E";
					break;
			      case 3:
					dir = "SE";
					break;
			      case 4:
					dir = "S";
					break;
			      case 5:
					dir = "SW";
					break;
			      case 6:
					dir = "W";
					break;
			      case 7:
					dir = "NW";
					break;
				}
	      cout << dir << " (" << r << ", " << c << "): " << thisWord << endl;
	  		}
	  	}
	  }
	}
}
      //Stop time once done
      t.stop();
      double time = t.getTime();
      int othertime = int(time) * 1000;

      cout << numFound << " words found" << endl;
      cout << "Found all words in " << time << " seconds" << endl;

      cout << othertime << endl;// for shell script
      break;
  }
    return 0;
}

bool readInGrid (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.  In the process, we'll print the grid to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
            cout << grid[r][c];
        }
        cout << endl;
    }
    // return success!
    return true;
}

char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the grid
        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}
