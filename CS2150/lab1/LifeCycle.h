//Amber Liu, al7bf, LifeCycle.h, 09/04/2018
//header file containing class definition
#include <iostream>
#include <string>
using namespace std;

// ---------------------------------------------------  class definition
class MyObject {
public:
    static int numObjs;
    MyObject(const char *n = "--default--");      // default constructor
    MyObject(const MyObject& rhs);                // copy constructor
    ~MyObject();                                  // destructor

    string getName() const {
        return name;
    }
    void setName(const string newName) {
        name = newName;
    }

    friend ostream& operator<<(ostream& output, const MyObject& obj);
private:
    string name;
    int id;
};

