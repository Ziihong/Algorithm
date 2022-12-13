#include <iostream>
using namespace std;

int arr1[10] = {9, 10, 8, 1, 2, 3, 4, 6, 5, 7};
int arr2[10] = {9, 10, 8, 1, 2, 3, 4, 6, 5, 7};

void printArr(int arr[]){
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(int parent, int size){
    printArr(arr1);
    int largest = parent;
    int left_idx = parent*2+1;
    int right_idx = parent*2+2;
    
    if(left_idx < size && arr1[left_idx] > arr1[largest]){
        largest = left_idx;
    }
    if(right_idx < size && arr1[right_idx] > arr1[largest]){
        largest = right_idx;
    }
    if(largest != parent){
        // swap
        int tmp = arr1[largest];
        arr1[largest] = arr1[parent];
        arr1[parent] = tmp;
        heapify(largest, size);
    }
}

void constructHeap(int idx, int size){
    cout << "construct idx: " << idx << endl;
    int left_idx = idx*2+1;
    int right_idx = idx*2+2;
    if((left_idx!=0 && left_idx<size) || (right_idx!=0 && right_idx<size)){
        constructHeap(left_idx, size);
        constructHeap(right_idx, size);
        heapify(idx, size);
    }
}
int main(){
    int size = 10;
    // for(int i=size/2; i>=0; i--){
    //     cout << i << endl;
    //     heapify(i, size);
    // }
    constructHeap(0, size);
    return 0;
}