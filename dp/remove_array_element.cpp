//https://www.geeksforgeeks.org/remove-array-end-element-maximize-sum-product/
#include <iostream>
#include <cstring>
using namespace std;
int arr[] = { 1, 3, 1, 5, 2 };
//int arr[] = { 1, 2 };
int n = 5;
int dp[5][5];

int maxSum(int left, int right) {
	int removedElements = n - (right-left+1);
	if(left == right) {
		return arr[left] * (removedElements+1);
	}
	if(left>= n || right < 0) {
		return 0;
	}
	if(dp[left][right] != -1) {
		return dp[left][right];
	}
	int maxa = arr[left]*(removedElements+1) + maxSum(left+1, right);
	int maxb = arr[right]*(removedElements+1) + maxSum(left, right-1);
	dp[left][right] =  max(maxa, maxb);
	return dp[left][right];
}
int main() {
	memset(dp, -1, sizeof(dp));
	cout << maxSum(0, n-1);
	return 0;
}