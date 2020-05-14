//https://www.geeksforgeeks.org/find-degree-particular-vertex-graph/
#include <iostream>
using namespace std;

#define V 4


// O(V)
int main () {

	int adj[V][V] = {{0,1,1,1},
					 {1,0,0,1},
					 {1,0,0,1},
					 {1,1,1,0}
					};

	int vertex = 0, count = 0;

	for (int i = 0 ; i < V ; i++) {
		if (adj[vertex][i]) {
			count ++;

		}
	}

	cout << "Number of vertex " << count << endl;

}