#include <iostream>
#include <queue> 
using namespace std;

int main () {

	priority_queue <int> pr_queue ;

	pr_queue.push (-10);
	pr_queue.push (-20);
	pr_queue.push (-5);
	pr_queue.push (-30);

	while (!pr_queue.empty()) {
		cout << -(pr_queue.top ()) << " ";

		pr_queue.pop ();
	 }


}

