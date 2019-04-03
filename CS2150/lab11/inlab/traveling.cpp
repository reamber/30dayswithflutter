/** @author Amber Liu 
 * @brief topological.cpp 
 * @date 12/02/2018
 * 
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"
/** @fn computeDistance(MiddleEarth &me, string start, vector<string> dests)
 * @param me 
 * @param start the city to begin the journey
 * @param dests all the cities to visit 
 * @return float distance
 * @brief calculates the distance
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests);
/** @fn printRoute(string start, vector<string> dests)
 * @param start the city to begin the journey 
 * @param dests vector holding all the cities visited en route 
 * @brief prints the route 
 */
void printRoute (string start, vector<string> dests);

/** @brief Main function
*/
int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    // YOUR CODE HERE

    string start = dests[0];
    vector<string> result = dests;
    float mindis = computeDistance(me, start, dests);

    while(next_permutation(dests.begin()+1, dests.end())){
        float temp = computeDistance(me, start, dests);
        if(temp < mindis){
            mindis = temp;
            result.clear();
            result = dests;
        }
    }
    cout << "Your journey will take you along the path ";
    printRoute(result[0], result);
    cout << "and will have length " << mindis << endl;
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
    // YOUR CODE HERE
    float sum = 0;
    for(int i = 0; i < dests.size(); i++){
        sum += me.getDistance(start, dests[i]);
        start = dests[i];
    }
    sum += me.getDistance(dests[0], dests[dests.size()-1]);
    return sum;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute (string start, vector<string> dests) {
    // YOUR CODE HERE
    for(int i = 0; i<dests.size(); i++){
        if(i == dests.size()-1){
            cout<< dests[i] << " -> " << dests[0] << endl;
        }
        else{
            cout << dests[i] << " -> ";
        }
    }
}
