////cond_var2.cpp用条件变量解决轮询间隔难题
//
//#include <iostream>
//#include <deque>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//std::deque<int> q;						//双端队列标准容器全局变量
//std::mutex mu;							//互斥锁全局变量
//std::condition_variable cond;           //全局条件变量
////生产者，往队列放入数据
//void function_1() {
//	int count = 10;
//	while (count > 0) {
//		std::unique_lock<std::mutex> locker(mu);
//		q.push_front(count);			//数据入队锁保护
//		locker.unlock();
//
//		cond.notify_one();              // 向一个等待线程发出“条件已满足”的通知
//
//		std::this_thread::sleep_for(std::chrono::seconds(1));		//延时1秒
//		count--;
//	}
//}
////消费者，从队列提取数据
//void function_2() {
//	int data = 0;
//	while (data != 1) {
//		std::unique_lock<std::mutex> locker(mu);
//
//		//在function_2中，在判断队列是否为空的时候，使用的是while(q.empty())，而不是if(q.empty())，这是因为wait()从阻塞到返回，不一定就是由于notify_one()函数造成的，还有可能由于系统的不确定原因唤醒（可能和条件变量的实现机制有关），这个的时机和频率都是不确定的，被称作伪唤醒。如果在错误的时候被唤醒了，执行后面的语句就会错误，所以需要再次判断队列是否为空，如果还是为空，就继续wait()阻塞；
//		while (q.empty())        //判断队列是否为空
//			cond.wait(locker); // 解锁互斥量并陷入休眠以等待通知被唤醒，被唤醒后加锁以保护共享数据
//		
//		data = q.back();
//		q.pop_back();			//数据出队锁保护
//		locker.unlock();
//		std::cout << "t2 got a value from t1: " << data << std::endl;
//	}
//}
//
//int main() {
//	std::thread t1(function_1);
//	std::thread t2(function_2);
//	t1.join();
//	t2.join();
//
//	getchar();
//	return 0;
//}
