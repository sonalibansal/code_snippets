//https://www.geeksforgeeks.org/minimum-operations-to-make-sum-of-neighbouring-elements/
#include <iostream>
#include <vector>
using namespace std;

int x = 1;
int arr[] = {1, 6, 1, 2, 0, 4};
int n = 6;

void minOperations(){
	int count = 0, temp, diff;
	for (int i = 0 ; i < n-1 ;i++) {
		temp = arr[i+1] + arr[i];
		if(temp > x) {
			diff = temp-x;
			count = count+diff;
			if(arr[i+1] >= arr[i]) {
				arr[i+1] = arr[i+1]-diff;
			}else {
				arr[i] = arr[i]-diff;
			}	
		}
		
	}
	cout << count << endl;
}

int main () {
	minOperations();
	return 0;
}