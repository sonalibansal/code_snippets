//https://www.geeksforgeeks.org/longest-subsequence-such-that-difference-between-adjacents-is-one/
#include <iostream>
#include <cstring>
using namespace std;
//int arr[] = {10, 9, 4, 5, 4, 8, 6};
int arr[] = {1, 2, 3, 2, 3, 7, 2, 1};
int n = 8, dp[8][100];
int lis(int index, int last) {
	if(index >= n) {
		return 0;
	}
	if(dp[index][last] != -1) {
		return dp[index][last];
	}
	if(abs(arr[index]-arr[last]) ==1 || last == index) {
		dp[index][last] =  max(lis(index+1, last), 1+ lis(index+1, index));
		return dp[index][last];
	}
	dp[index][last] = lis(index+1, last);
	return dp[index][last];
}

int main() {
	// your code goes here
	int curr =0, ans  =0 ;
	memset(dp, -1, sizeof(dp));
	for(int i = 0 ; i < n ;i++) {
		curr = lis(i,i);
		if(ans < curr) {
			ans = curr;
		}
	}
	cout << ans << endl;
	return 0;
}