//https://www.geeksforgeeks.org/maximum-profit-sale-wines/
#include <iostream>
#include <cstring>
using namespace std;
int arr[] = {2, 4, 6, 2, 5};
int n = 5, dp[5][5];

//O(n^2)
int maxProfit(int left, int right) {
	int year = n -(right-left);
	if(left == right) {
		return arr[left]*year;
	}
	if(left >= n || right < 0) {
		return 0;
	}
	if(dp[left][right] != -1) {
		return dp[left][right];
	}
	int maxa = arr[left] * year+ maxProfit(left+1, right);
	int maxb = arr[right] *year + maxProfit(left, right-1);
	dp[left][right] = max(maxa,maxb);	
	return dp[left][right];
}

int main() {
	memset(dp, -1, sizeof(dp));
	cout << maxProfit(0, n-1);
	return 0;
}