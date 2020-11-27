//https://practice.geeksforgeeks.org/problems/sum-of-numbers-in-string/0
#include <iostream>
using namespace std;
//string str = "1abc23";
//string str = "geeks4geeks";
//string str = "1abc2x30yz67";
string str = "123abc";

//O(n) where n is the string length
void sumOfNumbers() {
	int sum = 0, temp ;
	for(int i = 0 ; i< str.length() ; i++) {
		if(str[i] >= '0' && str[i] <='9') {
			temp = 0;
			while(str[i] >= '0' && str[i] <='9') {
				temp = temp*10 + str[i] -'0';
				i++;
			}
			sum = sum + temp;
		}
	}
	cout << sum << endl;
	
}
int main() {
	sumOfNumbers();
	return 0;
}