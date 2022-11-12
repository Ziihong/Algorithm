#include <iostream>
#define MAX_SIZE 101
using namespace std; 


int get_lcs_length(int L[][MAX_SIZE], const char* S, const char* T, int m, int n){
    // base case
    for(int i=0; i<=m; i++){
        L[i][0] = 0;
    }
    for(int i=0; i<=n; i++){
        L[0][i] = 0;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(S[i-1] == T[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
            }
            else {
                L[i][j] = max(L[i][j-1], L[i-1][j]);
            }
        }
    }
    return L[m][n];
}

void get_lcs_str(int L[][MAX_SIZE], int lcs_length, const char* S, const char* T, int m, int n, char answer[], int idx){

    for(int i=m; i>0; i--){
        for(int j=n; j>0; j--){
            if(L[i][j] == lcs_length){
                if(L[i-1][j] == lcs_length){
                    return get_lcs_str(L, lcs_length, S, T, i-1, j, answer, idx);
                }
                else if(L[i][j-1] == lcs_length){
                    return get_lcs_str(L, lcs_length, S, T, i, j-1, answer, idx);
                }
                else if(L[i-1][j] != lcs_length && L[i][j-1] != lcs_length){
                    answer[idx] =  S[i-1];
                    idx++;
                    return get_lcs_str(L, lcs_length-1, S, T, i-1, j-1, answer, idx);
                }
            }
        }
    }
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

        int s_len = S_str.length();
        int t_len = T_str.length();

        int L[MAX_SIZE][MAX_SIZE] = {0, };

        int lcs_length = get_lcs_length(L, S, T, s_len, t_len);
        // lcs length print
        cout << lcs_length << " ";
        
        if(lcs_length != 0) {
            char answer[lcs_length];
            int idx = 0;
            get_lcs_str(L, lcs_length, S, T, s_len, t_len, answer, idx);
                    
            // lcs print        
            for(int j=lcs_length-1; j>=0; j--){
                cout << answer[j];
            }
            cout << '\n';
        }

    }
    return 0;
}

