#include <iostream>
#define MAX_SIZE 101
using namespace std;


void order(int P[][MAX_SIZE], int i, int j){
    if(i == j){
        cout << "M" << i;
    }
    else{
        int k = P[i][j];
        cout << "(";
        order(P, i, k);
        order(P, k+1, j);
        cout << ")";
    }
}


int cmm(int d[], int n, int P[][MAX_SIZE]){
    int dp[MAX_SIZE][MAX_SIZE] = {0, };

    for(int diagonal=1; diagonal<=n; diagonal++){
        for(int i=1; i<=n; i++){
            int j = diagonal + i;
            dp[i][j] = __INT_MAX__; // 최대값으로 초기화
            for(int k=i; k<j; k++){
                int cnt = dp[i][k]+dp[k+1][j] + d[i-1]*d[k]*d[j];
                if(dp[i][j] > cnt){
                    dp[i][j] = cnt;
                    P[i][j] = k;
                }
            }
        }
    }

    order(P, 1, n);
    cout << '\n';

    return dp[1][n];
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
        int P[MAX_SIZE][MAX_SIZE]; // 최소가 되도록 만드는 기준점 저장
        for(int j=0; j<n+1; j++){
            cin >> d[j];
        }

        cout << cmm(d, n, P) << '\n';
    }
}