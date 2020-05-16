//https://www.geeksforgeeks.org/sum-of-the-minimum-elements-in-all-connected-components-of-an-undirected-graph/
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

#define V 10
vector<int> adj[V];
unordered_map <int, int> m;

//O(1)
void addEdge (int u , int v) {
	adj[u].push_back (v);
	adj[v].push_back (u);
}

//O(V+E)
void DFSUtil (int key, int c, vector<bool> &visited, vector<int> &arr) {
 	
	visited[key] = true;
	if (key < m[c]) {
		m[c] = arr[key-1];
	}

	for (int i = 0 ; i < adj[key].size (); i++) {
		if (!visited[adj[key][i]]) {
			DFSUtil (adj[key][i], c , visited, arr);
		}
	}	

}

//O(V+E)
void componentsMinElementSum (vector<int> &arr) {

	vector<bool> visited(V+1, false);
	int c = 1;

	for (int i = 1; i <= V ; i++) {
		if (!visited[i]) {
			m.insert ({c, INT_MAX});
			DFSUtil (i, c, visited, arr);
			c++;
		}
	}

	int sum = 0;
	for (int i = 0 ; i < m.size () ; i++) {
		sum = sum + m[i];
	}

	cout << sum << endl;

}

int main () {

	vector<int> arr{1, 6, 2, 7, 3, 8, 4, 9, 5, 10};

	addEdge (1,2);
	addEdge (3,4);
	addEdge (5,6);
	addEdge (7,8);
	addEdge (9,10);

	componentsMinElementSum (arr);

}