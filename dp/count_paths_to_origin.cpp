//https://www.geeksforgeeks.org/counts-paths-point-reach-origin/
#include <iostream>
#include <cstring>
using namespace std;
int n = 3, m = 6;
int dp[4][7];
int countPaths(int i, int j) {
	if(i==0 && j==0) {
		return 0;
	}
	if(i==0 || j==0) {
		return 1;
	}
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	dp[i][j] =  countPaths(i-1,j) + countPaths(i, j-1);
	return dp[i][j];
}

int main() {
	memset(dp, -1, sizeof(dp));
	cout << countPaths(n, m) << endl;
	return 0;
}