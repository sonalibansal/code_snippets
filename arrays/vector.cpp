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
	int i;

	a.push_back(Student (24,"Sonali")); // O(1)
	a.push_back(Student (25, "Mitanshi"));
	a.push_back(Student (25, "Ria"));
	a.push_back(Student (24, "Shubhi"));

	sort (a.begin(),a.end(), compareAge); // O(nlogn) worst case and average case , Best case : O(n)

	for (i = 0 ; i != a.size() ; i++) {
		cout << a[i].name << " " << a[i].age << endl; // 
	 }

	// Output : 
	// Ria 25
	// Mitanshi 25
	// Sonali 24
	// Shubhi 24

	return 0;

}