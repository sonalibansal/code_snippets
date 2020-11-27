//https://www.geeksforgeeks.org/count-of-substrings-of-length-k-with-exactly-k-distinct-characters/
#include <iostream>
#include <unordered_map>
using namespace std;

//string str= "abcc";
//string str = "aabab";
//string str = "aabcdabbcdc";
//string str = "aaabbaac";
string str = "abcd";
int k = 5;

void count() {
	
	unordered_map<char, int> map;
	int i , ans = 0;
	
	if(k > str.length()) {
		cout << ans << endl;
		return;
	}
	
	for(i = 0; i < str.length() ; i++) {
		if(i < k) {
			map[str[i]] ++;
			continue;
		} 
		if(i == k && map.size() == k) {
			ans++;
		}
		map[str[i-k]] --;
		if(map[str[i-k]] == 0) {
			map.erase(str[i-k]);
		}
		map[str[i]] ++;
		if(map.size() == k) {
			ans ++;
		}
	}
	if(str.length() == k && map.size() == k) {
		ans ++;
	}
	cout << ans << endl;
}

int main() {
    count();
	return 0;
}