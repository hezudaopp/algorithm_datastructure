#include <iostream>
#include <string>

using namespace std;

int find_string (string s[], int len, string v) {
	int left = 0, right = len-1;
	while (left <= right) {
		int mid = (left+right)/2;
		while (mid <= right && s[mid].compare("")==0) mid++;
		if (v.compare(s[mid]) == 0) return mid;
		else if (v.compare(s[mid]) > 0) {
			left = mid+1;
		} else {
			mid = (left+right)/2;
			while (mid >= left && s[mid].compare("")==0) mid--;
			if (v.compare(s[mid]) == 0) return mid;
			else {
				right = mid-1;
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	string s[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
	for (int i=0; i<sizeof(s)/sizeof(string); i++) {
		cout << find_string(s, sizeof(s)/sizeof(string), s[i]) << " ";
	}
	cout << endl << find_string(s, sizeof(s)/sizeof(string), "ballcar") << endl;
	return 0;
}