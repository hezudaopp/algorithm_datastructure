#include <iostream>

using namespace std;

// typedef struct  Struct1
// {
// 	char a;
// 	short b;
// } struct1;

// typedef struct Stru{
// 	char a;
// 	char d;
// 	short b;
// 	long c;
// } stru;

// template <class T>
// class A{
// public:
// 	static int count;
// 	T a;
// 	A(T t) {
// 		a = t;
// 		count++;
// 	}
// };

// template <class T>
// int A<T>::count = 0;

// class c{
// public:
// 	c(){
// 		cout << 1 << endl;
// 	}
// };

// class base {
// public:
// 	c a;
// };

// class derived : public base {
// public:
// 	derived(){
// 		cout << 2 << endl;
// 	}
// };

// class aa {
// public:
// 	int a;
// };

// class bb : aa {

// };

class A
{
public:
int a;
};

class B : public A
{
public:
int b;
};

void setA(A* array, int i)
{
array[i].a = 2;
}

int func(unsigned int i) {

	unsigned int temp = i;

	temp = (temp & 0x55555555) + ((temp & 0xaaaaaaaa)>>1);

	printf("%0x \n", temp);

	temp = (temp & 0x33333333) + ((temp & 0xcccccccc)>>2);

	printf("%0x \n", temp);

	temp = (temp & 0x0f0f0f0f) + ((temp & 0xf0f0f0f0)>>4);

	printf("%0x \n", temp);

	temp = (temp & 0xff00ff) + ((temp & 0xff00ff00)>>8);

	printf("%0x \n", temp);

	temp = (temp & 0xffff) + ((temp & 0xffff0000)>>16);

	printf("%0x \n", temp);

	return temp;

}

int main()
{
B data[4];
for (int i = 0; i < 4; i++)
{
data[i].a = 1;
data[i].b = 1;
setA(data, i);
cout << i << data[i].a << data[i].b << endl;
}

for (int i = 0; i < 4; ++i)
{
cout<<i<<data[i].a<<data[i].b << endl;
}

unsigned int a = 0x7f530829;

cout << func(a)<<endl;

return 0;
}

// int main (int argc, char *argv[]) {
// 	// A<int> first(4);
// 	// A<float> second(3.0);
// 	// A<int> third(5);
// 	// cout << second.count << endl;
// 	// cout << sizeof(stru) <<  endl;
// 	// int i, a, b;
// 	// cout << i << " " << a << " " << b << endl;
// 	// int a[][3]={{0,1},{2,3,4},{5,6},{7}};
// 	// std::cout << a[2][1] << endl;
// 	// base *b = new derived();
// 	// int i=0;
// 	// i = i++;
// 	// cout << i << endl;
// 	// bb b;
// 	// cout << b.a << endl;
// }