#include <iostream>
#include <string>

using namespace std;

bool isRotation(string s1, string s2) {
	int len = s1.length();
	if (len != s2.length()) return false;
	for (int r=0; r<len; r++) {
		string tmp=s1;
		for (int i=0; i<len; i++) {
			tmp[i] = s1[(i+r)%len];
		}
		if (tmp.compare(s2) == 0) return true;
	}
	return false;
}

int main (int argc, char *argv[]) {
	string s1("erbottlewat1"), s2("waterbottle1");
	cout << isRotation(s1, s2) << endl;
}