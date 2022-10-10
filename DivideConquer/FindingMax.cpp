#include <iostream>
using namespace std;

int recursionMax(int arr[], int l, int r){
    int half, l_max, r_max;
    if(l == r) return arr[l];
    else{
        half = (l+r)/2;
        l_max = recursionMax(arr, l, half);
        r_max = recursionMax(arr, half+1, r);
        return max(l_max, r_max);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        int num_arr[n];
        for(int j=0; j<n; j++){
            cin >> num_arr[j];

        }
        cout << recursionMax(num_arr, 0, n-1) << '\n';
    }
    return 0;
}
