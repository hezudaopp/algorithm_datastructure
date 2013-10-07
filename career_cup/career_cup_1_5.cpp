#include <iostream>

using namespace std;

void replaceStringSpace (char str[], int len) {
	int spaceCount = 0;
	for (int i=0; i<len; i++) {
		if (str[i] == ' ') {
			spaceCount++;
		}
	}
	int newLen = len + (spaceCount<<1);
	str[newLen] = '\0';
	for (int i = len-1, j=newLen-1; i>=0; i--) {
		if (str[i] == ' ') {
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		} else {
			str[j--] = str[i];
		}
	}
}

int main (char *argv[], int argc) {
	char str[] = " we are happy! ";
	replaceStringSpace(str, strlen(str));
	cout << str << endl;
	return 0;
}