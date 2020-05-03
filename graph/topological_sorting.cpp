#include <iostream>
#include <vector>
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


// O(V) where V is the number of Vertices. 
void topologicalUtil (int key, vector<bool> &visited , stack<int> &s) {

	visited [key] = true;
	for (int i = 0 ; i < adj[key].size() ; i++) {
		if (!visited[adj[key][i]]) {
			topologicalUtil (adj[key][i], visited , s);
		}
	}

	s.push (key);
}

// O(V+ E) where V is the number of Vertices and E is the number of edges
void topologicalSorting () {
	vector<bool> visited(V, false);

	stack<int> s;

	for (int i = 0 ; i < V ; i++) {
		if (! visited[i]) {
			topologicalUtil (i, visited, s);
		}
	}

	cout << "topological sorting of the graph" << endl;

	while (! s.empty ()) {
		cout << s.top () << " ";
		s.pop ();
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
