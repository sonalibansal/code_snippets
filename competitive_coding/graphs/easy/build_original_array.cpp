// https://www.geeksforgeeks.org/build-original-array-from-the-given-sub-sequences/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define V 6

vector<int> adj[V];

// O(1)
void addEdge (int v, int w) {
	adj[v].push_back (w);
}

//O(V+E) where V is the number of Vertices and E is the number of edges
void buildOriginalArray() {

	vector<int> indegree(V, 0);
	vector<int> result;
	queue<int> q;
	int i,j;

	// O(V+E) 
	for (i = 0 ; i < V ;i++) { //O(V)
		for (j = 0 ; j < adj[i].size() ;j++) { // O(E)
			indegree[adj[i][j]]++;
		}
	}

	//O(V) where V is the number of Vertice
	for (i = 0 ; i < V ;i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	// O(V+E) as number of elements pushed in this queue is O(V)
	// and E is the total number of edges in the graph
	while (!q.empty ()) {
		int top = q.front ();
		q.pop ();
		result.push_back (top);

		for (i = 0 ; i < adj[top].size () ; i++) {
			indegree [adj[top][i]] --;

			if (indegree[adj[top][i]] == 0) {
				q.push (adj[top][i]);
			}
		}

	}

	for (i = 0 ; i < V ; i++) {
		cout << result[i] << " ";
	}
}

int main () {

	vector<vector<int> > subsequence {{1, 2, 3},
									   {1, 2},
									   {3, 4},
									   {5, 2},
									   {0, 5, 4}};


	for (int i = 0 ; i < subsequence.size() ; i++) {
		for (int j = 0 ; j < subsequence[i].size()-1 ; j++) {
			addEdge (subsequence[i][j], subsequence[i][j+1]);
		}
	}

	buildOriginalArray (); // 0 1 5 2 3 4

	return 0;
}