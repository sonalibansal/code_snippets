#include <iostream>
#include <vector>
#include <utility> 
#include <stack>
#include <climits>
using namespace std;
 
#define V 3
vector<int> adj[3];

 // O (1)
void addEdge (int v, int w) {
	adj[v].push_back (w);
	adj[w].push_back (v);
}


// O(V) where V is the number of Vertices
int findParent (vector<int> &parent, int i ) {
	if (parent [i] == -1) {
		return i;
	}

	return findParent (parent, parent[i]);
}


// O(V) as time complexity of findPArent is O(V)
void Union (vector<int> &parent, int x , int y) {
	int xset = findParent (parent, x);
	int yset = findParent (parent, y);

	if (xset != yset) {
		parent [xset] = yset;
	}
}

// O(V^2)
int isCycle () {
	vector<int> parent (V, -1);

	for (int i = 0 ; i < V ; i++) {
		for (int j = 0 ; i < adj[i].size () ; i++) {
			int x = findParent (parent, i);
			int y = findParent (parent, adj[i][j]);

			if (x == y) {
				return 1;
			}

			Union (parent, x , y);
		}
	}

	return 0;
}

int main()  {

	addEdge (0,1);
	addEdge (1,2);
	addEdge (0,2);
	
	if (isCycle() ) {
		cout << "cycle is present" << endl;
	 }

	return 0;
}
