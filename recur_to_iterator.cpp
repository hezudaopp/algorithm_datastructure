#include <iostream>
#include <stack>

using namespace std;

void recur(int &s) {
	int x;
	cin >> x;
	if (x==0)
		s=0;
	else {
		recur(s);
		s+=x;
	}
	cout << s;
}

void iterate(int &s) {
	int x;
	cin >> x;
	stack<int> st;
	while (x!=0) {
		st.push(x);
		cin >> x;
	}
	s = 0;
	st.push(0);
	while (!st.empty()) {
		s += st.top();
		cout << s;
		st.pop();
	}
}

int main (char *argv[], int argc) {
	int s=3;
	iterate(s);
	return 0;
}