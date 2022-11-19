#include <iostream>
#define SIZE 4
using namespace std;

int quiz[SIZE][SIZE];
int isPrinted = 0;  


void printQuiz(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cout << quiz[i][j] << " ";
        }
        cout << '\n';
    }
}

bool isPromising(int r, int c, int n){
    for(int i=0; i<SIZE; i++){
        if(quiz[r][i] == n) return false;
        if(quiz[i][c] == n) return false;
    }
    for(int i=(r/2)*2; i<(r/2)*2+2; i++){
        for(int j=(c/2)*2; j<(c/2)*2+2; j++){
            if(quiz[i][j] == n) return false;
        }
    }
    return true;
}

void sudoku(int r, int c){
    if(isPrinted == 1) return;
    
    if(r == SIZE){
        printQuiz();
        isPrinted = 1;
    }
    if(c == SIZE) sudoku(r+1, 0);
    if(quiz[r][c] == 0){
        for(int i=1; i<=SIZE; i++){
            if(isPromising(r, c, i)){
                quiz[r][c] = i;
                sudoku(r, c+1);
                quiz[r][c] = 0;
            }
        }
    }
    else sudoku(r, c+1);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int i=0; i<t; i++){

        isPrinted = 0;
        for(int j=0; j<SIZE; j++){
            for(int k=0; k<SIZE; k++){
                cin >> quiz[j][k];
            }
        }
        sudoku(0, 0);
    }
    
    return 0;
}