//https://www.geeksforgeeks.org/minimum-weighted-graph/
#include <iostream>
#include <limits>
using namespace std;

#define V 4
int adj[V][V] = {0,3,2,5,0,2,4,7,1,2,0,3,5,2,1,3};

// O(V^2)
void removeOutgoingEdges () {
	int minIndex = -1;
	int minElement = INT_MAX, i, j;
	for (i = 0 ; i < V ; i++) {
		minIndex = -1;
		minElement = INT_MAX;
		for (j = 0 ; j < V; j++) {
			if (adj[i][j] < minElement && adj[i][j]) {
				minElement = adj[i][j];
				minIndex = j;
			}
		}
		for (j = 0 ; j < V; j++) {
			if (j != minIndex) {
				adj[i][j] = 0;
			}
		}
 	}

 	for (i = 0 ; i < V ; i++) {
		for (j = 0 ; j < V; j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}

int main () {

	removeOutgoingEdges ();

	return 0;
}