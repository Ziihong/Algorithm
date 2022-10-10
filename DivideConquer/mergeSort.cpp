#include <iostream>
#define MAX_SIZE 100
using namespace std;


int basic_op_count;

void merge(int arr[], int left, int mid, int right){
    int tmp[MAX_SIZE];

    for(int i=left; i<=right; i++){
        tmp[i] = arr[i];
    }

    int merge_idx = left;
    int idx1 = left;
    int idx2 = mid+1;

    while(idx1<=mid && idx2<=right){
        basic_op_count += 1;
        if(tmp[idx1] <= tmp[idx2]) {
            arr[merge_idx++] = tmp[idx1++];
        }
        else arr[merge_idx++] = tmp[idx2++];
    }

    while(idx1 <= mid){
        arr[merge_idx++] = tmp[idx1++];
    }
    while(idx2 <= right){
        arr[merge_idx++] = tmp[idx2++];
    }
}

void mergeSort(int arr[], int left, int right){
    if(left == right) return ;

    int mid = (left + right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    int arr[MAX_SIZE];

    cin >> t;
    for(int i=0; i<t; i++){
        basic_op_count = 0;
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> arr[j];
        }
        mergeSort(arr, 0, n-1);
        cout << basic_op_count << endl;
    }
    return 0;
}