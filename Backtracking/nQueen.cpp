#include <iostream>
#define MAX_SIZE 17

using namespace std;

int col[MAX_SIZE];
int N;
int isPrinted = 0;

void printArr(int col[]){
    for(int i=0; i<N; i++){
        cout << col[i]+1 << " ";
    }
    cout << endl;
    isPrinted = 1;
}

int isPromising(int row){
    int k=0;
    int promising = 1;
    while(k<row && promising){
        if(col[row] == col[k] || abs(col[row]-col[k]) == row-k){
            promising = 0;
        }
        k++;
    }
    return promising;
}

void nQueens(int row){
    if(isPrinted) return;
    
    if(isPromising(row)){ // if(row == 0) true -> else문 수행
        if(row == N-1){
            if(!isPrinted) printArr(col);
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
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> N;
        isPrinted = 0;
        for(int j=0; j<N; j++){
            col[0] = j;
            nQueens(0);
        }
    }
    return 0;
}