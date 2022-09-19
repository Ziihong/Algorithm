#include <iostream>
using namespace std;

#define MAX_SIZE 1000


void insertionSort(int array[], int n){
    int countSwaps = 0;
    int countCmpOps = 0;
    int i, j, key;

    for(i=1; i<n; i++){
        key = array[i];
        j=i;
        while(j>0){
            countCmpOps++; // 비교 연산자 실행
            if(array[j-1] > key){
              array[j] = array[j-1];
              j--;
              countSwaps++; // swap 실행
            }
            else break; // key 앞에는 모두 정렬된 숫자들. 정렬된 숫자보다 key가 크면 break
        }
        array[j] = key; // break한 마지막 index에 key의 값 저장
    }

    cout << countCmpOps << " " << countSwaps << '\n';

}


int main(){
    
    int t, n;
    int array[MAX_SIZE];

    cin >> t;
    
    for(int i=0; i<t; i++){
        cin >> n;

        for(int j=0; j<n; j++){
            cin >> array[j];
        }

        insertionSort(array, n);
    }

    return 0;
}