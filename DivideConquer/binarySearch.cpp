#include <iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int value){
    if(left > right) return -1;
    else{
        int mid = (left + right)/2;
        if(arr[mid] == value) return mid;
        else if(value < arr[mid]) return binarySearch(arr, left, mid-1, value);
        else return binarySearch(arr, mid+1, right, value);
    }  
}

int main(){
    int t, n, K;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> K;
        int arr[n];
        for(int j=0; j<n; j++){
            cin >> arr[j];
        }
        cout << binarySearch(arr, 0, n, K) << '\n';
    }
    return 0;
}