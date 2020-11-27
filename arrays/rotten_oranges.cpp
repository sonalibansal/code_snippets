//https://practice.geeksforgeeks.org/problems/rotten-oranges/0
#include <iostream>
using namespace std;

int arr[3][5] = {{2,1,0,2,1},
				 {0,0,1,2,1},
				 {1,0,0,2,1}};
int R = 3, C = 5;

bool isFresh(int i, int j) {
	return (i >= 0 && i < R && j>=0 && j < C && arr[i][j] == 1);
}

//O(n^2)
int minTime() {
	int row[] = {-1,1,0,0};
	int col[] = {0,0,-1,1};
	bool flag = false;
	int rottenOrangeNumber = 2;
	while(true) {
		for(int i = 0 ; i < R; i++) {
			for(int j = 0 ; j < C ; j++) {
				if(arr[i][j] == rottenOrangeNumber) {
					for(int k = 0; k < 4; k++) {
						if(isFresh(row[k]+i, col[k]+j)) {
							arr[row[k]+i][col[k]+j] = rottenOrangeNumber+1;
							flag = true;
						}
					}
				}
			}
		}
		if(!flag) {
			break;
		}
		flag = false;
		rottenOrangeNumber ++;
	}
	for(int i = 0 ; i < R; i++) {
		for(int j = 0 ; j < C ; j++) {
			if(arr[i][j] == 1) {
					return -1;
			}
		}
	}
	return rottenOrangeNumber -2 ;
}
int main() {
	cout << minTime();
	return 0;
}