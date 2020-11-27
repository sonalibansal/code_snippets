//https://www.geeksforgeeks.org/number-of-pairs-in-an-array-with-the-sum-greater-than-0/?ref=leftbar-rightbar
#include <iostream>
#include <algorithm>
using namespace std;

//int arr[] = { 3, -2, 1 }, n = 3;
//int arr[] = { -1, -3, -1, 0, 2, 3, 4, 5 }, n = 8;
int arr[] = { -1, -1, -1, 0 }, n = 4;

int binarySearch(int low, int high, int x) {
	
	if(low > high) {
		return -1;
	}
	if(arr[low] + x > 0) {
		return low;
	}
	int mid = (low+high)/2;
	if(x + arr[mid] > 0) {
		return binarySearch(low,mid-1,x);
	}else {
		return binarySearch(mid+1, high, x);
	}
}


// O(n log(n)
void numberOfPairs() {
	int ans = 0, j;
	for(int i = 0; i < n ; i++) {
		j = binarySearch(i+1, n-1, arr[i]);
		if(j != -1) {
			ans = ans + n-j;
		}
	}
	cout << ans << endl;
}

int main() {
	sort(arr, arr+n);
	numberOfPairs();
	return 0;
}