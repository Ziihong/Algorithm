#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main(){
    int t; 
    cin >> t;

    int a, b;
    for(int i=0; i<t; i++){
        cin >> a >> b;
        cout << gcd(a, b) << '\n';
    }

    return 0;
}