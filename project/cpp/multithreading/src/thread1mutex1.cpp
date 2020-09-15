////thread2.cpp  ���Ӷ�cout��ʾ�ն���Դ�������ʵĻ���������
//
//#include <iostream>
//#include <thread>
//#include <chrono>
//#include <mutex>
//
//using namespace std;
//
//std::mutex mutex1;
//
//void thread_function(int n)
//{
//	std::thread::id this_id = std::this_thread::get_id();       //��ȡ�߳�ID
//
//	for (int i = 0; i < 5; i++) {
//		mutex1.lock();
//		cout << "Child function thread " << this_id << " running : " << i + 1 << endl;
//		mutex1.unlock();
//		std::this_thread::sleep_for(std::chrono::seconds(n));   //����˯��n��
//	}
//}
//
//class Thread_functor
//{
//public:
//	// functor��Ϊ���ƺ���,C++�еķº�����ͨ������������()�����ʵ�֣�ʹ�������ʹ�ú���һ����������Ķ���
//	void operator()(int n)
//	{
//		std::thread::id this_id = std::this_thread::get_id();
//
//		for (int i = 0; i < 5; i++) {
//			{
//				std::lock_guard<std::mutex> lockg(mutex1);
//				cout << "Child functor thread " << this_id << " running: " << i + 1 << endl;
//			}
//			std::this_thread::sleep_for(std::chrono::seconds(n));   //����˯��n��
//		}
//	}
//};
//
//
//int main()
//{
//	thread mythread1(thread_function, 1);      // ���ݳ�ʼ������Ϊ�̵߳Ĳ���
//	if (mythread1.joinable())                  //�ж��Ƿ���Գɹ�ʹ��join()����detach()������true����ԣ�����false�򲻿���
//		mythread1.join();                     // ʹ��join()�����������߳�ֱ�����߳�ִ�����
//
//	Thread_functor thread_functor;
//	thread mythread2(thread_functor, 3);     // ���ݳ�ʼ������Ϊ�̵߳Ĳ���
//	if (mythread2.joinable())
//		mythread2.detach();                  // ʹ��detach()���������̺߳����̲߳������У����߳�Ҳ���ٵȴ����߳�
//
//	auto thread_lambda = [](int n) {
//		std::thread::id this_id = std::this_thread::get_id();
//		for (int i = 0; i < 5; i++)
//		{
//			mutex1.lock();
//			cout << "Child lambda thread " << this_id << " running: " << i + 1 << endl;
//			mutex1.unlock();
//			std::this_thread::sleep_for(std::chrono::seconds(n));   //����˯��n��
//		}
//	};
//
//	thread mythread3(thread_lambda, 4);     // ���ݳ�ʼ������Ϊ�̵߳Ĳ���
//	if (mythread3.joinable())
//		mythread3.join();                     // ʹ��join()�����������߳�ֱ�����߳�ִ�����
//
//	unsigned int n = std::thread::hardware_concurrency();       //��ȡ���õ�Ӳ������������
//	mutex1.lock();
//	std::cout << n << " concurrent threads are supported." << endl;
//	mutex1.unlock();
//	std::thread::id this_id = std::this_thread::get_id();
//
//	for (int i = 0; i < 5; i++) {
//		{
//			std::lock_guard<std::mutex> lockg(mutex1);
//			cout << "Main thread " << this_id << " running: " << i + 1 << endl;
//		}
//		std::this_thread::sleep_for(std::chrono::seconds(1));
//	}
//
//	getchar();
//	return 0;
//}
