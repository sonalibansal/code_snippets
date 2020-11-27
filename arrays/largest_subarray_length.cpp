//https://www.geeksforgeeks.org/size-subarray-maximum-sum/
#include <iostream>
using namespace std;

//int arr[] = {1, -2, 1, 1, -2, 1};
int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
int n = 8;

void largest() {
	int curr = 0, ans = -1000, start = 0, end = 0, s = 0;
	for(int i = 0 ; i < n ; i++) {
		curr = curr + arr[i];
		if(curr < 0) {
			curr = 0;
			s = i+1;
		}
		else if(ans < curr) {
			start = s;
			end = i;
			ans = max(ans, curr);
		}
	}
	cout << (end- start)+1 << endl;
}
int main() {
	largest();
	return 0;
}