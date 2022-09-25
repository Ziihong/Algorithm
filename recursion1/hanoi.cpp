#include <iostream>
using namespace std;

void hanoi(int n, int a, int b, int c){
    // if(n==0){
    //     if(a==3) cout << "N:: " << n << endl;
    // }
    if(n>0){
        hanoi(n-1, a, c, b);
        // cout << a << "->" << c << endl;
        // cout << "n: " << n << endl;
        if(a == 3 || c == 3) {
            if(a > c) cout << n-1 << " ";
            else cout << n << " ";
        }
        // if(c == 3) cout << n << " ";
        hanoi(n-1, b, a, c);
    }
}

int main(){
    int t, n;
    cin >> t;
    
    for(int i=0; i<t; i++){
        cin >> n;
        hanoi(n, 1, 2, 3);
    }
    return 0;
}


// 1 0 3 2 1 2 3 0 1 0 5 2 1 2 5 4 1 4 3 2 1 <- answer
// 1 0 3 2 1 0 1 2 1 0 5 2 1 0 1 4 1 0 3 2 1