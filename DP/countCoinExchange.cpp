#include <iostream>
#define MAXSIZE 100
using namespace std;

int countCoinExchange(int coinArr[], int coinCount, int change){
    int N[MAXSIZE][MAXSIZE] = {0};
    
    for(int i=1; i<=coinCount; i++){
        N[i][0] = 1;
    }
    for(int i=1; i<=change; i++){
        N[0][i] = 0;
    }

    int numComb;
    for(int i=1; i<=coinCount; i++){
        for(int j=1; j<=change; j++){

            if(j-coinArr[i-1] < 0) numComb = 0; // coinArr 다룰 때 i-1 인덱스 사용
            else numComb = N[i][j-coinArr[i-1]];
            
            N[i][j] = N[i-1][j] + numComb;
        }
    }

    for(int i=0; i<coinCount; i++){
        for(int j=0; j<change; j++){
            cout << N[i][j] << " ";
        }
        cout << endl;
    }
    return N[coinCount][change];
}

int main(){

    int coinArr[] = {1, 2, 3, 5}; 
    int coinCount = 4;
    int change = 7;  // 거스름돈

    cout << countCoinExchange(coinArr, coinCount, change) << endl;

    return 0;
}