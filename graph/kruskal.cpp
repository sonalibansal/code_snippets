#include <iostream>
#include <vector>
#include <utility> 
#include <climits>
#include <queue>
using namespace std;
 
#define V 9

// 1. Sort all the edges in increasing order of their weight.
// 2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it.
// 3. Repeat step#2 until there are (V-1) edges in the spanning tree

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
priority_queue<Node> pq;

// O(1)
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
	pq.push (Node (v, cost, w));
}


// O(E) where E is the number of Vertices
int findParent (vector<int> &parent, int i ) {
	if (parent [i] == -1) {
		return i;
	}

	return findParent (parent, parent[i]);
}

// O (E)
void Union (vector<int> &parent, int x , int y) {
	int xset = findParent (parent, x);
	int yset = findParent (parent, y);

	if (xset != yset) {
		parent [xset] = yset;
	}
}

// O(E log V) where V is the total number of vertices and E is the number of edges. 
void Kruskal (int src) {

	vector<int> parent (V, -1);

	while (!pq.empty ()) {
		Node top = pq.top ();			
		cout << top.weight << endl;
		int x = findParent (parent, top.id);
		int y = findParent (parent, top.parent);
		if (x != y) {
			Union (parent, x, y);
			cout << top.id << "-" << top.parent << " " << top.weight << endl;
		}

		pq.pop ();
	}
}

int main()  {

	addEdge (0,1,1);
	addEdge (0,2,5);
	addEdge (2,1,6);

	// addEdge (0,1,4);
	// addEdge (0,7,8);
	// addEdge (1,2,8);
	// addEdge (1,7,11);
	// addEdge (7,8,7);
	// addEdge (7,6,1);
	// addEdge (2,8,2);
	// addEdge (2,5,4);
	// addEdge (2,3,7);
	// addEdge (6,8,6);
	// addEdge (6,5,2);
	// addEdge (5,3,14);
	// addEdge (5,4,10);
	// addEdge (4,3,9);
   
	Kruskal(0);

	return 0;
}
