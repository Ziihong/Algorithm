#include <iostream>

using namespace std;

int hoare_countCmpOps, hoare_countSwaps, lomuto_countCmpOps, lomuto_countSwaps;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int partition_hoare(int arr[], int low, int high){
    int pivot, idx1, idx2;
    
    pivot = arr[low];
    idx1 = low - 1;
    idx2 = high + 1;

    while(true){
        hoare_countCmpOps++; // 비교 연산
        while(arr[++idx1] < pivot) hoare_countCmpOps++;
        hoare_countCmpOps++; // 비교 연산
        while(arr[--idx2] > pivot) hoare_countCmpOps++;

        if(idx1 < idx2) {
            hoare_countSwaps++; // swap
            swap(arr[idx1], arr[idx2]);
        }
        else return idx2;
    }
}

int partition_lomuto(int arr[], int low, int high){
    int pivot, pivot_lower_idx, pivot_idx;

    pivot = arr[low];
    pivot_lower_idx = low;

    for(int i=low+1; i<=high; i++){
        lomuto_countCmpOps++;     // 비교 연산
        if(arr[i] < pivot){
            pivot_lower_idx++;
            lomuto_countSwaps++; // swap
            swap(arr[i], arr[pivot_lower_idx]);
        }
    }
    pivot_idx = pivot_lower_idx;
    lomuto_countSwaps++; // swap
    swap(arr[low], arr[pivot_idx]);    
    return pivot_idx;
}


void quickSort_hoare(int arr[], int low, int high){
    int pivot_idx;
    if(low < high){
        pivot_idx = partition_hoare(arr, low, high);
        quickSort_hoare(arr, low, pivot_idx);
        quickSort_hoare(arr, pivot_idx+1, high);        
    }
}

void quickSort_lomuto(int arr[], int low, int high){
    int pivot_idx;
    if(low < high){
        pivot_idx = partition_lomuto(arr, low, high);
        quickSort_lomuto(arr, low, pivot_idx-1);
        quickSort_lomuto(arr, pivot_idx+1, high);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, input;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        
        int arr_hoare[n], arr_lomuto[n];
        hoare_countCmpOps = 0;
        hoare_countSwaps = 0;
        lomuto_countCmpOps = 0;
        lomuto_countSwaps = 0;

        for(int j=0; j<n; j++){
            cin >> input;
            arr_hoare[j] = input;
            arr_lomuto[j] = input;
        }
        quickSort_hoare(arr_hoare, 0, n-1);
        quickSort_lomuto(arr_lomuto, 0, n-1);
        cout << hoare_countSwaps << " " << lomuto_countSwaps << " " << hoare_countCmpOps << " " << lomuto_countCmpOps << '\n';

    }
    return 0;
}
