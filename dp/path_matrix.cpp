//https://practice.geeksforgeeks.org/problems/path-in-matrix/0
#include <iostream>
#include <cstring>
using namespace std;

#define n 2
int arr[n][n] = {348, 391, 618, 193};
//int arr[n][n] = {1,2,3,4,5,6,7,8,9};
//int arr[n][n] = {0,1,2,3};

int dp[n][n];
int maxSum(int row, int col) {
	if(row == n-1 && col >=0 && col < n) {
		return arr[row][col];
	}
	if(row >= n || row < 0 || col >= n || col < 0) {
		return -1000;
	}
	if(dp[row][col] != -1) {
		return dp[row][col];
	}
	
	int maxa = maxSum(row+1, col);
	int maxb = maxSum(row+1, col-1);
	int maxc = maxSum(row+1, col+1);
	dp[row][col] = arr[row][col] + max(max(maxa, maxb), maxc);
	return dp[row][col];
}
int main() {
	memset(dp, -1, sizeof(dp));
	int max = 0, curr = 0;
	for(int i = 0 ; i < n ;i++) {
		curr = maxSum(0, i);
		if(curr > max) {
			max = curr;
		}
	}
	
	cout << max << endl;
	return 0;
}