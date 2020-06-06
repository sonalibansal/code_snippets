//https://www.geeksforgeeks.org/powet-set-lexicographic-order/
#include <iostream>
#include <algorithm> 
#include <set>
using namespace std;

string input = "abc";
set<string> res;
string output = "";

void printLexographicOrder (int index, int length) {

	if (length != 0 ) {
		cout << output << endl;
		res.insert(output);
	}
	if (index == input.length()) {
		return;
	}
	output = output+ input[index];
	printLexographicOrder (index+1,length+1);
	output.erase(output.size()-1);
	printLexographicOrder (index+1,length);
}

void printLexographicOrder (int index) {
	cout << output << endl;
	if (index == input.length()) {
		return;
	}
	for (int i = index; i < input.length() ; i++) {
		output = output + input[i];
		printLexographicOrder (i+1);
		output.erase(output.length()-1);
	}
	return;
}

int main () {
	sort(input.begin(), input.end()); 
	printLexographicOrder (0,0);
	set<string> :: iterator it;
	cout << "output set = " << endl;
	for (it = res.begin() ; it != res.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}