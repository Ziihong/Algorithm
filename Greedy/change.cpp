#include <iostream>
using namespace std;

int main(){
    int coin_arr[] = {500, 100, 50, 10, 5, 1};

    int pay_money;
    cin >> pay_money;
    int change_money = 1000 - pay_money;
    
    int cnt = 0;
    for(int i=0; i<6; i++){
        int d = change_money/coin_arr[i];
        cnt += d;
        change_money -= coin_arr[i]*d;
    }
    cout << cnt << '\n';

    return 0;
}