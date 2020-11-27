//https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
#include <iostream>
#include <cstring>
using namespace std;

//int arr[] = {1,5,8,9,10,17,17,20};
int arr[] = {3 ,  5 ,  8 ,  9,  10,  17,  17,  20};
int rodLength[] = {1,2,3,4,5,6,7,8};
int n = 8, l = 8;
int dp[8][8];

int maxPrice(int index, int length) {
	if(length > l) {
		return -1000;
	}
	if(index >= n) {
		return 0;
	}
	if(dp[index][length] != -1) {
		return dp[index][length];
	}
	dp[index][length] = max(maxPrice(index+1, length), arr[index] + maxPrice(index,length+ rodLength[index]));
	return dp[index][length];
}

int main() {
	memset(dp, -1, sizeof(dp));
	cout << maxPrice(0, 0) << endl;
	return 0;
}