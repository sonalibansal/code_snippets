//https://www.geeksforgeeks.org/coin-change-dp-7/
#include <iostream>
#include <cstring>
using namespace std;
int arr[] = {2, 5, 3, 6};
int n = 4;
int requiredSum = 10;
int dp[4][1000];

int coinChange(int index,int sum= 0) {
	if(sum == requiredSum) {
		return 1;
	}
	if(sum > requiredSum || index >=n ){
		return 0;
	}
	if(dp[index][sum] != -1) {
		return dp[index][sum];
	}
	dp[index][sum] = coinChange(index, sum+arr[index])+coinChange(index+1, sum);
	return dp[index][sum];
} 

int main() {
	memset(dp,-1, sizeof(dp));
	cout << coinChange(0);
	return 0;
}