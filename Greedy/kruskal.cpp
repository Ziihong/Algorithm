#include <iostream>
#define MAXSIZE 10
#define INF 10000
using namespace std;

int parent[MAXSIZE];

int find(int x){
    while(parent[x] != x){
        x = parent[x];
    }
}
void uni(int a, int b){
    if(find(a) != find(b)){
        parent[a] = b;
    }
}

int is_same_parent(int a, int b){
    return find(a) == find(b);
}


void sortData(){
    // string temp;
    // for(int i=0; i<size-1; i++){
    //     for(int j=i+1; j<size; j++){
    //         if(data[j].at(1) < data[i].at(1)){ //data[].at(1)=>cost
    //             temp=data[i];
    //             data[i]=data[j];
    //             data[j]=temp;
    //         }
    //     }
    // }
}
int kruskal(){
    // int count=0, pos=0, cost=0;
    // while(count < MAX_SIZE-1){
    //     if(!checkCircle(data[pos].at(0), data[pos].at(2))){ //cycle을 형성하지않으면
    //         cout << "Edge" << count+1 << ": " << data[pos] << endl;
    //         cost+=data[pos].at(1)-'0';
    //         count++;
    //     }
    //     pos++;
    // }
    // cout << endl;
    // return cost;


    // kruskal 마지막에 uninon
    // 	sort(v.begin(), v.end());

	// int answer = 0;

	// for (int i = 0; i < v.size(); i++) {
	// 	if (isCycle(v[i].node[0], v[i].node[1]) == false) {
	// 		answer += v[i].distance;
	// 		uni(v[i].node[0], v[i].node[1]);
	// 	}
	// }

	// cout << answer;
}

int main(){
    int weigth_matrix[5][5] = 
	{	{0, 1, 3, INF, INF},
		{1, 0, 3, 6, INF},
		{3, 3, 0, 4, 2},
		{INF, 6, 4, 0, 5},
		{INF, INF, 2, 5, 0} 
    };

    for(int i=0; i<MAXSIZE; i++){
        parent[i] = i;
    }

    return 0;
}