//https://practice.geeksforgeeks.org/problems/sum-of-lengths-of-non-overlapping-subarrays/0
#include <iostream>
using namespace std;

// int arr[] ={2,1,4,9,2,3,8,3,4};
// int n = 9, k = 4;

// int arr[] ={1,2,3,2,3,4,1};
// int n = 7, k = 4;

int arr[] ={4,5,7,1,2,9,8,4,3,1};
int n = 10, k = 4;

//O(n)
void maxSumLength() {
	int sum = 0, max = 0, start = 0, i;
	for(i = 0 ; i < n ; i++) {
		if(arr[i] > max && arr[i] <= k) {
			max = arr[i];
		}else if(arr[i] > k){
			if(max == k) {
				sum = sum + i-start;
			}
			start = i+1;
			max = 0;
		}
	}
	if(i == n && max == k) {
		sum = sum + i-start;
	}
	cout << sum << endl;
}
int main() {
	maxSumLength();
	return 0;
}