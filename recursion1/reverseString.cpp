#include <iostream>

using namespace std;

void swap(char array[], int front, int back){
  char tmp = array[front];
  array[front] = array[back];
  array[back] = tmp;
}

void reverseString(char array[], int front, int back){
  if(front < back){
    swap(array, front, back);
    reverseString(array, front+1, back-1);
  }
}


int main(){
  int t, n;
  string input;  
  cin >> t;

  for(int i=0; i<t; i++){
    cin >> input;
    
    n = input.length();
    char array[n];
    for(int j=0; j<n; j++){
      array[j] = input.at(j);
    }
    
    reverseString(array, 0, n-1);

    for(int k=0; k<n; k++){
      cout << array[k];
    }
    cout << '\n';
  }
  return 0;
}

