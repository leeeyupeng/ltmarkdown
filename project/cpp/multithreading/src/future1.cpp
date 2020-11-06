////future1.cpp 使用全局变量传递被调用线程返回结果，使用条件变量通知调用线程已获得结果
//
//#include <vector>
//#include <numeric>
//#include <iostream>
//#include <chrono>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//int res = 0;						//保存结果的全局变量
//std::mutex mu;						//互斥锁全局变量
//std::condition_variable cond;       //全局条件变量
//
//void accumulate(std::vector<int>::iterator first,
//	std::vector<int>::iterator last)
//{
//	int sum = std::accumulate(first, last, 0);      //标准库求和函数
//	std::unique_lock<std::mutex> locker(mu);
//	res = sum;
//	std::cout << "accumulate" << std::endl;
//	std::this_thread::sleep_for(std::chrono::seconds(1));
//	std::cout << "accumulate" << std::endl;
//	locker.unlock();
//	cond.notify_one();              // 向一个等待线程发出“条件已满足”的通知
//}
//
//int main()
//{
//	std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };
//	std::thread work_thread(accumulate, numbers.begin(), numbers.end());
//
//	std::cout << "work_thread" << std::endl;
//	std::unique_lock<std::mutex> locker(mu);
//	cond.wait(locker, []() { return res; });   //如果条件变量被唤醒，检查结果是否被改变，为真则直接返回，为假则继续等待
//	std::cout << "result=" << res << '\n';
//	std::cout << "work_thread" << std::endl;
//	locker.unlock();
//	work_thread.join();         //阻塞等待线程执行完成
//
//	getchar();
//	return 0;
//}
