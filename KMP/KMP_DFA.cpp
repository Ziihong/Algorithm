#include <iostream>
#define MAXSIZE 1005
#define CHAR_MAXSIZE 3

using namespace std;

int DFA_Table[CHAR_MAXSIZE][MAXSIZE];

void init_DFA_Table(){
    for(int i=0; i<CHAR_MAXSIZE; i++){
        for(int j=0; j<MAXSIZE; j++){
            DFA_Table[i][j] = 0;
        }
    }
}

void constructDFA(string pattern, string text){
    int pattern_len = pattern.length();
    int text_len = text.length();

    DFA_Table[pattern.at(0)-'A'][0] = 1;

    int X = 0;
    for(int j=1; j<text_len; j++){
        for(int c=0; c<3; c++){
            DFA_Table[c][j] = DFA_Table[c][X];      // mismatch case
        }
        if(j < pattern_len){
            DFA_Table[pattern.at(j)-'A'][j] = j+1;  // match case
            X = DFA_Table[pattern.at(j)-'A'][X];
        }
    }
}

int DFA(string pattern, string text){
    int pattern_len = pattern.length();
    int text_len = text.length();
    int i, j;
    for(i=0, j=0; i<text_len && j<pattern_len; i++){
        j = DFA_Table[text.at(i)-'A'][j];
    }
    if(j == pattern_len) return i-pattern_len;
    else return -1;
}

int getNotZeroTransferCnt(int pattern_len){
    int not_zero_transfer_cnt = 0;
    for(int i=0; i<CHAR_MAXSIZE; i++){
        for(int j=0; j<pattern_len+1; j++){
            if(DFA_Table[i][j] != 0) not_zero_transfer_cnt++;
        }
    }
    return not_zero_transfer_cnt;
}


int main(){
    int t;
    string pattern, text;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> pattern >> text;
        
        int matched_cnt = 0;

        init_DFA_Table();
        constructDFA(pattern, text);
        int matched_idx = DFA(pattern, text);

        while(matched_idx != -1){
            if(matched_idx != -1) {
                matched_cnt++;
                text = text.substr(matched_idx+1);
                matched_idx = DFA(pattern, text);
            }
        }
        cout << getNotZeroTransferCnt(pattern.length()) << " " << matched_cnt << '\n';
    }    
    return 0;
}