#include <iostream>
#define MAX_SIZE 1000
using namespace std;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int array[], int n){
    int countCmpOps = 0;
    int countSwaps = 0;
    int i, j, min_index;

    for(i=0; i<n; i++){
        min_index = i; // 정렬되지 않은 데이터의 제일 앞 index
        for(j=i+1; j<n; j++){
            countCmpOps++;
            if(array[j] < array[min_index]){
                min_index = j;
            }
        }
        if(min_index != i) {
            swap(array[min_index], array[i]);
            countSwaps++;
        }
    }

    cout << countCmpOps << " " << countSwaps << '\n';
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    int array[MAX_SIZE];
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> array[j];
        }

        selectionSort(array, n);
    }
    return 0;
}