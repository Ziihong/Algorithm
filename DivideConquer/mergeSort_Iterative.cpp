#include <iostream>
#define MAXSIZE 100
using namespace std;

int basic_op_cnt;

int find_min(int arr[], int idx1, int idx2){

    if(arr[idx1] < arr[idx2]) return idx1;
    else return idx2;
}

void merge(int arr[], int low, int mid, int high){
    int tmp[MAXSIZE];
    for(int i=low; i<=high; i++){
        tmp[i] = arr[i];
    }
    int idx1, idx2, merge_idx;
    merge_idx = low;
    idx1 = low;
    idx2 = mid+1;
    while(idx1<=mid && idx2<=high){
        basic_op_cnt++;
        if(tmp[idx1] <= tmp[idx2]) arr[merge_idx++] = tmp[idx1++];
        else arr[merge_idx++] = tmp[idx2++];
    }

    while(idx1 <= mid) arr[merge_idx++] = tmp[idx1++];
    while(idx2 <= high) arr[merge_idx++] = tmp[idx2++];

}


void mergeSort(int arr[], int n){
    int size = 1; // 연속으로 merge할 데이터의 크기
    int low, mid, high;
    int end = n-1;
    while(size < n){
        for(int i=0; i<n; i+=2*size){
            low = i;            
            mid = min(i+size-1, end);
            high = min(i+2*size-1, end);
            merge(arr, low, mid, high);
        }
        size *= 2;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    int arr[MAXSIZE];
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        basic_op_cnt = 0;
        for(int j=0; j<n; j++){
            cin >> arr[j];
        }
        mergeSort(arr, n); 
        cout << basic_op_cnt << '\n';
    }

    return 0;
}