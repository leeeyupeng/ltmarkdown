////future4.cpp ʹ��async���ݱ������̷߳��ؽ��
//
//#include <vector>
//#include <thread>
//#include <future>
//#include <numeric>
//#include <iostream>
//#include <chrono>
//
//int accumulate(std::vector<int>::iterator first,
//	std::vector<int>::iterator last)
//{
//	int sum = std::accumulate(first, last, 0);
//	std::this_thread::sleep_for(std::chrono::seconds(1));
//	std::cout << "accumulate" << std::endl;
//	return sum;
//}
//
//int main()
//{
//	// ��ʾ�� async ���̼߳䴫�ݽ����
//	std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };
//	auto accumulate_future = std::async(std::launch::async, accumulate, numbers.begin(), numbers.end());		//auto�����Զ��ƶϱ���������
//	
//	std::cout << "wait" << std::endl;
//
//	std::cout << "result=" << accumulate_future.get() << '\n';
//
//	getchar();
//	return 0;
//}
