#include <iostream>
#define MAXSIZE 30
using namespace std;

int binCoeff(int n, int k){
    int B[MAXSIZE][MAXSIZE] = {0, };

    for(int i=0; i<=n; i++){
        for(int j=0; j<=min(i, k); j++){
            if(j==0 || j==i) B[i][j] = 1;
            else B[i][j] = B[i-1][j-1] + B[i-1][j];
        }
    }
    
    return B[n][k];
}

int main(){
    int n, k; // n!/k!(n-k)! = (n, k)  = (n-1, k-1) + (n-1, k)
    cin >> n >> k;
    cout << binCoeff(n, k) << endl;
    return 0;
}