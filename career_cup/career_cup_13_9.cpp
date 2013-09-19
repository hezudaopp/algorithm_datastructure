#include <iostream>

using namespace std;

template <class T>
class smartPoint {
public:
	smartPoint() {
		point = new T();
		refCount = new int();
		*refCount = 1;
	}

	smartPoint(smartPoint<T> &t) {
		cout << "copy construct function" << endl;
		point = t.point;
		refCount = t.refCount;
		(*refCount)++;
	}

	smartPoint<T> &operator=(const smartPoint<T> &t) {
		cout << "operator overload" << endl;
		if (this != &t) {
			refCount = t.refCount;
			(*refCount)++;
			point = t.point;
		}
		return *this;
	}

	virtual ~smartPoint<T> () {
		--(*refCount);
		if (*refCount==0) {
			point = NULL;
			delete point;
			delete refCount;
		}
	}

	int getRefCount() {
		return *this->refCount;
	}

	void printRefCountAddress() {
		cout << refCount << endl;
	}

private:
	T *point;
	int *refCount;


};

int main (char *argv[], int argc) {
	smartPoint<int> sp;
	smartPoint<int> sp1 = sp;
	smartPoint<int> sp2(sp);
	sp2 = sp1;
	cout << sp.getRefCount() << endl;
	cout << sp1.getRefCount() << endl;
	sp.printRefCountAddress();
	sp1.printRefCountAddress();
	sp2.printRefCountAddress();
	return 0;
}