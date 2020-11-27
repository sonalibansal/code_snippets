#include <iostream>
#include <queue>
using namespace std;

int arr[3][5] = {{2,1,0,2,1},
				 {0,0,1,2,1},
				 {1,0,0,2,1}};
int R = 3, C = 5;
class Node {
	public:
	int x;
	int y;
	
	Node(int x, int y) {
		this -> x = x;
		this -> y = y;
	}
};

bool isFresh(int i, int j) {
	return (i >= 0 && i < R && j>=0 && j < C && arr[i][j] == 1);
}

int minTime() {
	int row[] = {-1,1,0,0};
	int col[] = {0,0,-1,1};
	queue<Node> q;
	for(int i = 0 ; i < R; i++) {
		for(int j = 0 ; j < C ; j++) {
			if(arr[i][j] == 2) {
				for(int k = 0; k < 4; k++) {
					if(isFresh(row[k]+i, col[k]+j)) {
							arr[row[k]+i][col[k]+j] = arr[i][j]+1;
							q.push(Node(row[k]+i, col[k]+j));
						}
				}
			}
		}
	}
	
	while(!q.empty()) {
		Node top = q.front();
		int i = top.x;
		int j = top.y;
		for(int k = 0; k < 4; k++) {
			if(isFresh(row[k]+i, col[k]+j)) {
				arr[row[k]+i][col[k]+j] = arr[i][j]+1;
				q.push(Node(row[k]+i, col[k]+j));
			}
		}
		
	}

	int max = 2;
	for(int i = 0 ; i < R; i++) {
		for(int j = 0 ; j < C ; j++) {
			if(arr[i][j] == 1) {
					return -1;
			}
			if(arr[i][j] > max) {
				max = arr[i][j];
			}
		}
	}
	return max -2 ;
}
int main() {
	cout << minTime();
	return 0;
}