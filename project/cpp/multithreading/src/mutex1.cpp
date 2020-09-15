//// mutex1.cpp 		ͨ��������lock��unlock��������ȫ�ֱ���
//
//#include <chrono>
//#include <mutex>
//#include <thread>
//#include <iostream> 
//
//std::chrono::milliseconds interval(100);
//
//std::mutex mutex;
//int job_shared = 0; //�����̶߳����޸�'job_shared',mutex�������˱���
//int job_exclusive = 0; //ֻ��һ���߳����޸�'job_exclusive',����Ҫ����
//
////���߳�ֻ���޸� 'job_shared'
//void job_1()
//{
//	mutex.lock();
//	std::this_thread::sleep_for(5 * interval);  //�job_1�������ȴ�
//	++job_shared;
//	std::cout << "job_1 shared (" << job_shared << ")\n";
//	mutex.unlock();
//}
//
////���߳�ֻ���޸� 'job_shared'
//void job_12()
//{
//	mutex.lock();
//	std::this_thread::sleep_for(5 * interval);  //�job_1�������ȴ�
//	++job_shared;
//	std::cout << "job_12 shared (" << job_shared << ")\n";
//	mutex.unlock();
//}
//// ���߳����޸�'job_shared'��'job_exclusive'
//void job_2()
//{
//	while (true) {    //����ѭ����ֱ����������޸�'job_shared'
//		if (mutex.try_lock()) {     //���Ի�����ɹ����޸�'job_shared'
//			++job_shared;
//			std::cout << "job_2 shared (" << job_shared << ")\n";
//			mutex.unlock();
//			return;
//		}
//		else {      //���Ի����ʧ��,�����޸�'job_exclusive'
//			++job_exclusive;
//			std::cout << "job_2 exclusive (" << job_exclusive << ")\n";
//			std::this_thread::sleep_for(interval);
//		}
//	}
//}
//
//void job_11()
//{
//	std::lock_guard<std::mutex> lockg(mutex);    //��ȡRAII���������뿪��������Զ���������
//	std::this_thread::sleep_for(5 * interval);  //�job_1�������ȴ�
//	++job_shared;
//	std::cout << "job_1 shared (" << job_shared << ")\n";
//}
//
//void job_22()
//{
//	while (true) {    //����ѭ����ֱ����������޸�'job_shared'
//		std::unique_lock<std::mutex> ulock(mutex, std::try_to_lock);		//�Գ��������Դ���������
//		//���Ի�����ɹ����޸�'job_shared'
//		if (ulock) {
//			++job_shared;
//			std::cout << "job_2 shared (" << job_shared << ")\n";
//			return;
//		}
//		else {      //���Ի����ʧ��,�����޸�'job_exclusive'
//			++job_exclusive;
//			std::cout << "job_2 exclusive (" << job_exclusive << ")\n";
//			std::this_thread::sleep_for(interval);
//		}
//	}
//}
//
//
//int main()
//{
//	std::thread thread_1(job_1);
//	std::thread thread_2(job_12);
//
//	thread_1.join();
//	thread_2.join();
//
//	getchar();
//	return 0;
//}
