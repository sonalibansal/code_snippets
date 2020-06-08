//https://www.geeksforgeeks.org/maximum-sum-of-elements-divisible-by-k-from-the-given-array/
#include <iostream>
#include <vector>
using namespace std;

int k = 3;
int arr[] = {3,6,5,1,8};
int n = 5;

void printMaxSum (int index, int sum, int &maxsum){
	if(index == n) {
		if(sum%k ==0 && sum > maxsum) {
			maxsum = sum;
		}
		return;
	}
	printMaxSum(index + 1, sum + arr[index], maxsum);
	printMaxSum(index + 1, sum, maxsum);
}

int main () {
	int maxsum = 0;
	printMaxSum(0, 0, maxsum);
	cout << maxsum << endl;
	return 0;
}