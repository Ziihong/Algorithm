#include <iostream>

using namespace std;

int find_mid_max(int arr[], int left, int mid, int right){
    int left_sum = -1; 
    int right_sum = -1;

    int sum = 0;
    for(int i=mid; i>=left; i--){
        sum += arr[i];
        if(left_sum < sum) left_sum = sum;
    }
    sum = 0;
    for(int i=mid+1; i<=right; i++){
        sum += arr[i];
        if(right_sum < sum) right_sum = sum;
    }
    
    return left_sum + right_sum;
}

int maxSubsequenceSum(int arr[], int left, int right){
    if(left == right) return arr[left];

    int mid = (left + right)/2;
    int left_sum = maxSubsequenceSum(arr, left, mid);
    int right_sum = maxSubsequenceSum(arr, mid+1, right);
    int mid_sum = find_mid_max(arr, left, mid, right);

    int max_r = max(left_sum, right_sum);
    return max(max_r, mid_sum);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        int arr[n];
        for(int j=0; j<n; j++){
            cin >> arr[j];
        }
        int answer = maxSubsequenceSum(arr, 0, n-1);
        if(answer < 0) answer = 0;
        cout << answer << '\n';
    }
    return 0;
}

