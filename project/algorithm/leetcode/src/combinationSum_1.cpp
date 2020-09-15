#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	int n;
	int m_target;
	vector<int> m_candidates;
	vector<int> m_v;
	vector<vector<int>> m_ans;
	static bool compare(int a, int b)
	{
		return a < b;
	}
public:
	void DFS(int index, int value) {		
		if (value == m_target) {
			//m_ans.push_back(m_v);
			vector<int> vv;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m_v[i]; j++) {
					vv.push_back(m_candidates[i]);
				}
			}
			m_ans.push_back(vv);
			return;
		}
		if (value > m_target) { return; }
		if (index == n) { return; }
		
		if ((m_target - value) < m_candidates[index]) {
			return;
		}

		DFS(index + 1, value);

		m_v[index]+=1;
		DFS(index, value + m_candidates[index]);
		m_v[index] -= 1;
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		m_candidates = candidates;
		sort(m_candidates.begin(), m_candidates.end(), compare);
		m_target = target;
		n = m_candidates.size();
		m_v = vector<int>(n);
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