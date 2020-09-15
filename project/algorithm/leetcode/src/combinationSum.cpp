#include"leetcode.h"
class Solution {
private:
	int n;
	int m_target;
	vector<int> m_candidates;
	vector<int> m_v;
	vector<vector<int>> m_ans;
	static bool compare(int a, int b)
	{
		return a > b;
	}
public:
	void DFS(int index, int value) {		
		if (value == m_target) {
			m_ans.push_back(m_v);
			return;
		}
		if (index == n) { return; }
		
		for (int i = 0; i <= (m_target - value) / m_candidates[index]; i++) {
			DFS(index + 1,value + i * m_candidates[index]);
			m_v.push_back(m_candidates[index]);
		}

		for (int i = 0; i <= (m_target - value) / m_candidates[index]; i++) {
			m_v.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		m_candidates = candidates;
		sort(m_candidates.begin(), m_candidates.end(), Solution::compare);
		m_target = target;
		n = m_candidates.size();
		DFS(0, 0);
		return m_ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> matrix{
//2,3,6,7
//	};
//	vector<vector<int>> ans = s.combinationSum(matrix,7);
//	//cout << ans;
//	system("PAUSE");
//
//	return 0;
//
//}