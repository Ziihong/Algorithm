#include <iostream>

using namespace std;

int lcs(const char* S, const char* T, int m, int n){
    if(m == 0 || n == 0){
        return 0;
    }
    else if(S[m-1] == T[n-1]){
        return lcs(S, T, m-1, n-1)+1;
    }
    else{
        int n_included = lcs(S, T, m-1, n);
        int m_included = lcs(S, T, m, n-1);
        return max(n_included, m_included);
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

        cout << lcs(S, T, S_str.length(), T_str.length()) << '\n';
    }
    return 0;
}