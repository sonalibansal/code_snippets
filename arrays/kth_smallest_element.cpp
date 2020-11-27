//https://practice.geeksforgeeks.org/problems/kth-smallest-element/0
#include <iostream>
using namespace std;
int arr[] = {7 ,10, 4, 3, 20, 15}, n = 6, k = 6, count[100001];

void kthSmallest() {
	if(k > n) {
		cout << "Value of k cannot be larger than n" << endl;
	}
	for(int i = 0; i < 100000; i++) {
		count[i] = 0;
	}
	for (int i = 0 ; i < n ;i++) {
		count[arr[i]] ++;
	}
	int smallestCount = 0;
	for(int i = 0; i < 100000; i++) {
		if(count[i] > 0) {
			smallestCount++;
			if(k == smallestCount) {
				cout << i << endl;
				break;
			} 
		}
	}
}
int main() {
	kthSmallest();
	return 0;
}