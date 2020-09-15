#include"leetcode.h"

#include "tree/MinHeap_2.h"
#include "tree/BITree.h"
using namespace lt::tree;
class Solution {
private:
	bool cmpsort(const vector<int>& a, const vector<int>& b) {
		if (a[1] == b[1]) {
			return a[0] < b[0];
		}             
		return a[1] < b[1];
	}
	bool cmpsort2(const int& a, const int& b) {
		if (this->courses[a][0] == this->courses[b][0]) {
			return this->courses[a][1] < this->courses[b][1];
		}
		return this->courses[a][0] < this->courses[b][0];
	}
	bool cmp(vector<vector<int>>& courses, const int& a, const int& b) {
		if (courses[a][0] == courses[b][0]) {
			return courses[a][1] < courses[b][1];
		}
		return courses[a][0] < courses[b][0];
	}
	vector<vector<int>> courses;
public:
	int scheduleCourse(vector<vector<int>>& courses) {
		this->courses = courses;
		int n = this->courses.size();

		using std::placeholders::_1;
		using std::placeholders::_2;
		
		sort(this->courses.begin(), this->courses.end(),std::bind(&Solution::cmpsort,this, _1, _2));
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			arr[i] = i;
		}
		sort(arr.begin(), arr.end(), std::bind(&Solution::cmpsort2, this, _1, _2));
		BITree bitree;
		bitree.init(n);
		int ans = 0;
		int index = 0;
		int startday = 0;
		int nowday = 0;
		int sumday = 0;
		bool fflag = true;
		bool* flag = (bool*)malloc(sizeof(bool) * n);
		memset(flag, 0,sizeof(bool) * n);
		for(int k = 0; k < n; k ++){
			index = arr[k];
			sumday = bitree.getSum(index-1);
			//cout << courses[index][0] << endl;
			if (sumday + this->courses[index][0] > this->courses[index][1]) { continue; }
			fflag = true;
			sumday += this->courses[index][0];
			for (int i = index + 1; i < n; i++) {
				if (flag[i] == true) {
					sumday += this->courses[i][0];
					if (sumday > this->courses[i][1]) {
						fflag = false;
						break;
					}
				}
			}
			if (fflag == false) { continue; }
			ans++;
			flag[index] = true;
			bitree.updateBITree(index, this->courses[index][0]);
		}
		free(flag);
		return ans;
	}
};
