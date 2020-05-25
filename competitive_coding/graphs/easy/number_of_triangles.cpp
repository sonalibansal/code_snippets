//https://www.geeksforgeeks.org/number-of-triangles-in-directed-and-undirected-graphs/
#include <iostream>

using namespace std;

#define V 4

// O(V^3)
int numberOfTriangles (int graph[V][V],
	bool directed) {

	int i, j, k, count = 0;

	for (i = 0 ; i < V ; i++) {
		for (j = 0 ; j < V; j ++) {
			for (k = 0 ; k < V ; k++) {
				if (graph[i][j] && graph[j][k] && graph[k][i]) {
					count ++;
				}
			}
		}
	}


	if (directed) {
		return count/3;
	} else {
		return count/6;
	}
}

int main () {
	int digraph[V][V] = { {0, 0, 1, 0},
                        {1, 0, 0, 1},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0}
                      };

    cout << "Number of triangles " << numberOfTriangles (digraph, true) << endl;

    return 0;
 
}