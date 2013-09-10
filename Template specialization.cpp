#include <iostream>

using namespace std;

template <class T>
class mycontainer {
	T element;
public:
	mycontainer(T arg) {
		element = arg;
	}

	T increase() {
		return ++element;
	}
};

template <>
class mycontainer<char>
{
	char element;
public:
	mycontainer(char arg) {
		element = arg;
	}

	char increase() {
		if (element >= 'a' && element <= 'z')
			element = element+('A'-'a');
		return element;
	}
};

int main (char *argv[], int argc) {
	mycontainer<int> myint(8);
	cout << myint.increase() << endl;
	mycontainer<char> mychar('d');
	cout << mychar.increase() << endl;
	return 0;
}