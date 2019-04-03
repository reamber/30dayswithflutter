/** @author Amber Liu 
 * @brief topological.cpp 
 * @details topologically sorts a text file input 
 * @date 12/02/2018
 * 
 */
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>
#include <list>
//referenced ppt samples
using namespace std;
/**
  * @brief constructor for node
  */
class node{
public:
/** @var int indegree
   * @brief integer value of the node's indegree
   */
	int indegree;
/** @var vector<graphNode*> vec
   * @brief vector that holds adjacent nodes
   */
	vector<node*> vec;
/** @var string name 
   * @brief string that names the node 
   */
	string name;
/**
  * @brief constructor for node
  *@ param string str is the string to be stored by the node
  */
	node(string str){
		name = str;
		indegree = 0;
	}
};

/** @brief Main function
*/
int main (int argc, char **argv) {
	vector <node*> nodeslist;

	if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    ifstream file(argv[1], ifstream::binary);
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    string s1, s2;

    while(true){
    	file >> s1;
    	file >> s2;

    	if (s1 == "0" && s2 == "0"){
    		break;
    	}

    	int i = 0;//location
    	int vecpos1 = 0;//vec 1 position
    	int vecpos2 = 0;//vec 2 position

    	bool s1check = false;
    	bool s2check = false;
    	while(i < nodeslist.size()){
    		if(nodeslist[i]->name == s1){
    			s1check = true;
    			vecpos1 = i;
    		}
    		else if (nodeslist[i]->name == s2){
    			s2check = true;
    			vecpos2 = i;
    		}
    		i++;
    	}

    	if(!s1check){
    		nodeslist.push_back(new node(s1));
    		vecpos1 = nodeslist.size()-1;
    	}

    	if(!s2check){
    		nodeslist.push_back(new node(s2));
    		vecpos2 = nodeslist.size()-1;
    	}
    	nodeslist[vecpos2]->indegree++;
    	nodeslist[vecpos1]->vec.push_back(nodeslist[vecpos2]);
    }
    /////////sorting part///////////
    queue<node*> q;
    node *temp1;
    node *temp2;

    for(int j = 0; j < nodeslist.size(); j++){
    	temp1 = nodeslist[j];
    	if(temp1->indegree == 0){
    		q.push(temp1);
    	}
    }
    while(q.size()>0){
    	temp1 = q.front();
        q.pop();
    	cout << temp1->name << " ";
    	for(int z = 0; z < temp1->vec.size();z++){
    		temp2 = temp1->vec[z];
            temp2->indegree--;
    		if(temp2->indegree == 0){
    			q.push(temp2);
    		}
    	}
    }

    cout << endl;
    file.close();
}


