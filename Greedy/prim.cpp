#include <iostream>
using namespace std;
#define INF 9999

struct edge {
	int x1;
	int x2;
};

void prim(int n, int W[][5], edge* F) {
	int vnear;
	int min;
	int i, j;
	int f_size = 0;
	
	// the nearest node from the index (2-n)
	// 0, 1 index is ignored. It's just for readibility.
	int* nearest = new int[n+1];
	// distance of the index and the nearest node (2-n)
	int* distance = new int[n+1];

	for (i = 2; i <= n; i++) {
		nearest[i] = 1;
		distance[i] = W[0][i-1];
	}

	for (i = 0; i < n; i++) {
		min = INF;
		for (j = 2; j <= n; j++) {
			if (distance[j] < min && distance[j] >= 0) {
				min = distance[j];
				vnear = j;
			}
		}

		edge new_edge;
		new_edge.x1 = vnear;
		new_edge.x2 = nearest[vnear];

		F[f_size] = new_edge;
		f_size++;

		distance[vnear] = -1;

		for (j = 2; j <= n; j++) {
			if (W[j-1][vnear-1] < distance[j]) {
				distance[j] = W[j-1][vnear-1];
				nearest[j] = vnear;
			}
		}
		
	}
}

int main() {
	int weigth_matrix[5][5] = 
	{	{0, 1, 3, INF, INF},
		{1, 0, 3, 6, INF},
		{3, 3, 0, 4, 2},
		{INF, 6, 4, 0, 5},
		{INF, INF, 2, 5, 0} };

	// MST's maximum edge number is n-1
	edge* F = new edge[4];

	prim(5, weigth_matrix, F);

	int i;
	for (i = 0; i < 4; i++) {
		cout << F[i].x1 << "," << F[i].x2 << endl;
	}
	
}
