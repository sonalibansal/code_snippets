//https://practice.geeksforgeeks.org/problems/steps-by-knight/0
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define n 7
bool vis[n][n];
int dist[n][n];

class Node{
	public:
	int x;
	int y;
	
	Node(int x, int y) {
		this -> x = x;
		this -> y = y;
	}
};

bool isSafe(int i, int j) {
	return (i >= 0 && i < n && j >=0 && j < n && !vis[i][j]);
}

int minDistance(Node src, Node dest) {
	dist[src.x][src.y] = 0;
	queue<Node> q;
	q.push(src);
	
	vis[src.x][src.y] = true;
	
	while(!q.empty()) {
		Node top = q.front();
		q.pop();
		
		int row[] = {-2,-2,2,2,1,1,-1,-1};
		int col[] = {1,-1,-1,1,2,-2,2,-2};
		
		for(int k = 0 ; k < 8 ; k++) {
			int i = row[k]+top.x;
			int j = col[k]+top.y;
			if(isSafe(i, j)) {
				q.push(Node(i, j));
				vis[i][j] = true;
				dist[i][j] = dist[top.x][top.y] +1;
			}
		}
	}
	return dist[dest.x][dest.y];
	
}
int main() {
	memset(vis, false, sizeof(vis));
	
	Node src(4,5);
	Node dest(1,1);
	
	//Node src(5, 7);
	//Node dest(15, 20);
	
	cout << minDistance(src, dest);
	return 0;
}