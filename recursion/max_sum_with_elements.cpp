#include <iostream>
#include <vector>
using namespace std;
int arr[] = {1,5,3,4,5};
int n = 5;
vector<int> output;
vector<int> curr;
int maxSum =0 ;

void maxSumElements(int index, int sum =0) {
	if(index >= n) {
		if(maxSum < sum) {
			maxSum = sum;
			output.clear();
			for(int i = 0 ; i < curr.size() ;i++) {
				output.push_back(curr[i]);
			}
		}
		return;
	}
	curr.push_back(arr[index]);
	maxSumElements(index+2, sum + arr[index]);
	curr.pop_back();
	maxSumElements(index+1, sum);
}

int main() {
	maxSumElements(0);
	
	for(int i = 0 ;i < output.size(); i++) {
		cout << output[i] << " ";
	}
	return 0;
}