#include <iostream>
#include <thread>
#include <vector>
#include <functional>

using namespace std;

void merge(vector<int>& nums, int s, int mid, int e) {
	vector<int> lnums, rnums; // lnums, rnums为两个子序列，nums用于存放合并后的序列
	for (int i = s; i <= e; i++) {
		if (i <= mid) {
			lnums.push_back(nums[i]);
		}
		else {
			rnums.push_back(nums[i]);
		}
	}

	int l = 0, r = 0, k = s;
	// 比较两个指针(l和r)所指向的元素，选择相对小的元素(升序)放入到合并空间，
	// 并移动指针到下一位置，直到其中一个指针超出序列尾
	while (l < lnums.size() && r < rnums.size()) {
		if (lnums[l] < rnums[r]) {
			nums[k++] = lnums[l++];
		}
		else {
			nums[k++] = rnums[r++];
		}
	}
	// 将另一序列剩下的所有元素直接复制到合并序列尾
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
	// 向下拆分，独立进行，可以多线程
	// 疑问：为什么要用bind()，thread t1(mergeSort,std::ref(nums),s,mid);编译错误？
	// std::bind默认采用参数的拷贝而不是引用，用std::ref转化为引用
	thread t1(std::bind(mergeSort, std::ref(nums), s, mid));
	thread t2(std::bind(mergeSort, std::ref(nums), mid + 1, e));
	t1.join();
	t2.join();
	// mergeSort(nums,s,mid);
	// mergeSort(nums,mid+1,e);
	// 向上合并
	merge(nums, s, mid, e);
}

vector<int> sortArray(vector<int>& nums) {
	// 归并排序
	vector<int> arr = nums; // 为了不改变原数组
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

