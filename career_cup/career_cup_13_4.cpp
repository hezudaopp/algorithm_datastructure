#include <iostream>
#include <cstdlib>

using namespace std;

struct test
{
	int a;
	int *ptr;
};

typedef struct test TEST;

void shadowCopy(TEST &dest, TEST &src) {
	// dest.ptr = src.ptr;
	dest = src;
}

void deepCopy(TEST &dest, TEST &src) {
	dest.ptr = (int *)malloc(sizeof(int));
	memcpy(dest.ptr, src.ptr, sizeof(int));
}

int main (char *argv, int argc) {
	TEST t1, t2;
	int a = 3;
	t1.ptr = &a;
	shadowCopy(t2, t1);
	cout << t1.ptr << " " << t2.ptr << endl;
	deepCopy(t2, t1);
	cout << t1.ptr << " " << t2.ptr << endl;
	return 0;
}