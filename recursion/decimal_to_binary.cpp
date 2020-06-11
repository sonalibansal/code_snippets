//https://www.geeksforgeeks.org/decimal-binary-number-using-recursion/
#include <iostream>
#include <vector>
using namespace std;

int n = 10;
vector<int> output;

void decimalToBinary (int num) {

	if(num == 0) {
		for (int i = output.size()-1; i >= 0; i--) {
			cout << output[i] ;
		}
		return;
	}
	output.push_back (num %2);
	decimalToBinary(num/2);
}

int main () {
	decimalToBinary(n);
	return 0;
}