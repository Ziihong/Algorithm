#include <iostream>
#define MAXSIZE 100
using namespace std;


// 2*N 직사각형 타일 채우기와 동일
int fibo(int n){
    int Fib[MAXSIZE];
    Fib[0] = 0; 
    Fib[1] = 1;
    for(int i=2; i<=n; i++){ // index 0, 1 값 설정. 2부터 시작
        Fib[i] = Fib[i-1] + Fib[i-2];
    }
    return Fib[n];
}

int main(){

    cout << fibo(5) << endl;
    return 0;
}