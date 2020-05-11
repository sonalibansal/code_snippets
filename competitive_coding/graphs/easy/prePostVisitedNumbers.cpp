// https://www.geeksforgeeks.org/printing-pre-and-post-visited-times-in-dfs-of-a-graph/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits>
#include <stack>
#include <queue>
using namespace std;

#define V 6

int preVisitId[V+1];
int postVisitId[V+1];
vector<int> adj[V];

// O(1)
void addEdge(int u , int v) {
	adj[u].push_back (v);
	adj[v].push_back (u);
}

// O(V+E)
void DFSUtil (int key, int &pos, vector<bool> &visited) {
	visited[key] = true;
	preVisitId[key] = ++ pos;
	for (int i = 0 ; i < adj[key].size() ; i++) {
		if (!visited[adj[key][i]]) {	
			DFSUtil (adj[key][i], pos, visited);
		}
	}
	postVisitId[key] = ++ pos;
}

void DFS (int src) {

	vector<bool> visited(V, false);
	int pos = 0;
	for (int i = 1 ; i <= V ; i++) {
		if (!visited[i]) {
			DFSUtil (i, pos, visited);
		}
	}

	for (int i = 1 ; i <= V ; i++) {
		cout << i << " Pre number = " << preVisitId[i] << "Post number = " << postVisitId[i] << endl;
	 }

}


int main () {

	addEdge (1,2);
	addEdge (1,3);
	addEdge (2,4);
	addEdge (3,4);
	addEdge (3,5);
	addEdge (5,6);

	DFS (1); 

	// 1 Pre number = 1Post number = 12
	// 2 Pre number = 2Post number = 11
	// 3 Pre number = 4Post number = 9
	// 4 Pre number = 3Post number = 10
	// 5 Pre number = 5Post number = 8
	// 6 Pre number = 6Post number = 7
	return 0 ;
}



