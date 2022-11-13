#include <iostream>

using namespace std;

int cmm(int d[], int i, int j){
    if(i == j) return 0;

    int min_cnt = __INT_MAX__;
    int cnt;
    for(int k=i; k<j; k++){
        cnt = cmm(d, i, k) + cmm(d, k+1, j) + d[i-1]*d[k]*d[j];
        if(cnt < min_cnt) min_cnt = cnt;
    }
    return min_cnt;
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

        cout << cmm(d, 1, n) << '\n';
    }
    return 0;
}