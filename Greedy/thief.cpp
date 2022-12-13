#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long long, long long> > jewel_arr;

long long getMaxMoney(int C){
    long long max_money = -1;
    int max_idx = 0;
    for(int i=0; i<jewel_arr.size(); i++){  
        if(jewel_arr[i].first <= C){
            if(jewel_arr[i].second > max_money){
                max_money = jewel_arr[i].second;
                max_idx = i;
            }
        }
        else break;
    }
    jewel_arr[max_idx].second = -1; // 이미 챙긴 보석의 가격 최소값으로 설정
    return max_money;
}

int main(){
    long long N, K, M, V, C;
    cin >> N >> K;

    for(int i=0; i<N; i++){
        cin >> M >> V;
        jewel_arr.push_back(make_pair(M, V));
    }
    sort(jewel_arr.begin(), jewel_arr.end());
    
    unsigned long long answer = 0;
    for(long long i=0; i<K; i++){
        cin >> C;
        answer += getMaxMoney(C); 
    }
    cout << answer << '\n';

    return 0;
}