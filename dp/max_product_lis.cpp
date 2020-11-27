//https://www.geeksforgeeks.org/maximum-product-increasing-subsequence/
#include <iostream>
#include <cstring>
using namespace std;
//int arr[] = { 3, 100, 4, 5, 150, 6 };
int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
int n = 8;
int dp[8][8];

int maxProduct(int index, int last) {
	if(index >= n) {
		return 1;
	}
	if(dp[index][last] != -1) {
		return dp[index][last];
	}
	if(arr[index] > arr[last] || index == last) {
		dp[index][last] =  max(arr[index]* maxProduct(index+1, index), maxProduct(index+1, last));
		return dp[index][last];
	}
	dp[index][last] =  maxProduct(index+1, last);
	return dp[index][last];
}

int main() {
	// your code goes here
	int curr = 0, max = 0;
	memset(dp, -1, sizeof(dp));
	for(int i = 0 ; i < n ; i++) {
		curr = maxProduct(i, i);
		if(max < curr) {
			max = curr;
		}
	}
	cout << "Max product = " << max << endl;
	return 0;
}