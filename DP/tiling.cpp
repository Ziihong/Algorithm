#include <iostream>
#define MAXSIZE 100
using namespace std;


// fibo와 방식 동일
int tiling(int n){
    int Tile[MAXSIZE];
    Tile[0] = 0;
    Tile[1] = 1;
    Tile[2] = 2;
    for(int i=3; i<=n; i++){
        Tile[i] = Tile[i-1] + Tile[i-2];
    }
    return Tile[n];
}


int main(){

    cout << tiling(5) << endl;
    return 0;
}