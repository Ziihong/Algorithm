#include <iostream>
#define MAX_SIZE 2001
using namespace std;

int arr[MAX_SIZE];
int cnt;

void printArr(int n){
    for(int j=0; j<n; j++){
        cout << arr[j+1] << " ";
    }
    cout << endl;
}

bool isNotLeaf(int k, int size){
    if((arr[k*2]!=0 && k*2<=size) || (arr[k*2+1]!=0 && k*2+1<=size)) return true;
    return false;
}

int get_larger_child_idx(int i, int size){
    int left_child = arr[i*2];
    int right_child = arr[i*2+1];

    int larger_idx;
    if(right_child != 0 && i*2+1 <=size){
        if(left_child > right_child) larger_idx = i*2;
        else larger_idx = i*2+1;
        cnt += 2;
    }
    else{
        larger_idx = i*2;
        cnt++;
    }
    return larger_idx;
}

void fixHeap(int parent, int K, int size){
    int vacant = parent;
    while(isNotLeaf(vacant, size)){
        int larger_child_idx = get_larger_child_idx(vacant, size);
        if(K < arr[larger_child_idx]){
            arr[vacant] = arr[larger_child_idx];
            vacant = larger_child_idx;
        }
        else break;
    }
    arr[vacant] = K;
}


void heapSort(int n){
    
    for(int i=n/2; i>0; i--){
        fixHeap(i, arr[i], n);
    }   
    
    for(int heapsize=n; heapsize>=2; heapsize--){
        int max = arr[1];
        fixHeap(1, arr[heapsize], heapsize-1);
        arr[heapsize] = max;
    }
}

int main(){
    int t, n;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        cnt = 0;
        for(int j=0; j<n; j++){
            cin >> arr[j+1]; // 0번째 인덱스 사용x
        }
        heapSort(n);
        cout << cnt << '\n';
    }
    return 0;
}
