//https://practice.geeksforgeeks.org/problems/zero-sum-subarrays/0
#include <iostream>
using namespace std;
//int arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7};
//int arr[] = {0 ,0, 5, 5, 0, 0};
int arr[] = {1,2,3,4,5,6};
int n = 6;
 
//O(n ^ 2)
void subArraysCount() {
	int start , end, sum = 0, count = 0 ;
	for(int i = 0; i < n ; i++) {
		start = end = i;
		sum = 0;
		while(end < n) {
			sum = sum + arr[end];
			if(sum == 0) {
				cout << start << " " << end << endl;
				count ++;
				sum = 0;
			}
			end ++;
		}
	}
	cout << count << endl;
}
int main() {
	subArraysCount();
	return 0;
}