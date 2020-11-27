//https://practice.geeksforgeeks.org/problems/max-possible-amount/0
#include <iostream>
#include <cstring>
using namespace std;
#define n 4
//int arr[] = {5,3,7,10};
int arr[] = {8, 15, 3, 7};
int dp[n][n][2];

int maxPossibleAmount(int left, int right, int flag) {
	if(left == right && flag ==0) {
		return arr[left];
	}
	if(left >= n || right < 0 || (left == right && flag ==1)) {
		return 0;
	}
	if(dp[left][right][flag] != -1) {
		return dp[left][right][flag];
	}
	if(flag) {
		dp[left][right][flag] = min(maxPossibleAmount(left+1, right, !flag),
			maxPossibleAmount(left,right -1, !flag));
		return dp[left][right][flag];
	}
	int maxa = arr[left] + maxPossibleAmount(left+1, right, !flag);
	int maxb = arr[right] + maxPossibleAmount(left, right-1, !flag);
	dp[left][right][flag] = max(maxa, maxb);
	return dp[left][right][flag];
}

int main() {
	memset(dp, -1, sizeof(dp));
	cout << maxPossibleAmount(0, n-1, 0);
	return 0;
}