//https://practice.geeksforgeeks.org/problems/reach-a-given-score/0
#include <iostream>
#include <cstring>
using namespace std;

int arr[] = {3,5,10}, size =3;
//int N = 13; // output = 2
//int N = 20;  // output = 4
int N = 8 ; // output = 1
int dp[3][1000];

//O(size * 1000) 
int count(int index, int sum = 0) {
	if(sum == N) {
		return 1;
	}
	if(sum > N || index >= size) {
		return 0;
	}
	if(dp[index][sum] != -1) {
		return dp[index][sum];
	}
	dp[index][sum] =  count(index, sum+arr[index]) + count(index+1, sum);
	return dp[index][sum];
}

int main() {
	memset(dp, -1, sizeof(dp));
	cout << count(0);
	return 0;
}