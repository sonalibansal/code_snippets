//https://www.geeksforgeeks.org/sum-of-the-minimum-elements-in-all-connected-components-of-an-undirected-graph/
#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
using namespace std;

#define V 10
vector<int> adj[V];
unordered_map <int, int> m;

void addEdge (int u , int v) {
	adj[u].push_back (v);
	adj[v].push_back (u);
}

// void DFSUtil (int key, int c, vector<bool> &visited) {
 	
// 	visited[key] = true;
// 	cout << m[c] << " for key = "<< key << "and c= " << c <<  endl;
// 	if (key < m[c]) {
// 		m[c] = key;
// 	}

// 	for (int i = 0 ; i < adj[key].size (); i++) {
// 		if (!visited[adj[key][i]]) {
// 			DFSUtil (adj[key][i], c , visited);
// 		}
// 	}	

// }

void componentsMinElementSum (vector<int> &arr) {

	vector<bool> visited(V+1, false);
	int c = 1;

	for (int i = 0 ; i < arr.size() ; i++) {
		if (!visited[arr[i]]) {
			cout << "inside if block" << endl;
			m.insert ({c, INT_MAX});
			cout << m[c] << endl;
			//DFSUtil (arr[i], c, visited);
			c++;
		}
	}

	// int sum = 0;
	// for (int i = 0 ; i < map.size () ; i++) {
	// 	sum = sum + map[i];
	// }

	// cout << sum << endl;

}

int main () {

	vector<int> arr{1, 6, 2, 7, 3, 8, 4, 9, 5, 10};
	int m = 5;

	unordered_map<int, int> map;
	map.insert ({1,2});
	map.insert ({m, 4});

	cout << map[5] << endl;

	addEdge (1,2);
	addEdge (3,4);
	addEdge (5,6);
	addEdge (7,8);
	addEdge (9,10);

	componentsMinElementSum (arr);

}