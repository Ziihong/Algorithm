#include <iostream>
#define MAX_SIZE 101
using namespace std; 


int get_lcs_length(int L[][MAX_SIZE], int S[][MAX_SIZE], char s[], char t[], int m, int n){
    // base case
    for(int i=0; i<=m; i++){
        L[i][0] = 0;
    }
    for(int i=0; i<=n; i++){
        L[0][i] = 0;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1] == t[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
                S[i][j] = 0;
            }
            else {
                L[i][j] = max(L[i][j-1], L[i-1][j]);
                if(L[i][j] == L[i][j-1]) S[i][j] = 1;
                else S[i][j] = 2;
            }
        }
    }
    return L[m][n];
}

void get_lcs_str(int lcs_length, int S[][MAX_SIZE], char s[], int s_len, int t_len){
    int j_range = s_len;
    int k_range = t_len;

    char answer[lcs_length];
    int idx = 0;
    for(int j=j_range; j>0; j--){
        for(int k=k_range; k>0; k--){
            if(S[j][k] == 0){
                answer[idx] = s[j-1];
                idx++;
                j_range = j-1;
                k_range = k-1;
                break;
            }
        }
    }
    for(int j=lcs_length-1; j>=0; j--){
        cout << answer[j];
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;
    string s_str;
    string t_str;
    
    for(int i=0; i<testcase; i++){
        cin >> s_str >> t_str;

        const int s_len = s_str.length();
        const int t_len = t_str.length();

        char s[s_len];
        char t[t_len];
        for(int j=0; j<s_len; j++){
            s[j] = s_str.at(j);
        }   
        for(int j=0; j<t_len; j++){
            t[j] = t_str.at(j);
        }

        int L[MAX_SIZE][MAX_SIZE] = {0, };
        int S[MAX_SIZE][MAX_SIZE] = {0, };
        int lcs_length = get_lcs_length(L, S, s, t, s_len, t_len);
        cout << lcs_length << " ";
        if(lcs_length != 0) get_lcs_str(lcs_length, S, s, s_len, t_len);
    }
    return 0;
}