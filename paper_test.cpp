#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

// int i=1;

// #define DOUBLE(x) x+x
// int i=5*DOUBLE(5);	//30

// struct student
// {
// 	/* data */
// 	int a;
// 	char b[20];
// 	double c;
// } stu;
// #define FIND(struc, e) (size_t)&(((struc *)4)->e);

// #define MIN(a,b) (((a+b)-abs(a-b))/2)

struct {
	double b;
	short a2;
}B;

int main(int argc, char *argv[]) {
	// cout << i << endl;	//1
	// int i=i;
	// cout << i << endl;	//undefined

	// int a, x;
	// for (a=0, x=0; a<=1 && !x++; ) {
	// 	a++;
	// }
	// cout << a << x << endl;	//12

	// int arr[]={6,7,8,9};
	// int *ptr = arr;
	// *(ptr++) += 123;
	// cout << *ptr << endl;
	// cout << *ptr << *(++ptr) << endl;
	// cout << *ptr << *ptr++ << endl;
	// int i=1;
	// cout << i << (i++) << endl;
	// printf("%d %d", i, i++);
	// cout << i << endl;

	// float a=1.0f;
	// cout << (int)a << endl;
	// cout << &a << endl;
	// cout << (int&)a << endl;	//0 01111111 00000000000000000000000
	// float b = 0.0f;
	// cout << (int&)b << endl;	// 0 00000000 00000000000000000000000

	// int a=0xfffffff7;
	// unsigned char b = (char)a;
	// char *c = (char *)&a;
	// printf("%x, %x, %d, %d\n",b,*(c-1), c, c+1);

	// char a=0xa5;
	// char b = ~a>>4+1;
	// printf("%d", b);

	// int a=5, b=4;
	// a=a^b;
	// b=a^b;
	// a=a^b;
	// cout << a << b << endl;

	// unsigned int offset = FIND(student, b);
	// cout << offset << &stu << endl;

	// int a=4, b=3;
	// cout << MIN(a, b) << endl;
	cout << sizeof(B) << endl;
}