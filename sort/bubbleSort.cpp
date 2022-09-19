#include <iostream>
#define MAX_SIZE 1000

using namespace std;

void copyArray(int arr[], int inputArr[], int n){
    for(int i=0; i<n; i++){
        arr[i] = inputArr[i];
    }
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b= tmp;
}

void bubbleSort(int array[], int n){
    int countCmpOps = 0;
    int countSwaps = 0;

    for(int pass=1; pass<n; pass++){
        for(int i=0; i<n-pass; i++){
            countCmpOps++;
            if(array[i] > array[i+1]){
                swap(array[i], array[i+1]);
                countSwaps++;
            }
        }
    }

    cout << countCmpOps << " " << countSwaps << " ";
}


void bubbleSortImproved1(int array[], int n){
    int countCmpOps = 0;
    int countSwaps = 0;
    int swapped; 

    for(int pass=1; pass<n; pass++){
        swapped = 0;
        for(int i=0; i<n-pass; i++){
            countCmpOps++;
            if(array[i] > array[i+1]){
                swap(array[i], array[i+1]);
                swapped = 1;
                countSwaps++;
            }
        }
        if(swapped == 0) break; // 이번 pass에서 swap하지 않았다면, 모든 데이터가 정렬되어 있음
    }

    cout << countCmpOps << " " << countSwaps << " ";
}


void bubbleSortImproved2(int array[], int n){
    int countCmpOps = 0;
    int countSwaps = 0; 
    int lastSwappedPos = n-1;
    int swappedPos;

    for(int pass=1; pass<n; pass++){
        if(lastSwappedPos > 0){
            swappedPos = 0;
            for(int i=0; i<lastSwappedPos; i++){
                countCmpOps++;
                if(array[i] > array[i+1]){
                    swap(array[i], array[i+1]);
                    swappedPos = i;
                    countSwaps++;
                }
            }
            lastSwappedPos = swappedPos;
        }
    }

    cout << countCmpOps << " " << countSwaps << "\n";
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    int input_array[MAX_SIZE];
    int array[MAX_SIZE];

    cin >> t;

    for(int i=0; i<t; i++){
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> input_array[j];
        }
        
        copyArray(array, input_array, n);
        bubbleSort(array, n);

        copyArray(array, input_array, n);
        bubbleSortImproved1(array, n);

        copyArray(array, input_array, n);
        bubbleSortImproved2(array, n);
    }
    return 0;
}