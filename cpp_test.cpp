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

// class A
// {
// public:
// int a;
// };

// class B : public A
// {
// public:
// int b;
// };

// void setA(A* array, int i)
// {
// array[i].a = 2;
// }

int func(unsigned int i) {

	// unsigned int temp = i;

	// temp = (temp & 0x55555555) + ((temp & 0xaaaaaaaa)>>1);

	// printf("%0x \n", temp);

	// temp = (temp & 0x33333333) + ((temp & 0xcccccccc)>>2);

	// printf("%0x \n", temp);

	// temp = (temp & 0x0f0f0f0f) + ((temp & 0xf0f0f0f0)>>4);

	// printf("%0x \n", temp);

	// temp = (temp & 0xff00ff) + ((temp & 0xff00ff00)>>8);

	// printf("%0x \n", temp);

	// temp = (temp & 0xffff) + ((temp & 0xffff0000)>>16);

	// printf("%0x \n", temp);

	// return temp;

}

// struct AA {
// 	int a;
// 	short b;
// 	int c;
// 	char d;
// };

// struct BB {
// 	long a;
// 	char b;
// 	char c;
// 	short e;
// 	int d;
// };

// struct AssignOperator {
// 	AssignOperator(int _b) : size(_b) {
// 	}
// 	int size;
// };

// struct A {
// 	A(){}
// 	~A(){}
// 	int a;
// 	int b;
// };

// struct B {
// 	B(){}
// 	~B(){}
// 	int a;
// 	char b;
// 	static double c;
// };

// struct C
// {
// 	C(){}
// 	~C(){}
// 	int a;
// 	short b;
// 	virtual int c() {}
// };

// class A
// {
// public:
//     A(){cout<<"1";}
//     A(A &a){cout <<"2";}
//     ~A() {cout<<"3";}
// };

// class B
// {
// public:
//     B(){cout <<"4";}
//     B(B &b){cout<<"5";}
//     ~B(){cout<<"6";}
// };
// class A{
// public:
// 	int a;
// 	A () {}
// 	A(const A &other) {
// 		cout << 3 << endl;
// 		a = other.a;
// 	}
// 	A(A &other) {
// 		cout << 2 << endl;
// 	}
// 	A (int n) {
// 		cout << 1 << endl;
// 		a = n;
// 	}
// 	virtual ~A(){}
// };

class CMyString {
public:
	CMyString(char *pData = NULL);
	CMyString(const CMyString &str);
	virtual ~CMyString();
	CMyString & operator=(const CMyString &str) {
		// if (&str == this) return *this;	// &str == this instead of str == *this
		// int n = strlen(str.m_pData)+1;	// do not forget  plus 1
		// char *tmp = this->m_pData;
		// this->m_pData = new char[n];
		// strcpy(this->m_pData, str.m_pData);
		// delete []tmp;
		// tmp = NULL;	// release memory only after we alloc memory successfully
		if (&str != this) {
			CMyString tmp(str);	// tmp obejct will be dealloced out of if statement
			char *tmpData = tmp.m_pData;
			tmp.m_pData = this->m_pData;
			this->m_pData = tmpData;
		}
		return *this;
	}

private:
	char *m_pData;
};

int main() {
	cout << (1<<31) << endl;
	cout << (-1>>2) << endl;
	
	// int first = 1, second = 1;
	// for (int i=0; i<100; i++) {
	// 	int sum = first + second;
	// 	first = second;
	// 	second = sum;
	// 	cout << sum << " ";
	// }
	// A aa = 10;
	// A aa(10);
	// aa = 20;
	// A bb = aa;
	// cout << sizeof(A) << endl;
	// A* pa = B(A());
 //    delete pa;
 //    return 0;
	// char array[] = "abcde";
	// char* s = array;
	// cout<<sizeof(array)<<strlen(array)<<sizeof(s)<<strlen(s);
	// char *bb = new char(sizeof(B));
	// B *b = new(bb) B();
	// cout << &(*b) << endl;
	// cout << &(bb) << endl;
	// cout << sizeof(A) << endl;
	// cout << sizeof(b) << endl;
	// cout << sizeof(B) << endl;
	// cout << sizeof(C) << endl;
	// AssignOperator a(1);
	// AssignOperator b(2);
	// b = a;
	// cout << &a << " " << &b << endl;
	// cout << b.size << endl;
	// cout << sizeof(AA) << endl;	//按最长字节对齐
	// cout << sizeof(BB) << endl; 
// B data[4];
// for (int i = 0; i < 4; i++)
// {
// data[i].a = 1;
// data[i].b = 1;
// setA(data, i);
// cout << i << data[i].a << data[i].b << endl;
// }

// for (int i = 0; i < 4; ++i)
// {
// cout<<i<<data[i].a<<data[i].b << endl;
// }

// unsigned int a = 0x7f530829;

// cout << func(a)<<endl;

	// int i = -2;
	// int h = 2;
	// int j = ~2+1;
	// int k = ~(-2)+1;
	// int x = (2^1);
	// int t = (2^31)-3;
	// int result = t & ~t;
	// int t = 2^31-3;
	// cout << t << endl;

	// printf("%0x\n", i);
	// printf("%0x\n", j);
	// printf("%0x\n", h);
	// printf("%0x\n", k);
	// printf("%d\n", x);
	// printf("%0x\n", x);
	// printf("%0x\n", t);
	// printf("%0x\n", result);

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