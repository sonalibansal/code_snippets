//https://www.geeksforgeeks.org/coin-change-dp-7/

#include <iostream>
using namespace std;
int arr[] = {2, 5, 3, 6};
int n = 4;
int N = 10;
int count =0;
int dp[4];

int coinChange(int index, int sum= 0) {
	if(sum == N) {
		return 1;
	}
	if(sum > N || index >=n ){
		return 0;
	}
	return coinChange(index, sum+arr[index])+coinChange(index+1, sum);
} 

int main() {
	cout << coinChange(0);
	return 0;
}