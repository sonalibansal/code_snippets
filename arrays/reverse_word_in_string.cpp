//https://practice.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string/0
#include <iostream>
using namespace std;

//string str = "i.like.this.program.very.much";
string str = "pqr.mno";

void reverseUtil(int start, int end) {
	char temp;
	while(start < end) {
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		
		start ++;
		end --;
	}
}

void reverse() {
	int start = 0, i;
	for(i = 0 ; i < str.length() ; i++) {
		if(str[i] == '.') {
			reverseUtil(start, i-1);
			start = i+1;
		}
	}
	if(i == str.length()) {
		reverseUtil(start, i-1);
	}
}
int main() {
	reverse();
	cout << str << endl;
	return 0;
}