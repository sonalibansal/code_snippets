// https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define V 4
vector<int> adj[V];


//O(1)
void addEdge (int u , int v) {
	adj[u].push_back (v);
	adj[v].push_back (u);
}


int isSafe (int v, int c, vector<int> &color) {
	for (int i = 0 ; i < adj[v].size (); i ++) {
		if (color[adj[v][i]] == c) {
			return false;
		}
	}
	return true;
}

// O(V+E) 
bool mColoringUtil (vector<int> &color, int v , int m) {
	
	if (v == V) {
		return true;
	}

	for (int i = 1; i <= m ; i++) {
		if (isSafe(v, i, color)) {
			color[v] = i;
			if (mColoringUtil (color, v+1, m)) {
				return true;
			}
			color[v] = 0;
		}
	}
	return false;

}

void printColors (vector<int> color) {
	for (int i = 0 ; i < V ; i++) {
		cout << color[i] << " " ;
	}
}

void solveMColoringProblem (int m) {
	vector<int> color (V, 0);

	if (mColoringUtil (color, 0, m) ) {
		printColors (color);
	} else {
		cout << "Solution does not exist" << endl;
	}
	
}

int main () {

	addEdge (0,1);
	addEdge (1,2);
	addEdge (2,3);
	addEdge (0,2);
	addEdge (0,3);

	solveMColoringProblem (3); // 1 2 3 2

	return 0;
}