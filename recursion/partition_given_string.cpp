//https://www.geeksforgeeks.org/partition-given-string-manner-ith-substring-sum-1th-2th-substring/

#include <iostream>
#include <vector>
using namespace std;

#define n 4
string input = "5813";
vector<string> output(n);

bool checkForFibonacci (int index) {
	if (index > 2) {
		int num1 = atoi( output[index-1].c_str() );
		cout << "1st number = " << num1 << endl;
		int num2 = atoi(output[index-2].c_str());
		cout << "2nd number = " << num2 << endl;
		int sum = num1+ num2;
		cout << "sum = " << sum << endl;
		int number = atoi(output[index].c_str());
		cout << "number= " << number << endl;
		if (number == sum) {
			return true;
		}
		return false;
	}
	return true;
	
}

void partitionGivenString (int index, int length) {
	if(index == n) {
		cout << index << endl;
		for (int i = 0 ;i < length ; i++) {
			cout << output[i] << " ";
		}
		cout << endl;
		return;
	}
	
	if (checkForFibonacci(length)) {
		output[length] = input[index];
		partitionGivenString (index+1, length+1);
		cout << index << endl;

	} else {
		return;
	}
	
	if(length >= 1) {
		if (checkForFibonacci (length)) {
			output[length-1] = output[length-1]+ input[index];
			partitionGivenString (index+1, length);	
		} else {
			return;
		}
		
	}
}

int main () {
	
	partitionGivenString (0, 0);

	return 0;
}