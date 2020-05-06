#include <iostream>
#include <vector>

using namespace std;

#define V 4
vector<int> adj[V];


// O (1)
void addEdge (int v, int w) {
	adj[v].push_back (w);
}


// O(V^2)
int isGraphConnected () {

	int i,j;
	vector<int> indegree(V,0);
	vector<int> outdegree(V,0);

	for (i = 0 ; i < V ;i++) {
		for (j = 0 ; j < adj[i].size() ;j++) {
			indegree[adj[i][j]]++;
			outdegree[i]++;
		}
	}

	for (i = 0 ; i < V ; i++) {
		if (indegree[i] == 0 && outdegree[i] == 0) {
			return 0 ;
		}
	}

	return 1;
}

// O(V) 
void DFSUtil (int src, vector<bool> &visited) {

	visited[src] = true;
	for (int i = 0; i < adj[src].size() ; i++) {
		if(!visited[adj[src][i]]) {
			DFSUtil (adj[src][i], visited);
		}
	}
}

int isGraphConnectedOptimised () {
	vector <bool> visited(V, false);

	DFSUtil (0, visited);
	for (int i = 0 ; i < V ;i++) {
		if(!visited[i]) {
			return 0;
		}	
	}

	return 1;
}

int main () {

	addEdge (0,1);
	addEdge (1,2);
	//addEdge (2,3);
	addEdge (0,2);

	if (isGraphConnected()) {
		cout << "Graph is connected" << endl;
	}else {
		cout << "Graph is not connected " << endl;
	}

	if (isGraphConnectedOptimised()) {
		cout << "Graph is connected" << endl;
	}else {
		cout << "Graph is not connected " << endl;
	}
}