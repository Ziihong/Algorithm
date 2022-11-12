#include <iostream>
#define MAX_SIZE 101

using namespace std;

void init_L(int L[][MAX_SIZE]){
    for(int i=0; i<MAX_SIZE; i++){
        for(int j=0; j<MAX_SIZE; j++){
            L[i][j] = -1;
        }
    }
}

int lcs(int L[][MAX_SIZE], const char* S, const char* T, int m, int n){
    
    if(m == 0 || n == 0){
        L[m][n] = 0;
        return 0;
    }

    if(L[m][n] == -1){ 
        if(S[m-1] == T[n-1]){
            L[m][n] = lcs(L, S, T, m-1, n-1)+1;
        }
        else{
            int n_included = lcs(L, S, T, m-1, n);
            int m_included = lcs(L, S, T, m, n-1);
            L[m][n] = max(n_included, m_included);
        }
    }
    return L[m][n];   
}

int lcs_memo(int L[][MAX_SIZE], const char *S, const char* T, int m, int n){
    
    init_L(L);
    return lcs(L, S, T, m, n);
}


int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    string S_str, T_str;

    for(int i=0; i<t; i++){
        cin >> S_str >> T_str;
        
        const char* S = S_str.c_str();
        const char* T = T_str.c_str();

        int L[MAX_SIZE][MAX_SIZE];
        
        cout << lcs_memo(L, S, T, S_str.length(), T_str.length()) << '\n';
    }
    return 0;
}