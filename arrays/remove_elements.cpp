#include <iostream>
using namespace std;
string str = "acbac";
//string str = "aababc";
void removeFromString() {
	int i = 0, j, k;
	while(i < str.length()) {
		if(str[i] == 'a') {
			if(i+1 < str.length () && str[i+1] == 'c') {
				k = i;
				for(j = i+2; j < str.length () ;j++) {
					str[k++] = str[j];
				}
				str.resize(str.length () -2);
				continue;
			}
		}
		if(str[i] == 'b') {
			k = i;
			for(j = i+1; j < str.length () ;j++) {
				str[k++] = str[j];
			}
			str.resize(str.length()-1);
			continue;
		}
		i++;
	}
	cout << str << endl;
}
int main() {
	removeFromString();
	return 0;
}