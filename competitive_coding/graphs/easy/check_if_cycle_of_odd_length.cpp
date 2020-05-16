//https://www.geeksforgeeks.org/check-graphs-cycle-odd-length/
#include <iostream> 
#include <queue>
#include <vector>
using namespace std;

#define V 4

vector<int> adj[V];

//O(1)
void addEdge (int u , int v) {
	adj[u].push_back (v);
	adj[v].push_back (u);
}

//O(V+E)
bool BipartiteUtil (int src, vector<int> &color) { 

	queue<int> q;
	int top, element;

	q.push (src);
	color[src] = 0 ;

	while (! q.empty()) {
		top = q.front();
		q.pop ();

		if (find (adj[top].begin(), adj[top].end(), top) != adj[top].end()) {
			return false;
		}

		for (int i = 0 ; i < adj[top].size () ;i++) {
			element = adj[top][i];
			if (color[element] == -1) {
				color[element] = 1 - color[top];
				q.push (element);
			} else if (color[element] == color[top]){
				return false;
			}
		}
	}

	return true;
}

int main () {

	vector<int> color(V ,-1);

	addEdge (0,1);
	addEdge (0,3);
	addEdge (1,2);
	addEdge (2,3);

	if (BipartiteUtil (0, color)) {
		cout << "NO" << endl;
	}else {
		cout << "YES" << endl;
	}

	return 0;
}