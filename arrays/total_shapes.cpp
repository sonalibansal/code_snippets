//https://practice.geeksforgeeks.org/problems/x-total-shapes/0
#include <iostream>
#include <queue>
using namespace std;

#define R 10
#define C 3
queue<pair<int, int> > q;

//char graph[R][C+1] = { "OOOOXXO", "OXOXOOX","XXXXOXO", "OXXXOOO"};

char graph[R][C+1] = {"XXO", "OOX","OXO", "OOO", "XOX", "XOX", "OXO", "XXO", "XXX", "OOO"};
bool visited[R][C];

bool isSafe(int i, int j) {
	return (i>=0 && i < R && j >=0 && j < C
	&& graph[i][j] == 'X' && !visited[i][j]);
}

void BFS(int src, int dest)  {
	int row[] = {1, 0, -1, 0};
	int col[] = {0, 1, 0, -1};
	
	q.push(make_pair(src, dest));
	visited[src][dest] = true;
	
	pair<int, int> element;
	int i, j, k;
	
	while(!q.empty()) {
		element = q.front();
		q.pop();
		i = element.first;
		j = element.second;
		
		for(int k = 0 ; k < 4; k++) {
			if(isSafe(row[k] +i, col[k]+j)) {
				visited[row[k] + i][col[k]+j] = true;
				q.push(make_pair(row[k] +i, col[k]+j));
			}
		}
	}
	
	
}

void countXTotalShapes() {
	int res = 0;
	for(int i = 0 ; i < R ; i++) {
		for(int j = 0 ;j < C ;j++) {
			visited[i][j] = false;
		}
	}
	for(int i = 0 ; i < R ; i++) {
		for(int j = 0 ;j < C ;j++) {
			if(graph[i][j] == 'X' && !visited[i][j]) {
				BFS(i, j);
				res ++;
			}
		}
	}
	cout << res << endl;
}
int main() {
	countXTotalShapes();
	return 0;
}