////cond_var2.cpp���������������ѯ�������
//
//#include <iostream>
//#include <deque>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//std::deque<int> q;						//˫�˶��б�׼����ȫ�ֱ���
//std::mutex mu;							//������ȫ�ֱ���
//std::condition_variable cond;           //ȫ����������
////�����ߣ������з�������
//void function_1() {
//	int count = 10;
//	while (count > 0) {
//		std::unique_lock<std::mutex> locker(mu);
//		q.push_front(count);			//�������������
//		locker.unlock();
//
//		cond.notify_one();              // ��һ���ȴ��̷߳��������������㡱��֪ͨ
//
//		std::this_thread::sleep_for(std::chrono::seconds(1));		//��ʱ1��
//		count--;
//	}
//}
////�����ߣ��Ӷ�����ȡ����
//void function_2() {
//	int data = 0;
//	while (data != 1) {
//		std::unique_lock<std::mutex> locker(mu);
//
//		//��function_2�У����ж϶����Ƿ�Ϊ�յ�ʱ��ʹ�õ���while(q.empty())��������if(q.empty())��������Ϊwait()�����������أ���һ����������notify_one()������ɵģ����п�������ϵͳ�Ĳ�ȷ��ԭ���ѣ����ܺ�����������ʵ�ֻ����йأ��������ʱ����Ƶ�ʶ��ǲ�ȷ���ģ�������α���ѡ�����ڴ����ʱ�򱻻����ˣ�ִ�к�������ͻ����������Ҫ�ٴ��ж϶����Ƿ�Ϊ�գ��������Ϊ�գ��ͼ���wait()������
//		while (q.empty())        //�ж϶����Ƿ�Ϊ��
//			cond.wait(locker); // ���������������������Եȴ�֪ͨ�����ѣ������Ѻ�����Ա�����������
//		
//		data = q.back();
//		q.pop_back();			//���ݳ���������
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
