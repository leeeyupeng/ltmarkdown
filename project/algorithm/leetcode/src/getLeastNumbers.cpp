//#pragma once
//#include <iostream>
//#include <vector>
//#include <list>
//#include <stack>
//#include <queue>
//#include <string>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <ctime>
//#include <regex>
//using namespace std;
//
//#include "getLeastNumbers.h"
//vector<int> Solution::getLeastNumbers(vector<int>& arr, int k) {
//	int n = arr.size();
//	priority_queue<int> q(arr.begin(), arr.begin() + k);
//	if (k > 0) {
//		for (int i = k; i < n; i++) {
//			if (q.top() > arr[i]) {
//				q.pop();
//				q.push(arr[i]);
//			}
//		}
//	}
//
//	vector<int> v(k);
//	for (int i = k - 1; i >= 0; i--) {
//		v[i] = q.top();
//		q.pop();
//	}
//	return v;
//}
