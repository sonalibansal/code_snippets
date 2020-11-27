//https://practice.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins/0
#include <iostream>
#include <cstring>
using namespace std;
#define n 3
int arr[n][n] = {1, 2, 3, 4, 6, 5, 9, 8, 7};
//int arr[n][n] = {1, 2, 3, 4, 6, 5, 3, 2, 1};
int k = 16;
int dp[n][n][1000];
int countPaths(int row, int col, int coinsSum) {
	if(coinsSum > k || row >= n || col >= n) {
		return 0;
	}
	if(row == n-1 && col == n-1 && coinsSum == k) {
		return (coinsSum == k);
	}
	if(dp[row][col][coinsSum] != -1) {
		return dp[row][col][coinsSum];
	}
	int a = 0, b = 0;
	if(row+1 < n) {
		a = countPaths(row+1, col, coinsSum + arr[row+1][col]);
	}
	if(col+1 < n) {
		b = countPaths(row, col+1, coinsSum + arr[row][col+1]);
	}
	dp[row][col][coinsSum] = a + b;
	return dp[row][col][coinsSum];
}

int main() {
	memset(dp, -1, sizeof(dp));
	cout << countPaths(0,0,arr[0][0]);
	return 0;
}