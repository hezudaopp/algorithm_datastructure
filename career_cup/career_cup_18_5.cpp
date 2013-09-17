#include <iostream>
#include <pthread.h>//头文件是必须的，符合posix标准使程序可移植众多平台
// #include <thread>

using namespace std;

#define PTHREAD_NUM 6

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  //静态分配
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;    //静态分配

bool isEnableA = true;
bool isEnableB = false;
bool isEnableC = false;

class Hello {
public:
    static void* A(void *args) {
        pthread_mutex_lock(&mutex);
        while (!isEnableA)
            pthread_cond_wait(&cond, &mutex);
        cout << "A\n";
        isEnableA = false;
        isEnableB = true;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }

    static void* B(void *args) {
        pthread_mutex_lock(&mutex);
        while (!isEnableB)
            pthread_cond_wait(&cond, &mutex);
        cout << "B\n";
        isEnableB = false;
        isEnableC = true;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }

    static void* C(void *args) {
        pthread_mutex_lock(&mutex);
        while (!isEnableC)
            pthread_cond_wait(&cond, &mutex);
        cout << "C\n";
        isEnableC = false;
        isEnableA = true;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
};

int main()
{

    pthread_t tids[PTHREAD_NUM];//定义线程的id变量，多个变量可以声明为数组使用
    
    pthread_create(&tids[0], NULL, Hello::A, NULL);//参数依次是：创建的线程id，线程参数，调用函数名，传入的函数参数

    pthread_create(&tids[1], NULL, Hello::B, NULL);//参数依次是：创建的线程id，线程参数，调用函数名，传入的函数参数

    pthread_create(&tids[2], NULL, Hello::C, NULL);//参数依次是：创建的线程id，线程参数，调用函数名，传入的函数参数

    pthread_create(&tids[4], NULL, Hello::A, NULL);//参数依次是：创建的线程id，线程参数，调用函数名，传入的函数参数

    pthread_create(&tids[5], NULL, Hello::B, NULL);//参数依次是：创建的线程id，线程参数，调用函数名，传入的函数参数

    pthread_create(&tids[6], NULL, Hello::C, NULL);//参数依次是：创建的线程id，线程参数，调用函数名，传入的函数参数


    pthread_exit(NULL);//等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；

    return 0;
}