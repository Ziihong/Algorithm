#include <iostream>

#define MAXSIZE 9
#define MARK 1
#define UNMARK 0

using namespace std;

typedef struct Point{
    int x, y;
}point;

point direction[8] = {
    {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}
};

int check[MAXSIZE][MAXSIZE];
int path[MAXSIZE][MAXSIZE];

int knightTour(int row, int col, point pos, int count){
    if(count == row*col) return 1;

    point next;
    for(int i=0; i<8; i++){
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;

        if(0<next.x && next.x<=col && 0<next.y && next.y<=row && check[next.y][next.x] != MARK){
            check[next.y][next.x] = MARK;
            path[next.y][next.x] = count+1;

            if(knightTour(row, col, next, count+1)) return 1;            
            check[next.y][next.x] = UNMARK;
        }
    }
    return 0;
}

void printTour(int y, int x){
    cout << 1 << endl;
    for(int i=1; i<=y; i++){
        for(int j=1; j<=x; j++){
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int t, y, x;
    point start;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> y >> x >> start.y >> start.x; 
    
        for(int j=0; j<MAXSIZE; j++){
            for(int k=0; k<MAXSIZE; k++){
                check[j][k] = UNMARK;
                path[i][k] = 0;
            }
        }
        check[start.y][start.x] = MARK;
        path[start.y][start.x] = 1;

        if(knightTour(y, x, start, 1)) printTour(y, x);
        else cout << 0 << endl;
    }
    return 0;
}