#include <iostream>

using namespace std;

int power(int a, int n){
    int tmp;
    if(n == 0) return 1;
    else if(n%2 == 1) {
        tmp = power(a, (n-1)/2) % 1000;
        return a*tmp*tmp % 1000;
    }
    else{
        tmp = power(a, n/2) % 1000;
        return tmp*tmp % 1000;
    }
}


int main(){
    int t, a, n;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> a >> n;
        cout << power(a, n) << endl;
    }
    return 0;
}

