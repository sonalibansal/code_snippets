#include <iostream>
#include <vector>
#include <queue>
#include <utility> 
#include <stack>
#include <climits>
using namespace std;
 
#define V 6
vector<int> adj[6];

 // O (1)
void addEdge (int v, int w) {
	adj[v].push_back (w);
}

// O(V + E) where V is the number of Vertices and E is the number of edges
// In worst case E = V-1 so time complexity = O(V^2)
void topologicalSorting () {
	vector<int> indegree(V,0);
	vector<int> result;
	queue<int> q;
	int i,j,top;

	for (i = 0 ; i < V ; i++) {
		for (j = 0 ; j < adj[i].size() ; j++) {
			indegree[adj[i][j]] ++;
		}
	}

	for (i = 0 ; i < V ; i++) {
		if(indegree[i] == 0 ) {
			q.push (i);
		}
	}

	while (!q.empty()) {
		top = q.front();
		q.pop ();
		result.push_back (top);

		for (i = 0 ; i < adj[top].size(); i++) {
			indegree[adj[top][i]]--;

			if (indegree[adj[top][i]] == 0) {
				q.push (adj[top][i]);
			}
		}
	}

	cout << "topological sorting of the graph" << endl;

	if (result.size () != V) {
		cout << "topo sort of the graph is not possible" << endl;
	}

	for (i = 0 ; i < V ; i++) {
		cout << result[i] << endl;
	}

}

int main()  {

	addEdge (5,0);
	addEdge (5,2);
	addEdge (4,0);
	addEdge (4,1);
	addEdge (2,3);
	addEdge (3,1);
   
	topologicalSorting();

	return 0;
}
