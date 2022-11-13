#include <iostream>
#define MAX_SIZE 101

using namespace std;

void init_dp(int dp[][MAX_SIZE]){
    for(int i=0; i<MAX_SIZE; i++){
        for(int j=0; j<MAX_SIZE; j++){
            dp[i][j] = -1;
        }
    }
}


int cmm(int d[], int i, int j, int dp[][MAX_SIZE]){
    if(i == j) {
        dp[i][j] = 0;
        return 0;
    }

    int min_cnt = __INT_MAX__;
    int cnt;
    if(dp[i][j] == -1){
        for(int k=i; k<j; k++){
            cnt = cmm(d, i, k, dp) + cmm(d, k+1, j, dp) + d[i-1]*d[k]*d[j];
            if(cnt < min_cnt) min_cnt = cnt;
            dp[i][j] = min_cnt;
        }
    }
    return dp[i][j];
}


int cmm_memo(int d[], int i, int j, int dp[][MAX_SIZE]){
    init_dp(dp); 
    return cmm(d, i, j, dp);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, n;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> n;
        int d[n+1]; 
        for(int j=0; j<n+1; j++){
            cin >> d[j];
        }

        int dp[MAX_SIZE][MAX_SIZE];
        cout << cmm_memo(d, 1, n, dp) << '\n';
    }

    return 0;
}
