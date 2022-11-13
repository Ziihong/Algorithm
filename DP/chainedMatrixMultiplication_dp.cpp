#include <iostream>
#define MAX_SIZE 101
using namespace std;

void init_dp(int dp[][MAX_SIZE], int n){
    for(int i=0; i<MAX_SIZE; i++){
        for(int j=0; j<MAX_SIZE; j++){
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = __INT_MAX__;
        }
    }
}

int cmm(int d[], int n, int P[][MAX_SIZE]){
    int dp[MAX_SIZE][MAX_SIZE];
    init_dp(dp, n); // dp 최대값으로 초기화

    for(int diagonal=1; diagonal<=n; diagonal++){
        for(int i=1; i<=n; i++){
            int j = diagonal + i;
            for(int k=i; k<j; k++){
                int cnt = dp[i][k]+dp[k+1][j] + d[i-1]*d[k]*d[j];
                if(dp[i][j] > cnt){
                    dp[i][j] = cnt;
                    P[i][j] = k;
                }
            }
        }
    }


    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            cout << P[i][j] << " ";
        }
        cout << endl;
    }

    return dp[1][n];
}

void printMatrix(){}

int main(){
    int t, n;
    cin >> t;
    
    for(int i=0; i<t; i++){
        cin >> n;
        int d[n+1];
        int P[MAX_SIZE][MAX_SIZE]; // 최소가 되도록 만드는 기준점 저장
        for(int j=0; j<n+1; j++){
            cin >> d[j];
        }

        cout << cmm(d, n, P) << endl;
    }
}