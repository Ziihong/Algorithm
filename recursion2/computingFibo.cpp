#include <iostream>
using namespace std;

void print(int F[2][2]){
    cout << F[0][0] << " " << F[0][1] << endl;
    cout << F[1][0] << " " << F[1][1] << endl;
}



void multiply(int F[2][2], int M[2][2]){
    int w, x, y, z;
    w = (F[0][0]*M[0][0] + F[0][1]*M[1][0]) % 1000;
    x = (F[0][0]*M[0][1] + F[0][1]*M[1][1]) % 1000;
    y = (F[1][0]*M[0][0] + F[1][1]*M[1][0]) % 1000;
    z = (F[1][0]*M[0][1] + F[1][1]*M[1][1]) % 1000;

    F[0][0] = w;
    F[0][1] = x;
    F[1][0] = y;
    F[1][1] = z;
}


void power(int F[2][2], int n){
    if(n <= 1) return;
    int M[2][2] = {
        {1, 1},
        {1, 0}
    };

    power(F, n/2); // 짝수
    multiply(F, F);
    if(n%2 != 0) multiply(F, M); // 홀수 일때 버려지는 연산 1회 보완
}


int fibo(int n){
    int F[2][2] = {
        {1, 1},
        {1, 0}
    };

    if(n == 0) {
        return 0;   
    }
    power(F, n);
    
    return F[0][1];
}

int main(){
    int t, n;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> n;
        cout << fibo(n) << endl;
    }
    return 0;
}


