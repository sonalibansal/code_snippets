//https://www.geeksforgeeks.org/detecting-negative-cycle-using-floyd-warshall/
#include <iostream>
#include <climits>
using namespace std;

#define INT_MAX 10000
#define V 4

bool checkForNegativeCycle (int graph[V][V]) {

	int i, j, k;
	int dist[V][V];

	for (i = 0 ; i < V ; i++) {
		for (j = 0 ; j < V ; j++) {
			dist[i][j] = graph[i][j];
		}
	}

	for (k = 0; k < V ; k++) {
		for (i = 0 ; i < V ; i++) {
			for (j = 0 ; j < V ; j++) {
				dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (i = 0 ; i < V ; i++) {

		if (dist[i][i] < 0) {
			return true;
		}
	}
	return false;
}

int main () {

	int graph[V][V] = { {0, 1, INT_MAX, INT_MAX},
						{INT_MAX, 0, -1, INT_MAX},
						{INT_MAX, INT_MAX, 0, -1},
						{-1, INT_MAX, INT_MAX,0}
					  };

	if (checkForNegativeCycle (graph)){
		cout << "YES" << endl;

	}else {
		cout << "NO" << endl;
	}

	return 0;			  
}