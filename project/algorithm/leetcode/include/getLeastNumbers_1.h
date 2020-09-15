#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

	void traverse(vector<int>& arr, int k,int node) {
		int left, right;
		left = (node << 1) + 1;
		right = left + 1;
		if (right < k) {
			traverse(arr, k, left);
			traverse(arr, k, right);

		}
	}
	void InitHeap(vector<int>& arr, int k) {
		traverse(vector<int>& arr, k,0);
	}
	void UpdateHeap(vector<int>& arr, int value) {
	}
	void SortHeap(vector<int>& arr, int k) {

	}
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		int n = arr.size();
		InitHeap(arr,k);
		for (int i = k; i < n; i++) {
			if (arr[0] > arr[i]) {
				UpdateHeap(arr, arr[i]);
			}
		}
		SortHeap(arr, k);
		arr.resize(k);
		vector<int> ans = arr;
		return ans;
	}
};