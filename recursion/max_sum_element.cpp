#include <iostream>
#include <vector>
using namespace std;
int arr[] = {1,5,3,4,5};
int n = 5;
int maxSum =0 ;

void maxSumElements(int index, int sum = 0) {
	if(index >= n) {
		if(maxSum < sum) {
			maxSum = sum;
		}
		return;
	}
	maxSumElements(index+2, sum + arr[index]);
	maxSumElements(index+1, sum);
}

int main() {
	maxSumElements(0);
	cout << maxSum << endl;
	return 0;
}