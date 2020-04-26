#include <iostream>
#include <list>
#include <queue>

using namespace std;


class  Graph
{

	int V;
	list<int> *adj;

public:
	 Graph (int V);

	 // O (1)
	 void addEdge (int v, int w) {
	 	adj[v].push_back (w);
	 	adj[w].push_back (v);
	 }

	 void BFS (int s);
	
};



Graph :: Graph (int V) {
	this -> V = V;
	adj = new list<int> [V];
}


// 0(V+E) where is the number of vertices in the graph and 
// E is the total number of edges.
// Worst case time complexity : O(V^2)
void Graph :: BFS (int s) {
	int *visited = new int[V];

	for (int i = 0 ; i < V ;i++) {
		visited [i] =0;
	}
	queue<int> q;
	list<int> :: iterator it;

	q.push (s);
	visited[s] = 1;

	while (! q.empty()) {

		s = q.front ();
		cout << s << " ";
		q.pop ();

		for (it = adj[s].begin(); it != adj[s].end(); it++) {
			if (!visited[*it]) {
				q.push (*it);
				visited [*it] = 1;
			}
		};

	}

}

int main () {

	Graph g(4);

	g.addEdge (0,2);

	g.addEdge (2,3);

	g.addEdge (0,1);

	g.addEdge (1,2);

	cout << "BFS of the graph" << "\n";
	g.BFS (0);
}