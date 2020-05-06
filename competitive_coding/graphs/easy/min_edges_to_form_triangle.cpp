// https://www.geeksforgeeks.org/minimum-number-of-edges-that-need-to-be-added-to-form-a-triangle/
#include <iostream>
#include <vector>
#include <utility> 
#include <climits>
using namespace std;
 
#define V 3
vector<int> adj[V];

 // O (1)
void addEdge (int v, int w) {
	adj[v].push_back (w);
	adj[w].push_back (v);
}

// This program finds out the min numbers of edges required to form a triangle
// O(V^3)
int min_edges () {
	int ans = 3;
	bool edge1Present, edge2Present, edge3Present;

	for (int i = 0 ; i < V ;i++) {
		for (int j = i+1 ;j < V; j++) {
			for (int k = j+1; k < V; k++) {
				edge1Present = adj[i][j];
				edge2Present = adj[j][k];
				edge3Present = adj[k][i];
				if ( edge1Present && edge2Present && edge3Present) {
					return 0;
				}

				if ((edge1Present && !edge2Present && !edge3Present) 
					|| (edge2Present && !edge1Present && !edge3Present)
					|| (edge3Present && !edge1Present && !edge2Present)) {
					ans =  min(ans, 2);
				}

				if (!edge1Present && !edge2Present && !edge3Present) {
					ans = min (ans, 3);
				}

				if ((edge1Present && edge2Present && !edge3Present)
					|| (edge2Present && edge3Present && !edge1Present)
					|| (edge3Present && edge1Present && !edge2Present)) {
					ans = min (ans, 1);
				}
			}
		}
	}
	return ans;

}


int main()  {

	addEdge (0,1);
	addEdge (0,2);

	cout << "Min edges required to form a triangle is "  << min_edges () << endl;

	return 0;
}
