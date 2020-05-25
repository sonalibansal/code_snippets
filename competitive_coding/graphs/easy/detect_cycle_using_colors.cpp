//https://www.geeksforgeeks.org/detect-cycle-direct-graph-using-colors/ 
#include <iostream>
#include <vector>
#include <utility> 
#include <stack>
#include <climits>
using namespace std;
 
#define V 4
vector<int> adj[V];

enum Color {WHITE, GRAY, BLACK}; 


 // O (1)
void addEdge (int v, int w) {
	adj[v].push_back (w);
	adj[w].push_back (v);
}

// O(V+E)
bool DFSUtil (int key, vector<int> &color) {

	color[key] = GRAY;

	for (int i = 0 ; i < adj[key].size () ; i++) {
		if (color[adj[key][i]] == GRAY) {
			return true;
		}

		if (color[adj[key][i]] == WHITE && DFSUtil (adj[key][i], color)) {
			return true;
		}
	}

	color[key] = BLACK;
	return false;
}

// O(V+E)
bool isCyclic () {
	vector<int> color (V, WHITE);

	for (int i = 0 ; i < V ; i++) {
		if (color[i] == WHITE) {
			if (! DFSUtil (i, color)) {
				return false;
			}

		}
	}
	return true;
}

int main () {
	addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 2); 
    addEdge(2, 0); 
    addEdge(2, 3); 
    addEdge(3, 3);

    if (isCyclic ()) {
    	cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
    }
    return 0;
}