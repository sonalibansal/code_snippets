//https://www.geeksforgeeks.org/ways-to-write-n-as-sum-of-two-or-more-positive-integers/
#include <iostream>
#include <cstring>
using namespace std;
int n = 5, dp[5][1000]; 

//O(n^2)
int countWays(int index, int sum) {
	if(sum == n) {
		return 1;
	}
	if(sum > n || index>=n) {
		return 0;
	}
	if(dp[index][sum] != -1) {
		return dp[index][sum];
	}
	dp[index][sum] = countWays(index, sum+index) + countWays(index+1, sum);
	return dp[index][sum];
}

int main() {
	memset(dp, -1, sizeof(dp));
	cout << countWays(1, 0);
	return 0;
}