////future1.cpp ʹ��ȫ�ֱ������ݱ������̷߳��ؽ����ʹ����������֪ͨ�����߳��ѻ�ý��
//
//#include <vector>
//#include <numeric>
//#include <iostream>
//#include <chrono>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//int res = 0;						//��������ȫ�ֱ���
//std::mutex mu;						//������ȫ�ֱ���
//std::condition_variable cond;       //ȫ����������
//
//void accumulate(std::vector<int>::iterator first,
//	std::vector<int>::iterator last)
//{
//	int sum = std::accumulate(first, last, 0);      //��׼����ͺ���
//	std::unique_lock<std::mutex> locker(mu);
//	res = sum;
//	std::cout << "accumulate" << std::endl;
//	std::this_thread::sleep_for(std::chrono::seconds(1));
//	std::cout << "accumulate" << std::endl;
//	locker.unlock();
//	cond.notify_one();              // ��һ���ȴ��̷߳��������������㡱��֪ͨ
//}
//
//int main()
//{
//	std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };
//	std::thread work_thread(accumulate, numbers.begin(), numbers.end());
//
//	std::cout << "work_thread" << std::endl;
//	std::unique_lock<std::mutex> locker(mu);
//	cond.wait(locker, []() { return res; });   //����������������ѣ�������Ƿ񱻸ı䣬Ϊ����ֱ�ӷ��أ�Ϊ��������ȴ�
//	std::cout << "result=" << res << '\n';
//	std::cout << "work_thread" << std::endl;
//	locker.unlock();
//	work_thread.join();         //�����ȴ��߳�ִ�����
//
//	getchar();
//	return 0;
//}
