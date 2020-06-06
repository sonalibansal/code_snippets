//https://www.geeksforgeeks.org/all-possible-binary-numbers-of-length-n-with-equal-sum-in-both-halves/
#include <iostream>
#include <vector>
using namespace std;

#define n 4
int res[n];

void calculatesum(int index, int &leftsum, int &rightsum) {
	if (n%2 != 0) {
		if (index < n/2) {
			leftsum++;
			return;
		}
		if (index > n/2) {
			rightsum++;
			return;
		}
		return;
	}
	if (index < n/2) {
		leftsum++;
		return;
	}
	rightsum++;
 
}

void printCombinations (int start, int leftSum , int rightSum) {

	if(start == n) {
		
		if (leftSum == rightSum) {
			for (int i = 0 ; i < start ; i++) {
				cout << res[i] ;
			}
			cout << endl;	
		}
				
		return;
	}
	
	if (rightSum > leftSum || (rightSum + n - start < leftSum)) {
		return;
	}

	res[start] = 0;
	printCombinations (start+1, leftSum, rightSum);
	res[start] = 1;
	calculatesum(start, leftSum, rightSum);
	printCombinations (start+1, leftSum, rightSum);
}

int main () {

	printCombinations (0, 0, 0);
	return 0;
}