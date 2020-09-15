#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
using namespace std;

class Solution {
private:
	int mergesort(vector<int>& nums, vector<int>& temp, int index, int n) {
		if (n <= 1) { return 0; }
		int mid = n >> 1;
		int count = 0;
		count += mergesort(nums, temp, index,mid);
		count += mergesort(nums, temp, index+mid, n - mid);
		count += merge(nums,temp,index,mid,n);
		return count;
	}
	int merge(vector<int>& nums, vector<int>& temp, int index, int mid,int n) {
		int i = 0, j = 0;
		int count = 0;
		while (i < mid || j < n-mid) {
			if (i < mid&&j < n - mid) {
				if (nums[index + i] <= nums[index + mid + j]) {
					temp[index + i + j] = nums[index + i];
					i++;
				}
				else {
					temp[index + i + j] = nums[index + mid + j];
					count += mid - i;
					j++;
				}
			}
			else if (i < mid) {
				temp[index + i + j] = nums[index + i];
				i++;
			}
			else if(j < n - mid){
				temp[index + i + j] = nums[index + mid + j];
				j++;
			}
		}
		for (int i = index; i < index+n; i++) {
			nums[i] = temp[i];
		}
		return count;
	}
public:
	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		vector<int> temp(n);
		int ans = mergesort(nums, temp, 0, n);
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> v = {
//		7,5,6,4
//	};
//
//	int ans = s.reversePairs(v);
//	cout << ans;
//	system("PAUSE");
//	return 0;
//}