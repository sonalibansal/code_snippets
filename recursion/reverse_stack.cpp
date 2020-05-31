#include <stack>
#include <iostream>
using namespace std;

// O(n) where n is the stack size
stack<int> reverseStackAndPrint (stack<int> s, stack<int> &reverse) {

	if (s.empty ()) {
		return reverse;
	}

	reverse.push (s.top ());

	s.pop ();

	return reverseStackAndPrint (s, reverse);

}


int main () {

	stack<int> s;
	s.push (1);
	s.push (2);
	s.push (3);
	s.push (4);

	stack<int> reverse;
	stack<int> res = reverseStackAndPrint (s, reverse);

	cout << "Original stack elements" << endl;

	while (!s.empty ()) {
		cout << s.top () << " ";
		s.pop ();
	}

	cout << "Reverse stack elements" << endl;

	while (!res.empty ()) {
		cout << res.top () << " ";
		res.pop ();
	}


}