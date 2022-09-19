#include <iostream>
#include <cmath>
#define MAX_SIZE 1000

using namespace std;

void insertionSort(int array[], int n, int gap){
    int i, j, key;
    for(i=gap; i<n; i++){
        key = array[i];
        j=i;
        while(j>=gap){ 
            if(array[j-gap] > key){
                array[j] = array[j-gap];
                j -= gap;
            }
            else break;
        }
        array[j] = key;
    }
}

// shellSort는 insertSort의 단점을 보완한 알고리즘
void shellSort(int array[], int n){
    int countCmpOps = 0;
    int countSwaps = 0;

    int shrink = 2;
    int gap, i, j, key;

    for(gap=floor(n/shrink); gap>0; gap/=shrink){

        // insertionSort
        for(i=gap; i<n; i++){
            key = array[i];
            j=i;
            while(j>=gap){ 
                countCmpOps++;
                if(array[j-gap] > key){
                    array[j] = array[j-gap];
                    j -= gap;
                    countSwaps++;
                }
                else break;
            }
            array[j] = key;
        }// insertionSort end
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
        shellSort(array, n);
    }

    return 0;
}