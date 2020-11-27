//https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
#include <iostream>
using namespace std;
int val[] {60,100,120};
int wt[] = {10,20,30};
int n = 3, W = 50, maxSum =0;

int maxSubset(int index, int weight=0) {
	if(weight > W) {
		return -1000;
	}
	
	if(index>=n) {
		return 0;
	}
	int maxa = val[index] + maxSubset(index+1, weight+wt[index]);
	int maxb = maxSubset(index+1, weight);
	return max(maxa, maxb);
}

int main() {
	// your code goes here
	cout << maxSubset(0);
	//cout << maxSum << endl;
	return 0;
}