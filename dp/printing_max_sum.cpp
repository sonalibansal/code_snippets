//https://www.geeksforgeeks.org/printing-maximum-sum-increasing-subsequence/

#include <iostream>
#include <cstring>
using namespace std;
//int arr[] = {1, 101, 2, 3, 100, 4, 5};
//int arr[] = {3, 4, 5, 10};
//int arr[] = {10, 5, 4, 3};
int arr[] = {3, 2, 6, 4, 5, 1};
int n = 6;
int dp[6][6];

// O(n^2)
int lis(int index, int last) {
	if(index >= n) {
		return 0;
	}
	if(dp[index][last] != -1) {
		return dp[index][last];
	}
	if(arr[index]>arr[last] || last == index) {
		dp[index][last] =  max(arr[index]+ lis(index+1, index), lis(index+1, last));
		return dp[index][last];
	}
	dp[index][last] = lis(index+1, last);
	return dp[index][last];
}
 
int main() {
	int curr = 0, ans  = 0 ;
	memset(dp, -1, sizeof(dp));
	//O(n^2 + n) = O(n^2)
	for(int i = 0 ; i < n ;i++) {
		curr = lis(i,i);
		if(ans < curr) {
			ans = curr;
		}
	}
	cout << ans << endl;
	return 0;
}