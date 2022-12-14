#include <iostream>
#define MAX_SIZE 10
using namespace std;

int pt[MAX_SIZE];
int sz[MAX_SIZE];

void init(int n){
    for(int i=0; i<n; i++){
        pt[i] = i;
        sz[i] = 1;
    }
}

int find(int a){
    int parent;
    int root = a;
    while(pt[root] != root){ // root가 아니라면
        root = pt[root];
    }
    // root 아래 모든 자식 노드들 설정
    while(pt[a] != root){
        parent = pt[a];
        pt[a] = root;
        a = parent;
    }
    return root;
}

bool in_same_set(int a, int b){
    return find(a) == find(b);
}

void union_set(int a, int b){
    if(find(a) != find(b)){
        if(sz[a] > sz[b]){
            pt[b] = a;
            sz[a] += sz[b]; 
        }
        else{
            pt[a] = b;
            sz[b] += sz[a];
        }
    }
}


int main(){
    int n;
    cin >> n;
    init(n);
    
    return 0;
}