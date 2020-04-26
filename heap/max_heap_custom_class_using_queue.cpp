#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Student
{
  public:
	string name;
	int totalMarks;
	
	Student (string name, int totalMarks) {
		this -> name = name;
		this -> totalMarks = totalMarks;
	}
};

// time complexity : O(1)
bool operator< (Student A, Student B) {
	if (A.totalMarks != B.totalMarks) {
		return A.totalMarks < B.totalMarks;
	}
	return A.name > B.name;
}

int main() {

	priority_queue<Student> q;
	q.push (Student ("Sonali", 85)); // O(logn)
	q.push (Student ("Abhishek", 95));
	q.push (Student ("Ria", 60));
	q.push (Student ("Mitanshi", 85));

	while (!q.empty ()) {
		Student s = q.top (); // O(1)
		q.pop (); // O(logn)
		cout << s.name << " " << s.totalMarks << " ";
		cout << "\n";
	}

	return 0;
}
