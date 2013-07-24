#include <string>
#include <iostream>

using namespace std;

void rmDup(string &s) {
	int len = s.length();
	if (len == 0) return;
	for (int i=0; i<len; i++) {
		char c = s[i];
		for (int j=i+1; j<len; j++) {
			if (c == s[j]) {
				len--;
				s.erase(j, 1);
				j--;
			}
		}
	}
	return;
}

int main (int argc, char *argv[]) {
	string s("aaaaaaaaaaaaa");
	rmDup(s);
	cout << s << endl;
	return 0;
}