#include <iostream>
#include <cmath>
#define MAX_SIZE 1000

using namespace std;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void combSort(int array[], int n){
    float shrink = 1.3;
    int countCmpOps = 0;
    int countSwaps = 0;

    int sorted = 0;
    int gap = n;

    while(!sorted){
        gap = floor(gap/shrink);
        if(gap <= 1){
            gap = 1;
            sorted = 1;
        }

        for(int i=0; i+gap<n; i++){
            countCmpOps++;
            if(array[i] > array[i+gap]){
                swap(array[i], array[i+gap]);
                sorted = 0;     // gap이 1일 때 정렬이 끝나지 않은 상황. 다시 한번 sort하기 위한 설정
                countSwaps++;
            }
        }
    }
    cout << countCmpOps << " " << countSwaps << "\n";

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    int array[MAX_SIZE];

    cin >> t;

    for(int i=0; i<t; i++){
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> array[j];
        }
        combSort(array, n);
    }

    return 0;
}