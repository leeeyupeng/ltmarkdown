#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> nums3(nums1.begin(),nums1.begin() + m);
		vector<int>::iterator ite1 = nums1.begin();
		vector<int>::iterator ite3 = nums3.begin();
		vector<int>::iterator ite2 = nums2.begin();
		while (ite3 != nums3.end() || ite2 != nums2.end()) {
			if (ite3 != nums3.end() && ite2 != nums2.end()) {
				if (*ite3 <= *ite2) { *ite1 = *ite3; ite1++; ite3++; }
				else { *ite1 = *ite2; ite1++; ite2++; }
			}
			else if (ite3 != nums3.end()) { *ite1 = *ite3; ite1++; ite3++; }
			else if(ite2 != nums2.end()) { *ite1 = *ite2; ite1++; ite2++; }
		}
	}
};