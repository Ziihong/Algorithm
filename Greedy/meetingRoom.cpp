#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 백준 1931 벡터 이용
// int main(){
//     int t, start_time, end_time;
//     cin >> t;
//     vector< pair<int,int> > time_table;
//     for(int i=0; i<t; i++){
//         cin >> start_time >> end_time;
//         time_table.push_back(make_pair(end_time, start_time));
//     }

//     sort(time_table.begin(), time_table.end());

//     int cnt = 1;
//     int current_time = time_table[0].first;
//     for(int i=1; i<t; i++){
//         if(current_time <= time_table[i].second){ // 시작 시간
//             cnt++;
//             current_time = time_table[i].first; // 종료 시간
//         }
//     }
//     cout << cnt << '\n';

//     return 0;
// }

void timeSort(int n, int time_table[][2]){
    // 종료 시간 기준으로 정렬
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(time_table[i][1] > time_table[j][1]){
                int tmp_arr[2] = {time_table[i][0], time_table[i][1]};
                time_table[i][0] = time_table[j][0];
                time_table[i][1] = time_table[j][1];
                time_table[j][0] = tmp_arr[0];
                time_table[j][1] = tmp_arr[1];
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    int time_table[t][2];
    for(int i=0; i<t; i++){
        cin >> time_table[i][0] >> time_table[i][1];
    }
    for(int i=0; i<t; i++){
        cout << time_table[i][0] << " " << time_table[i][1] << endl;
    }
    
    timeSort(t, time_table);
    int current_time = time_table[0][1];
    int cnt = 1;

    for(int i=1; i<t; i++){
        if(current_time <= time_table[i][0]){
            cnt++;
            current_time = time_table[i][1];
        }
    }
    cout << cnt << '\n';
    return 0;
}