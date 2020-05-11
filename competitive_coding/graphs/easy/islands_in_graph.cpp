// https://www.geeksforgeeks.org/islands-in-a-graph-using-bfs/
#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <queue>
using namespace std;

#define R 5
#define C 5

queue<pair<int, int> > q;

// O(1)
int isSafe (int i , int j ,int graph[R][C], int visited[R][C]) {

	return (i >= 0 && i < R
			&& j >= 0 && j < C 
			&& graph[i][j] 
			&& !visited[i][j]);

}

//O(RC)
void BFS (int graph[R][C], int visited[R][C], int src, int dest) {

	int row[] = {-1,-1,-1,0,1,1,1,0};
	int col[] = {-1,0,1,1,1,0,-1,-1};
	int i,j,k;
	pair<int,int> top;

	q.push (make_pair(src, dest));
	visited[src][dest] = 1;

	while (!q.empty ()) {
		top = q.front();
		q.pop ();
		i = top.first;
		j = top.second;
		for (k = 0 ; k < 8 ; k++) {
			if(isSafe (i + row[k], j + col[k], graph, visited)) {
				visited[i+ row[k]][j + col[k]] = 1;
				q.push (make_pair (i+ row[k], j + col[k]));
			}
		}
	}
	
}

// O(RC) 
int countNumberOfIsland (int graph[R][C]) {

	
	int i,j,k, res = 0;

	int visited[R][C];
	for (i = 0 ; i < R ; i++) {
		for (j= 0 ; j < C ; j++) {
			visited[i][j] = 0;
		} 
	}

	for (i = 0 ; i < R ; i++) {
		for (j = 0 ; j < C ; j++) {
			if (graph[i][j] && !visited[i][j]) {
				BFS(graph, visited, i , j);
				res ++;
			}
		}
	}

	return res;
	
}

int main () {

	int graph[R][C] = {{1,1,0,0,0},
					   {0,1,0,0,1},
	 				   {1,0,0,1,1},
					   {0,0,0,0,0},
					   {1,0,1,0,1}};

	cout << "Number of islands " << countNumberOfIsland(graph) << endl;

	return 0 ;
}
