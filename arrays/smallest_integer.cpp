//https://www.geeksforgeeks.org/smallest-integer-to-be-inserted-to-have-equal-sums/
#include <iostream>
#include <climits>
using namespace std;

int arr[] = {3,2,1,5,7,8};
int n = 6;

void smallestInteger(){
	int min = INT_MAX, i, j, leftSum =0, totalSum =0, rightSum = 0;
	for (i= 0 ; i < n ;i++) {
		totalSum = totalSum + arr[i];
	}
	for (i = 0 ; i < n-1 ;i++) {
		leftSum = leftSum + arr[i];
		rightSum = totalSum -leftSum;

		if(abs(rightSum -leftSum)< min) {
			min = rightSum-leftSum;
		}
		if(min == 0) {
			break;
		}
	}
	
	cout << min << endl;
}

int main () {
	smallestInteger();
	return 0;
}