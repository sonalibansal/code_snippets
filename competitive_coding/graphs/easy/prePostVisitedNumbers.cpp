#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits>
#include <stack>
#include <queue>
using namespace std;

#define V 6

class Node {
	public:
		int id;
		int preVisitId;
		int postVisitId;

		Node (int id, int preVisitId , int postVisitId) {
			this -> id = id;
			this -> preVisitId = preVisitId;
			this -> postVisitId = postVisitId;
		}
};

vector<Node> adj[V];

// O(1)
void addEdge(int u , int v) {
	adj[u].push_back (Node (v, -1, -1));
	adj[v].push_back (Node (u, -1, -1));
}

void DFSUtil (Node vertex, int &pos, vector<bool> &visited) {
	visited[vertex.id] = true;
	vertex.preVisitId = ++ pos;
	for (int i = 0 ; i < adj[vertex].size() ; i++) {
		Node n = adj[vertex][i];
		if (!visited[n.id]) {	
			DFSUtil (n, pos, visited);
		}
	}

	vertex.postVisitId = ++ pos;
}

void DFS (int src) {

	vector<bool> visited(V, false);
	int pos = 0;

	for (int i = 1 ; i < = V ; i++) {
		if (!visited[adj[i].id]) {
			DFSUtil (n, pos, visited);
		}
	}

	for (int i = 0 ; i < adj.size() ; i++)  {
		Node n = adj[i];
		cout << n.id << "Pre number = " << n.preVisitId << "Post number = " << n.postVisitId << endl;
	}
}


int main () {

	addEdge (1,2);
	addEdge (1,3);
	addEdge (2,4);
	addEdge (3,4);
	addEdge (3,5);
	addEdge (5,6);

	DFS (1); 
	return 0 ;
}



