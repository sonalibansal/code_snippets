#include <iostream>
#include <list>
using namespace std;

class  Graph {
	int V;
	list<int> *adj;

	void DFSUtil (int s, int *visted);
public:
	Graph (int V) {
		V = V;
		adj = new list<int>[V];
	}

	void addEdge (int v, int w) {
		adj[v].push_back (w);
	}

	void DFS (int s);	
};


void Graph :: DFSUtil (int s, int *visited) {

	cout << "DFS util function " << "\n";
	visited[s] = 1;

	list<int> :: iterator it;

	cout << s << " ";

	for (it = adj[s].begin (); it != adj[s].end(); it++) {
		if (!visited [*it]) {
			DFSUtil (*it, visited);	
		}
	}
}
void Graph :: DFS (int s) {

	int *visited;
	visited = new int[V];
	
	for (int i = 0; i< V ; i++) {
		visited [i] = 0;
	}

	DFSUtil (s, visited);
}

int main () {
	Graph g(4);

	g.addEdge (0,2);

	g.addEdge (2,3);

	g.addEdge (0,1);

	g.addEdge (1,2);

	cout << "DFS of the graph" << "\n";
	g.DFS (2);
}
