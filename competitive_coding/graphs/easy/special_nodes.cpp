//https://www.geeksforgeeks.org/number-of-special-nodes-in-an-n-ary-tree/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits>
#include <queue>
using namespace std;

#define V 10
vector<int> adj[V];

// O(1)
void addEdge(int u , int v) {
	adj[u].push_back (v);
}

// O(n) where n is the number of nodes
void specialNodes (vector<int> &val, unordered_set<int> &values, int v, int &ans) {

	if (values.count(val[v])) {
		return ;
	}

	ans++;
	values.insert (val[v]);

	for (int i = 0 ; i < adj[v].size (); i++) {
		specialNodes (val, values , adj[v][i], ans);
	}

	values.erase (val[v]);

}

int main () {
	vector<int> val {0,2,1,4,3,4,8,10,2,5,1};

	addEdge (2,4);
	addEdge (2,5);
	addEdge (2,6);
	addEdge (1,2);
	addEdge (1,3);
	addEdge (3,7);
	addEdge (3,8);
	addEdge (3,9);
	addEdge (3,10);

	int ans = 0 , v = 1;

	unordered_set<int> values;
	specialNodes (val, values, v, ans);

	cout << "Number of special nodes = " << ans -1 << endl;

	return 0 ;
}