//https://www.geeksforgeeks.org/path-maximum-average-value/
#include <iostream>
#include <cstring>
using namespace std;

int n = 3, pathLength = 2*n-1;
int arr[3][3] = { {1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9}};

int dp[3][3];
double maxAverage(int i, int j) {
	if(i>=n || j>=n) {
		return 0;
	}
	
	int maxa = arr[i][j] + maxAverage(i+1,j);
	int maxb = arr[i][j] + maxAverage(i, j+1);
	cout << maxa << " " << maxb << endl;
	int maxValue = max(maxa, maxb);
	
	if(i==0 && j==0) {
		return (double)maxValue/pathLength;
	} else {
		return maxValue;
	}
}

int main() {
	memset(dp, -1, sizeof(dp));
	cout << maxAverage(0, 0) << endl;
	return 0;
}