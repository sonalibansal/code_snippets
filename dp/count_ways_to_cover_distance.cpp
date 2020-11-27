//https://www.geeksforgeeks.org/count-number-of-ways-to-cover-a-distance/
#include <iostream>
#include <cstring>
using namespace std;

int arr[] = {1,2,3};
int size = 3, n = 4;
int dp[40];

int countWays(int sum) {
	if(sum == n) {
		return 1;
	}
	if(sum > n) {
		return 0;
	}
	if(dp[sum] != -1) {
		return dp[sum];
	}
	int count = 0;
	for(int i = 0; i < size ; i++) {
		count = count + countWays(sum +arr[i]);
	}
	dp[sum] = count;
	return count;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cout << countWays(0) << endl;
	return 0;
}