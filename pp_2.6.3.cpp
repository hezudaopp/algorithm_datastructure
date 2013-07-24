#include <iostream>

using namespace std;

void rotate_string(string &s, int k) {
	int len = s.length();
	k %= len;
	int count = 0;
	for (int i=0; i<k; i++) {
		char tmp = s[i];
		int cur = i, next = (cur+k)%len;
		do {
			s.replace(cur, 1, 1, s[next]);
			count ++;
			cur = next;
			next = (next+k) % len;
		} while (next != i);
		s.replace(cur, 1, 1, tmp);
		count ++;
		if (count >= len) break;
	}
}

void reverse_string(string &s, int start, int end) {
	while (start < end) {
		char c = s[start];
		s.replace(start, 1, 1, s[end]);
		s.replace(end, 1, 1, c);
		start++;
		end--;
	}
}

void rotate_string1(string &s, int k) {
	int len = s.length();
	k %= len;
	reverse_string(s, 0, k-1);
	reverse_string(s, k, len-1);
	reverse_string(s, 0, len-1);
}

void rotate_sub_string(string &s, int start, int mid, int end) {
	if (end - start <= 1) return;
	int left = mid - start + 1, right = end - mid;
	if (left <= right) {
		for (int i=start; i<start+left; i++) {
			char c = s[i];
			s.replace(i, 1, 1, s[end-left+1+(i-start)]);
			s.replace(end-left+1+(i-start), 1, 1, c);
		}
		rotate_sub_string(s, start, start+right, end-left);
	} else if (left > right) {
		for (int i=mid; i < mid+right; i++) {
			char c = s[i];
			s.replace(i, 1, 1, s[start+(i-mid)]);
			s.replace(start+(i-mid), 1, 1, c);	
		}
		rotate_sub_string(s, mid, mid+right, end);
	}
}

void rotate_string2(string &s, int k) {
	int len = s.length();
	k %= len;
	rotate_sub_string(s, 0, k, len-1);
}

int main (int argc, char *argv[]) {
	string s("0123456789");
	rotate_string2(s, 4);
	cout << s;
}