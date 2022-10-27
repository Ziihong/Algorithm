#include <iostream>

using namespace std;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void cocktailSort(int arr[], int size){
    bool swapped = true;
    int start, end;
    start = 0;
    end = size-1;

    while(swapped) {
        swapped = false;
        for(int i=start; i<end; i++){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
        end--; // 이번 pass로 제일 오른쪽 정렬

        if(!swapped) break; // 정렬 완료
        
        swapped = false;
        for(int i=end-1; i>=start; i--){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
        start++; // 이번 pass로 제일 왼쪽 정렬
    }
}

int main(){
    int arr[] = {54, 74, 98, 154, 98, 32, 20, 13, 35, 40};
    int size = 10;

    cocktailSort(arr, size);

    cout << "After sort" << endl;
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}