#include <iostream>
#define MAXSIZE 1001

using namespace std;

int fail[MAXSIZE];

void getFail(string pattern){
    int pattern_len = pattern.length();
    int j = 0;

    for(int i=1; i<pattern_len; i++){
        while(j>0 && pattern[i] != pattern[j]){
            j = fail[j-1];
        }
        if(pattern[i] == pattern[j]){
            fail[i] = ++j;
        }
    }
}

int kmp(string text, string pattern){
    int matched_cnt = 0;
    getFail(pattern);
    int text_len = text.length();
    int pattern_len = pattern.length();
    int j = 0;
    for(int i=0; i<text_len; i++){
        while(j>0 && text[i] != pattern[j]){
            j = fail[j-1];
        }
        if(text[i] == pattern[j]){
            if(j == pattern_len-1) {
                matched_cnt++;
                j = fail[j];
            }
            else j++;
        }
    }
    return matched_cnt;
}

void printFail(string pattern){
    for(int k=0; k<pattern.length(); k++){
        cout << fail[k] << ' ';
    }
    cout << endl;
}

int main(){
    int t, matched_cnt;
    string pattern, text;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> pattern >> text;
        fill_n(fail, MAXSIZE, 0);

        matched_cnt = kmp(text, pattern);
        
        printFail(pattern);
        cout << matched_cnt << '\n';
    }
    return 0;
}