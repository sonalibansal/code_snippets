//https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
#include <iostream>
using namespace std;
int arr[] = {-2,-3,4,-1,-2,1,5,-3};
int n = 8;

//O(n)
void laregstSum() {
	int curr = 0, ans = -1000;
	for(int i = 0; i< n ;i++) {
		curr = max(curr + arr[i], arr[i]);
		ans =  max(ans, curr);
	}
	cout << "max sum =" << ans << endl;
}
int main() {
	laregstSum();
	return 0;
}