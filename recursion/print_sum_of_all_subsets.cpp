//https://www.geeksforgeeks.org/print-sums-subsets-given-set/
#include <iostream>
#include <vector> 
using namespace std;

int arr[ ] = {2, 3};
vector<int> output;
int n = 2;

void printSum (int index) {
	int sum = 0;
	if (output.size() == 0) {
		cout << sum << " ";
	} else {
			for (int i = 0; i < output.size(); i++) {
				sum = sum + output[i];
			}
			cout << sum << " ";
	}
	
	if (index == n) {
		return;
	}

	for (int i = index ; i < n ;i++) {
		output.push_back(arr[i]);
		printSum(i+1);
		output.pop_back();
	}


}

void printSumOptimised (int index, int sum) {
	if (index == n) {
		cout << sum << " ";
		return;
	}
	
	printSumOptimised(index+1, sum + arr[index]);
	printSumOptimised(index+1, sum);
}

int main() {

	printSum(0);
	cout << endl;

	printSumOptimised(0, 0);
}