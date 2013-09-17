#include <iostream>

using namespace std;

#define max(a,b) a-(((a-b)>>31)&(0x1))*(a-b)

int main (int argc, char *argv[]) {
	cout << max(5,3) << endl;
	cout << max(3,5) << endl;
}