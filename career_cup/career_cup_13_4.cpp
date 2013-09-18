#include <iostream>
#include <cstdlib>

using namespace std;

struct test
{
	int a;
	char *ptr;
};

typedef struct test TEST;

void shadowCopy(TEST &dest, TEST &src) {
	// dest.ptr = src.ptr;
	dest = src;
}

void deepCopy(TEST &dest, TEST &src) {
	dest.ptr = (char *)malloc(strlen(src.ptr)+1);
	memcpy(dest.ptr, src.ptr, strlen(src.ptr)+1);
}

int main (char *argv, int argc) {
	TEST t1, t2;
	char a[] = "aaa";
	t1.ptr = a;
	shadowCopy(t2, t1);
	cout << &t1 << " " << &t2 << endl;
	cout << &(t1.ptr) << " " << &(t2.ptr) << endl;
	cout << t1.ptr << " " << t2.ptr << endl;
	deepCopy(t2, t1);
	cout << &(t1.ptr) << " " << &(t2.ptr) << endl;
	cout << t1.ptr << " " << t2.ptr << endl;
	return 0;
}