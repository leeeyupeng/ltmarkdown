#include"leetcode.h"

#define MAX ((long long)INT_MAX-(long long)INT_MIN + 1)
class MedianFinder {
private:	
	unordered_map<long long, int> map;
	long long MAXX = MAX + 10;
	int bitnums;
	void addbitree(long long index) {
		while (index <= MAXX) {
			map[index] ++;
			index = index + (index&((~index) + 1));
		}
	}
	long long getindex(int count) {
		long long index = 0;
		int bits = bitnums;
		int countnums = 0;
		long long iindex;
		long long one = 1;
		while (bits > 0) {
			iindex = index | (one << (bits - 1));
			if (countnums + map[iindex] < count) {
				index = iindex;
				countnums += map[iindex];
			}
			bits--;
		}
		if (countnums < count) { index++; }
		return index;
	}
	int getbitnums() {
		long long index = MAXX;
		int bitnums = 0;
		int nums = 0;
		while (index > 0) {
			nums++;
			if ((index & 0x1) == 0x1) {
				bitnums = nums;
			}
			index = index >> 1;			
		}
		return bitnums;
	}

	int nums;
public:
	/** initialize your data structure here. */
	MedianFinder() {
		nums = 0;
		map.clear();
		bitnums = getbitnums();
	}

	void addNum(int num) {
		nums++;
		addbitree((long long)num - (long long)INT_MIN + 1);
	}

	double findMedian() {
		if ((nums & 0x1) == 0x1) {
			return getindex((nums>>1) + 1) + (long long)INT_MIN - 1;
		}
		else {
			long long i1 = getindex(nums >> 1) + (long long)INT_MIN - 1;
			long long i2 = getindex((nums >> 1) + 1) + (long long)INT_MIN - 1;
			return i1 * 0.5f + i2 * 0.5f;
		}
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

//int main() {
//	MedianFinder* obj = new MedianFinder();
//	obj->addNum(INT_MAX);
//	double param_2 = obj->findMedian();
//	obj->addNum(220);
//	param_2 = obj->findMedian();
//	obj->addNum(2200);
//	param_2 = obj->findMedian();
//	obj->addNum(INT_MIN);
//	param_2 = obj->findMedian();
//	obj->addNum(INT_MAX);
//	param_2 = obj->findMedian();
//
//	system("PAUSE");
//
//	return 0;
//}