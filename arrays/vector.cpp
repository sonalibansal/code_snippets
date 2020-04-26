#include <iostream> 
#include <vector>

using namespace std;


class  Student
{
public:
	int age;
	string name;

	Student (int age, string name) {
		this->age = age;
		this->name = name;
	}
	
};

// time complexity : O(1)
bool compareAge (Student A, Student B) {
	if (A.age != B.age) {
		return A.age > B.age;
	}
	return A.name > B.name;
}

int main () {
	
	vector<Student> a;

	a.push_back(Student (24,"Sonali")); // O(1)
	a.push_back(Student (25, "Mitanshi"));
	a.push_back(Student (25, "Ria"));
	a.push_back(Student (24, "Shubhi"));

	sort (a.begin(),a.end(), compareAge); // O(nlogn) worst case and average case , Best case : O(n)

	vector<Student> :: iterator i;

	for (i = a.begin(); i != a.end(); i++) 
	{
		Student object = *i;
		cout << object.name << " " << object.age;
	}

	return 0;

}