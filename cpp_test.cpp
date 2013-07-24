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