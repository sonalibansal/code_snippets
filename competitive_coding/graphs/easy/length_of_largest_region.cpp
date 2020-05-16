//https://www.geeksforgeeks.org/find-length-largest-region-boolean-matrix/

#include <iostream>
#include <queue>
#include <climits>
#include <unordered_map>
using namespace std;

#define R 4
#define C 5

unordered_map <int, int > m;

// O(1)
int isSafe (int graph[R][C], bool visited[R][C], int i , int j ) {

	return (i >= 0 && i < R 
	&& j >= 0 && j < C 
	&& graph[i][j] && !visited[i][j]);
}

// O(RC)
void BFS (int graph[R][C], bool visited[R][C], int compNumber, int src, int dest) {

	int row[] = {-1,-1,-1,0,1,1,1,0};
	int col[] = {-1,0,1,1,1,0,-1,-1};
	int i,j,k;

	queue<pair<int, int > > q;
	pair<int, int > top;

	q.push (make_pair (src, dest));
	visited[src][dest] = true;

	while (!q.empty ()) {

		top = q.front ();
		q.pop ();

		i = top.first;
		j = top.second;

		for (k = 0 ; k < 8 ; k++) {
			if (isSafe(graph, visited, i + row[k], j + col[k]))  {
				visited[i + row[k]][j + col[k]] = 1;
				q.push (make_pair(i + row[k], j + col[k]));
				m[compNumber] ++;
			}
		}
	}
}


// O(RC)
int islands (int graph[R][C]) {

	bool visited[R][C];

	int res = 0, i, j;

	for (i = 0 ;i < R ; i++) {
		for (j = 0; j < C; j++) {
			visited[i][j] = false;
		}
	}

	for (i = 0 ;i < R ; i++) {
		for (j = 0; j < C; j++) {
			if (graph[i][j] && !visited[i][j]) {
				res ++;
				m.insert ({res, 1});	
				BFS (graph, visited, res, i , j);	
			}
		}
	}

	int largest = INT_MIN;
	for (i = 0 ; i < m.size() ; i++) {
		if (largest < m[i]) {
			largest = m[i];
		}
	}
	return largest;
}


int main () {

	int M[][5] = { {0,0,1,1,0},
				   {1,0,1,1,0},
				   {0,1,0,0,0},
				   {0,0,0,0,1}};

	int largestLength = islands (M);
	cout << largestLength << endl;

}