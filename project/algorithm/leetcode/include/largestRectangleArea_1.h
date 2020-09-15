#pragma once
//https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		heights.push_back(-1);
		stack<int> st;
		int result = 0;
		for (int i = 0; i < heights.size(); i++)
		{
			if (st.empty())
			{
				st.push(i);
			}
			else if (heights[st.top()] < heights[i])
			{
				st.push(i);
			}
			else
			{
				int top;
				while (!st.empty())
				{
					if (heights[st.top()] >= heights[i])
					{
						top = st.top();
						int temp = (i - st.top()) * heights[st.top()];
						if (temp > result)
						{
							result = temp;
						}
						st.pop();
					}
					else
					{
						break;
					}
				}
				st.push(top);
				heights[top] = heights[i];

			}
		}
		return result;
	}
};