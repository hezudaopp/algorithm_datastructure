#include <iostream>

using namespace std;

class base
{
public:
	base() {
		cout << "base constructor" << endl;
	}
	virtual ~base() {
		cout << "base destructor" << endl;
	}

	/* data */
};

class derived : public base{
public:
	derived() {
		cout << "derived constructor" << endl;
	}
	~derived() {
		cout << "derived destructor" << endl;
	}
};

int main (char *argv, int argc) {
	base *b = new derived();
	delete(b);
	return 0;
}