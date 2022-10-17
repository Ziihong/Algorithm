#include <iostream>
using namespace std;

int getCount(int gap){
    int* count_dp = new int [gap+1];
    for(int i=0; i<gap+1; i++){
        count_dp[i] = 10000001; // 최소 개수 구하기 때문에 큰 값으로 초기화
    }

    int weight_arr[] = {1, 2, 5, 10, 20, 50, 100};
    count_dp[0] = 0;
    for(int i=0; i<7; i++){
        for(int j=weight_arr[i]; j<=gap; j++){
            count_dp[j] = min(count_dp[j], count_dp[j-weight_arr[i]]+1);
        }
    }
    return count_dp[gap];
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, input;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        int left_sum = 0;
        int right_sum = 0;
        for(int j=0; j<n; j++){
            cin >> input;
            if(j == 0 || left_sum == right_sum) left_sum += input;
            else if(left_sum < right_sum) left_sum += input;
            else if(left_sum > right_sum) right_sum += input;
        }
        int gap = abs(left_sum - right_sum);
        if(gap != 0) cout << getCount(gap) << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}
