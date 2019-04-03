//Amber Liu, al7bf, xToN.cpp, 09/02/2018
#include <iostream>
using namespace std;

int xton(int x, int n){
  int answer = 0;
  if(n == 0){
    answer = 1;
  }
  else{
    answer = x * xton(x, n-1);
  }
  return answer;
}

int main(){
  int x, n;
  cout << "what's x?" << endl;
  cin >> x;
  cout << "what's n?" << endl;
  cin >> n;
  cout << xton(x, n) << endl;
  return 0;
}
