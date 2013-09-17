#include <iostream>

using namespace std;

#define BIG 1
#define LITTLE 0

int main (int argc, char *argv[]) {
	int a = 0x0001;
	char *c = (char *)&a;
	int endian = (c[0]) ? LITTLE : BIG;
	cout << endian << endl;
	return 0;
}