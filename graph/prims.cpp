#include <iostream>
#include <vector>
#include <utility> 
#include <climits>
#include <queue>
using namespace std;
 
#define V 3

class Node
{
public:
	int id;
	int weight;
	int parent;

	Node(int id, int weight, int parent) {
		this -> id = id;
		this -> weight = weight;
		this -> parent = parent;
	}
};

vector<Node> adj[V];

bool operator< (Node A, Node B) {
	if (A.weight != B.weight) {
		return A.weight > B.weight;
	}
	return A.id > B.id;
}

 // O (1)
void addEdge (int v, int w, int cost) {
	adj[v].push_back (Node (w, cost, -1));
	adj[w].push_back (Node (v, cost, -1));
}

// O(E log V) where V is the total number of vertices and E is the number of edges. 
void prims (int src) {

	priority_queue<Node> pq;
	vector<int> dist(V, INT_MAX);
	vector<bool> sptSet(V, false);

	dist[src] = 0;
	pq.push(Node(src, 0 , -1));
	vector<Node> ::iterator it;

	while (!pq.empty()) {
		Node top = pq.top ();
		int u = top.id;
		pq.pop ();
		if (!sptSet[u]) {
			sptSet[u] = true;
			dist[u] = top.weight;
			for (it = adj[u].begin(); it != adj[u].end() ;it++) {
				Node element = *it;
				int key = element.id;
				int cost = element.weight;
				if (!sptSet[key]) {
					pq.push(Node(key, cost , u));
				}

			}
			if (top.parent != -1) {
				cout << top.parent << "-" << top.id << " " << top.weight << endl;
			}
		}
		
	}
}

int main()  {

	addEdge (0,1,4);
	addEdge (0,7,8);
	addEdge (1,2,8);
	addEdge (1,7,11);
	addEdge (7,8,7);
	addEdge (7,6,1);
	addEdge (2,8,2);
	addEdge (2,5,4);
	addEdge (2,3,7);
	addEdge (6,8,6);
	addEdge (6,5,2);
	addEdge (5,3,14);
	addEdge (5,4,10);
	addEdge (4,3,9);
   
	prims(0);

	return 0;
}
