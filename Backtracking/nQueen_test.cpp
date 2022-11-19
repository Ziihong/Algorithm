#include <iostream>

#define N 4
using namespace std;

int col[N];
int cnt = 0;

int isPromising(int row){
    int k=0;
    int promising = 1;
    while(k<row && promising){
        cnt++;
        cout << k << " " << row << " " << col[k] << " " << col[row] << endl;
        if(col[row] == col[k] || abs(col[row]-col[k]) == row-k){
            promising = 0;
        }
        k++;
    }
    return promising;
}

void nQueens(int row){
    if(isPromising(row)){ // if(row == 0) true -> else문 수행
        if(row == N-1){
            cout << "Answer >>> " << endl;
            for(int i=0; i<N; i++){
                cout << col[i]+1 << " ";
            }
            cout << endl;
            return;
        }
        else{
            for(int i=0; i<N; i++){
                col[row+1] = i;
                nQueens(row+1);
            }
        }
    }
}

int main(){

    for(int i=0; i<N; i++){
        col[0] = i;
        nQueens(0);
    }
    cout << cnt << endl;    
    return 0;
}
// 3 1 4 2 

// 8 4 1 3 6 2 7 5 