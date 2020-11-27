//https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
#include <iostream>
#include <cstring>
using namespace std;
//int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
int arr[] = {100, 10, 22, 9, 33, 21, 50, 41, 60, 80};
//int arr[] = {3,1,2,1,4,5};
//int arr[] = {1,5,2,3,4};
//int arr[] = {3, 10, 2, 1, 20};
//int arr[] = {50, 3, 10, 7, 40, 80};
//int arr[] = {3, 2};
int n = 10;
int dp[10][100];

// O(n)
int lis(int index, int last) {
	if (index >=n) {
		return 0;
	}
	if(dp[index][last] != -1) {
		return dp[index][last];
	}
	if(arr[index] > arr[last] || index == last) {
		dp[index][last] = max(lis(index+1, last), 1+lis(index+1, index));
		return dp[index][last];
	}
	dp[index][last] = lis(index+1, last);
	return dp[index][last];
}

int main() {
	int curr = 0, max =0;
	memset(dp, -1, sizeof(dp));
	for(int i = 0 ; i < n ; i++) {
		curr = lis(i,i);
		if(max < curr) {
			max = curr;
		}
	}
	cout << max << endl;
	return 0;
}