#include <iostream>

using namespace std;

int findPeak(int arr[], int l, int r){
    if(l==r) return arr[l];

    int mid = (l+r)/2;
    int l_peak = findPeak(arr, l, mid);
    int r_peak = findPeak(arr, mid+1, r);
    return max(l_peak, r_peak);
}

int main(){
    int arr[] = {12, 15, 20, 25, 32, 35, 37, 38, 39, 40, 45, 31, 26, 12, 9, 7, 3};
    cout << findPeak(arr, 0, 16) << endl;
    return 0;
}
