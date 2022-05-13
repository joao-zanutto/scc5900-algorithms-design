#include <iostream>
#define MAX 8
using namespace std;

static int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                          {1, -2}, {1, 2}, {2, -1}, {2, 1}};


bool limits(int x, int y){
	return ((x >= 0 && y >= 0) && (x < MAX && y < MAX));
}

bool isempty(int chess[MAX][MAX], int x, int y){
	return (limits(x, y)) && (chess[x][y] < 0);
}

int getDegree(int chess[MAX][MAX], int x, int y){
	int count = 0;
	for (int i = 0; i < MAX; ++i)
		if (isempty(chess, (x + moves[i][0]), (y + moves[i][1])))
			count++;

	return count;
}

bool nextMove(int chess[MAX][MAX], int *x, int *y){
	int min_deg_idx = -1, c, min_deg = (MAX+1), nx, ny;

	for (int count = 0; count < MAX; ++count){
		nx = *x + moves[count][0];
		ny = *y + moves[count][1];

		if ((isempty(chess, nx, ny)) && (c = getDegree(chess, nx, ny)) < min_deg){
			min_deg_idx = count;
			min_deg = c;
		}
	}

	if (min_deg_idx == -1)
		return false;

	nx = *x + moves[min_deg_idx][0];
	ny = *y + moves[min_deg_idx][1];
	chess[nx][ny] = chess[*x][*y]+1;

	*x = nx;
	*y = ny;

	return true;
}

bool neighbour(int x, int y, int xx, int yy){
	for (int i = 0; i < MAX; ++i)
		if (((x + moves[i][0]) == xx) && ((y + moves[i][1]) == yy))
			return true;

	return false;
}

bool findClosedTour(){
    int board[MAX][MAX];
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            board[i][j] = -1;
    board[0][0] = 0;

    int sx = 0, x = sx, sy = 0, y = sy;
    for (int i = 0; i < MAX*MAX-1; i++)
		if (nextMove(board, &x, &y) == 0)
			return false;

	for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
	return true;
}

int main(){
    while(!findClosedTour()){;}
    return 0;
}