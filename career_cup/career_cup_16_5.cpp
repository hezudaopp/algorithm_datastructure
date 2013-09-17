#include <iostream>

using namespace std;

bool isBigEndian() {
	int word = 0x0001;
	char *words = (char *)&word;
	return (words[0] ? false : true);
}

int main (char *argv[], int argc) {
	cout << isBigEndian() << endl;
	return 0;
}