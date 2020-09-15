#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <time.h>

#define TEST_DATA_LENGTH 10000000 //每个线程操作次数
#define THREAD_NUM 8 //线程个数

using namespace std;//引入std命名空间

mutex m;//声明互斥锁m

long n_total = 0;
long m_total = 0;
atomic<long> a_total = 0;//原子量的初始化

//在不采用互斥锁和原子类的情况下
void test_f_normal()
{
	for (int i = 0; i < TEST_DATA_LENGTH; i++)
	{
		n_total += 1;

	}
}

//使用mutex互斥锁
void test_f_mutex()
{
	for (int i = 0; i < TEST_DATA_LENGTH; i++)
	{
		m.lock();
		m_total += 1;
		m.unlock();
	}
}
//使用原子操作
void test_f_atomic()
{
	for (int i = 0; i < TEST_DATA_LENGTH; i++)
	{
		a_total += 1;
	}
}




void main_test()
{
	thread ts[THREAD_NUM];
	//normal mode ,result is error
	clock_t start = clock();

	for (int i = 0; i < THREAD_NUM; i++)
	{
		ts[i] = thread(&test_f_normal);
	}

	for (int i = 0; i < THREAD_NUM; i++)
	{
		ts[i].join();
	}

	clock_t end = clock();
	cout << "total: " << n_total << endl;
	cout << "test_f_normal: " << end - start << endl;


	//use mutex ,
	clock_t mstart = clock();

	for (int i = 0; i < THREAD_NUM; i++)
	{
		ts[i] = thread(&test_f_mutex);
	}

	for (int i = 0; i < THREAD_NUM; i++)
	{
		ts[i].join();
	}

	clock_t mend = clock();
	cout << "total: " << m_total << endl;
	cout << "test_f_mutex: " << mend - mstart << endl;

	//use atomic
	clock_t astart = clock();

	for (int i = 0; i < THREAD_NUM; i++)
	{
		ts[i] = thread(&test_f_atomic);
	}

	for (int i = 0; i < THREAD_NUM; i++)
	{
		ts[i].join();
	}

	clock_t aend = clock();
	cout << "total: " << a_total << endl;
	cout << "test_f_atomic: " << aend - astart << endl;

	system("pause");
	return;
}