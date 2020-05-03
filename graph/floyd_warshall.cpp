#include <iostream>
#include <climits>
using namespace std;

#define INT_MAX 10000
#define V 4

// Time complexity : O(V^2)
void printSolution (int dist[V][V]) {
	for (int i = 0 ; i < V; i++) {
		for (int j = 0 ; j < V ; j++) {
			if (dist[i][j] == INT_MAX) {
				cout << "INT_MAX" << " ";
			}else {
				cout << dist[i][j] << " " ;
			}
		}
		cout << "\n";
	}
}


// Time complexity : O(V^3)
void floyd (int graph[V][V]) {
	int i, j, k;
	int dist[V][V];

	for (i = 0 ;i < V ;i++) {
		for (j = 0; j < V ;j++) {
			dist[i][j] = graph[i][j];
		 }	
	 }

	for (k = 0 ; k < V ; k++) {
		for (i = 0 ; i < V ; i++) {
			for (j = 0 ; j < V ; j++) {
					dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
			 }
		 }
	 }

	printSolution (dist);
}

int main()  {

	int graph[V][V] = { {0, 5, INT_MAX, 10},
						{INT_MAX, 0, 3, INT_MAX},
						{INT_MAX, INT_MAX, 0, 1},
						{INT_MAX, INT_MAX, INT_MAX,0}
					  };

	floyd(graph);

	return 0;
}