#include <iostream>
#include <pthread.h>
#include <string>

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// template <class T>
class Singleton {
protected:
	Singleton() {}

private:
	// static T* instance;
	static Singleton* instance;

public:
	static Singleton* createInstance() {
		// pthread_mutex_lock(&mutex);
		// if (instance == NULL) {
		// 	instance = new Singleton();
		// }
		// pthread_mutex_unlock(&mutex);
		return instance;
	}

	// static T* getInstance() {
	// 	return instance;
	// }

};

// 外部初始化 before invoke main
// 静态实例初始化在程序开始时进入主函数之前就由主线程以单线程方式完成了初始化
Singleton* Singleton::instance = new Singleton;

int main (char *argv[], int argc) {
	Singleton *singleton = Singleton::createInstance();
	cout << singleton << endl;
	return 0;
}