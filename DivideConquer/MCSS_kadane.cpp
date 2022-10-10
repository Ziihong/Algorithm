#include <iostream>

using namespace std;


int maxSubsequenceSum(int arr[], int n, int* start, int* end){
    int max_sum = 0;
    int this_sum = 0;
    int front = 0;

    for(int i=0; i<n; i++){
        this_sum += arr[i];
        if(this_sum > max_sum){
            max_sum = this_sum;
            *start = front;
            *end = i;
        }
        // 최대 부분 합이 음수이면 굳이 더하지 않고 다음 i+1 번째 인덱스부터 새로 더함. this_sum 초기화. i 초기화x
        else if(this_sum < 0){
            front = i+1; 
            if(arr[front] == 0) front += 1;
            this_sum = 0;
        }
    }
    return max_sum;
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
        int start = -1;
        int end = -1;

        for(int j=0; j<n; j++){
            cin >> arr[j];
        }
        cout << maxSubsequenceSum(arr, n, &start, &end) << " " << start << " " << end << '\n';
    }
    return 0;
}
