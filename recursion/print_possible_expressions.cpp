//https://www.geeksforgeeks.org/print-all-possible-expressions-that-evaluate-to-a-target/
#include <iostream>
#include <vector>
using namespace std;


void getPossibleExpressionsUtil (vector<string> &res, string input, int target,
								 string currExpr, int pos, int currValue, int last) {

	if (pos == input.length ()) {
		if (currValue == target) {
			res.push_back (currExpr);
			return;
		}
	}

	for (int i = pos ; i < input.length() ; i++) {

		if (i != pos && input[pos] == '0') 
            break; 

		string part = input.substr(pos, i + 1 - pos); 
		int curr = atoi (part.c_str());
		if (pos == 0) {
			getPossibleExpressionsUtil (res, input, target, currExpr + part, i+1,
									    curr, curr);
		} else {

			getPossibleExpressionsUtil (res, input, target, currExpr + "+" + part, i+1,
									    currValue + curr, curr);
			getPossibleExpressionsUtil (res, input, target, currExpr + "-" + part, i+1,
									    currValue - curr, -curr);
			getPossibleExpressionsUtil (res, input, target, currExpr + "*" + part, i+1,
									    currValue - last + last * curr, last * curr);

		}
	}

}

vector<string> getPossibleExpressions (string input, int target) {
	vector<string> res;
	getPossibleExpressionsUtil (res, input, target, "", 0, 0, 0);
	return res;
}

void printResult (vector<string> res) {
	for (int i = 0; i < res.size(); i++) 
        cout << res[i] << endl; 
}


int main () {

	string input = "123";
	int target = 6;
	vector<string> res = getPossibleExpressions (input, target);

	printResult (res);

}