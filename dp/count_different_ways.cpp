//https://www.geeksforgeeks.org/count-ofdifferent-ways-express-n-sum-1-3-4/
#include <iostream>
#include <cstring>
using namespace std;
int arr[] = {1,3,4};
int n = 3, requiredSum = 10, count = 0;
int dp[1000];
int countDiffWays (int sum = 0) {
	if(sum == requiredSum) {
		return 1;
	}
	if(sum > requiredSum) {
		return 0;
	}
	if(dp[sum] != -1) {
		return dp[sum];
	}
	int count = 0;
	for(int i = 0 ; i< n ;i++) {
		count =  count +  countDiffWays(sum+arr[i]);
	}
	dp[sum] = count;
	return count;
}
int main() {
	memset(dp, -1, sizeof(dp));
	cout << countDiffWays() << endl;
	return 0;
}