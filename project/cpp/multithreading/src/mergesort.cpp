#include <iostream>
#include <thread>
#include <vector>
#include <functional>

using namespace std;

void merge(vector<int>& nums, int s, int mid, int e) {
	vector<int> lnums, rnums; // lnums, rnumsΪ���������У�nums���ڴ�źϲ��������
	for (int i = s; i <= e; i++) {
		if (i <= mid) {
			lnums.push_back(nums[i]);
		}
		else {
			rnums.push_back(nums[i]);
		}
	}

	int l = 0, r = 0, k = s;
	// �Ƚ�����ָ��(l��r)��ָ���Ԫ�أ�ѡ�����С��Ԫ��(����)���뵽�ϲ��ռ䣬
	// ���ƶ�ָ�뵽��һλ�ã�ֱ������һ��ָ�볬������β
	while (l < lnums.size() && r < rnums.size()) {
		if (lnums[l] < rnums[r]) {
			nums[k++] = lnums[l++];
		}
		else {
			nums[k++] = rnums[r++];
		}
	}
	// ����һ����ʣ�µ�����Ԫ��ֱ�Ӹ��Ƶ��ϲ�����β
	while (l < lnums.size()) {
		nums[k++] = lnums[l++];
	}
	while (r < rnums.size()) {
		nums[k++] = rnums[r++];
	}
}

void mergeSort(vector<int>& nums, int s, int e) {
	if (s >= e) {
		return;
	}

	int mid = (s + e) / 2;
	// ���²�֣��������У����Զ��߳�
	// ���ʣ�ΪʲôҪ��bind()��thread t1(mergeSort,std::ref(nums),s,mid);�������
	// std::bindĬ�ϲ��ò����Ŀ������������ã���std::refת��Ϊ����
	thread t1(std::bind(mergeSort, std::ref(nums), s, mid));
	thread t2(std::bind(mergeSort, std::ref(nums), mid + 1, e));
	t1.join();
	t2.join();
	// mergeSort(nums,s,mid);
	// mergeSort(nums,mid+1,e);
	// ���Ϻϲ�
	merge(nums, s, mid, e);
}

vector<int> sortArray(vector<int>& nums) {
	// �鲢����
	vector<int> arr = nums; // Ϊ�˲��ı�ԭ����
	mergeSort(arr, 0, arr.size() - 1);
	return arr;
}

#define MAX 200
//int main() {
//	vector<int> nums;
//	for (int i = 0; i < MAX; i++) {
//		nums.push_back(rand());
//	}
//	vector<int>	re;
//	re = sortArray(nums);
//	for (int num : re) {
//		cout << num << " ";
//	}
//	cout << endl;
//	return 0;
//}

