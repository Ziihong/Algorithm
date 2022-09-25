#include <iostream>

using namespace std;

int answer;

void swap(char* array, int i, int j){
  char tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

void strWeight(char* array, int len){
    int weight = 0;
    int cal;
    for(int i=0; i<len; i++){
      cal = int(array[i]) - int('a');
      
      if(i%2 == 0) weight += cal;
      else weight -= cal;
    }
    if(weight > 0) answer++;
}


void permutation(char* array, int begin, int end, int len){
  int range = end - begin;
  if(range == 1) {
    
    // 가중치 계산
    strWeight(array, len);
    
  }
  else{
    for(int i=0; i<range; i++){
      //cout << array[begin] << " " << array[begin+i] << endl;
      swap(array, begin, begin+i);
      permutation(array, begin+1, end, len);
      swap(array, begin, begin+i);
    }  
  }
}

int main(){
  int t, n;
  string input;
  cin >> t;

  for(int i=0; i<t; i++){
    answer = 0; 

    cin >> input;
    n = input.length();
    char array[n];
    
    for(int j=0; j<n; j++){
      array[j] = input.at(j);
    }
    permutation(array, 0, n, n);

    cout << answer << '\n';
  }
  
  return 0;
}