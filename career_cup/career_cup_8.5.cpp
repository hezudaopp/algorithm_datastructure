#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> getParentheses(int n) {
	std::set<string> result;
	if (n<=0) {
		return result;
	} else if (n==1) {
		result.insert("()");
		return result;
	} else {
		set<string> pre_result = getParentheses(n-1);
		for (set<string>::iterator it = pre_result.begin(); it!=pre_result.end(); it++) {
			result.insert("("+*it+")");
			result.insert("()"+*it);
			result.insert(*it + "()");
		}
		return result;
	}
}

int main (int argc, char *argv[]) {
	set<string> s = getParentheses(3);
	for (set<string>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}
}