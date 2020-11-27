//https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
#include <iostream>
using namespace std;
//int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
//int arr[] = {100, 10, 22, 9, 33, 21, 50, 41, 60, 80};
//int arr[] = {3,1,2,1,4,5};
//int arr[] = {1,5,2,3,4};
//int arr[] = {3, 10, 2, 1, 20};
//int arr[] = {50, 3, 10, 7, 40, 80};
int arr[] = {3, 2};
int n = 2;

// O(2^n)
int lis(int index, int last) {
	if (index >=n) {
		return 0;
	}
	if(arr[index] > arr[last] || index == last) {
		return max(lis(index+1, last), 1+lis(index+1, index));
	}
	return lis(index+1, last);
}
int main() {
	int curr = 0, max =0;
	
	// O(n^2 * n)
	for(int i = 0 ; i < n ; i++) {
		curr = lis(i,i);
		if(max < curr) {
			max = curr;
		}
	}
	cout << max << endl;
	return 0;
}