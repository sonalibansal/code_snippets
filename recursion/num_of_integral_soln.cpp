//https://www.geeksforgeeks.org/number-of-non-negative-integral-solutions-of-sum-equation/
#include <iostream>
using namespace std;


int totalCount(int n, int val){
	int count = 0;
	if(n == 1  && val >=0) {
		return 1;
	}
	
	for (int i = 0 ;i <= val; i++) {
		count = count+ totalCount(n-1, val-i);
	}
	return count;
}

int main () {
	int n = 5, val = 4;
	int count = totalCount(n,val);
	cout << count << endl;
	return 0;
}