https://www.geeksforgeeks.org/spanning-tree-with-maximum-degree-using-kruskals-algorithm/
#include <iostream>
#include <vector>
using namespace std;

#define V 5
vector<int> adj[V];

void addEdge(int u , int v) {
	adj[u].push_back (v);
	adj[v].push_back (u);
}


//O(E)
int findParent (vector<int> &parent, int x) {

	if (parent[x] == -1) {
		return x;
	}

	return findParent (parent, parent[x]);
}

//O(E)
void Union (vector<int> &parent, int x, int y) {
	int xSet = findParent (parent, x);
	int ySet = findParent (parent, y);

	if (xSet != ySet) {
		parent[xSet] = ySet;
	}
}

//O(VE) 
void findSPTWithMaxDegree () {
	vector<int> parent (V, -1);
	vector<int> degree(V,0);
	int i,j,max = 0, u , v;

	for (i = 0 ; i < V; i++) {
		for (j = 0 ; j < adj[i].size() ; j++) {
			degree[adj[i][j]] ++;
		}
	}	

	for (i = 1 ; i < V ; i++) {
		if(degree[i] > degree[max]) {
			max = i;
		}
	}

	for (i = 0 ; i < adj[max].size () ; i++) {
		cout << max << " - " << adj[max][i] << endl;
		Union (parent, max, adj[max][i]);
	}

	for (i = 0 ; i < V; i++) {
		for (j = 0 ; j < adj[i].size() ; j++) {
			u = findParent(parent, i) ;
			v = findParent(parent, adj[i][j]);

			if (u != v) {
				Union (parent, u , v);
				cout << i << " - " << adj[i][j] << endl;
			}
		}
	}
}

int main () {
		
	addEdge (0,1);
	addEdge (0,4);
	addEdge (1,2);
	addEdge (4,2);
	addEdge (2,3);

	findSPTWithMaxDegree ();

	return 0 ;
}
