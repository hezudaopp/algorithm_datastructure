#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> permutation(string str) {
	set<string> s;
	if (str.length() == 0) return s;
	if (str.length() == 1) {
		s.insert(str);
	} else {
		unsigned int len = str.length();
		set<string> words = permutation(str.substr(0, len-1));
		string last_str = str.substr(len-1, 1);
		for (set<string>::iterator it=words.begin(); it!=words.end(); it++) {
			unsigned int l = (*it).length();
			for (int i=0; i<=l; i++) {
				string tmp = (*it).substr(0, i) + last_str + (*it).substr(i);
				// cout << tmp << endl;
				s.insert(tmp);
			}
		}
	}
	return s;
}

int main (int argc, char *argv[]) {
	string str("peer");
	set<string> s =	permutation(str);
	for (set<string>::iterator it=s.begin(); it!=s.end(); it++) {
		cout << *it << endl;
	}
}