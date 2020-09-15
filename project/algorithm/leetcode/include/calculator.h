#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <vector>
using namespace std;

//https://leetcode-cn.com/problems/basic-calculator/

//µ›πÈ
namespace calculatorrecursive
{
	//¥ Àÿ
	struct morpheme
	{
		long digital;
		char ops;
		int type;
		int priority = -1;

		morpheme(int t, int d, char o, int p)
		{
			type = t;
			digital = d;
			ops = o;
			priority = p;
		}

		morpheme()
		{
		}
	};
	string skipspace(string s)
	{
		string ans;

		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			if (c != ' ') {
				ans.push_back(c);
			}
		}
		return ans;
	}
	void scanning(const string str, vector<morpheme>& v)
	{
		char morphemetype[] = { ')','+','-','*','/','(' };
		int morphemetypelength = 6;

		long digit = 0;
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			char c = str[i];
			if (c == ' ')
			{
				continue;
			}
			bool flag = false;
			for (int j = 0; j < morphemetypelength; j++)
			{
				if (c == morphemetype[j])
				{
					v.push_back(morpheme(j, 0, c, j));
					flag = true;
				}
			}

			if (flag == false)
			{
				digit = digit * 10 + (int)c - 0x30;

				if (i == len - 1 || (str[i + 1] < '0' || str[i + 1] > '9'))
				{
					v.push_back(morpheme(-1, digit, '\0', -1));
					digit = 0;
				}
			}
		}
	}
	long calculator(vector<morpheme>& v, int left, int right);
	int recursive(vector<morpheme>& out,vector<morpheme>& in,int left,int right)
	{
		for (int i = left; i < right; )
		{
			if (in[i].type == 5)
			{
				vector<morpheme> outtemp2;
				int bracketright = recursive(outtemp2,in, i + 1,right);
				for (int j = 0; j < outtemp2.size(); j++)
				{
					out.push_back(outtemp2[j]);
				}
				i= bracketright + 1;
			}
			else if (in[i].type == 0)
			{
				long value = calculator(out, 0, out.size());
				out.clear();
				out.push_back(morpheme(-1, value, '\0', -1));
				return i;
			}
			else
			{
				out.push_back(in[i]);
				i++;
			}
		}
		return right;
	}

	long calculator(vector<morpheme>& v,int left,int right)
	{
		vector<morpheme> r1;
		long curvalue = 0;
		for (int i = left; i < right;)
		{
			if (v[i].type == -1)
			{
				curvalue = v[i].digital;
				i++;
			}
			else if (v[i].priority == 3)
			{
				curvalue = curvalue * v[i + 1].digital;
				i += 2;
			}
			else if (v[i].priority == 4)
			{
				curvalue = curvalue / v[i + 1].digital;
				i += 2;
			}
			else
			{
				r1.push_back(morpheme(-1, curvalue, '\0', -1));
				r1.push_back(v[i]);
				i++;
			}
		}
		r1.push_back(morpheme(-1, curvalue, '\0', -1));

		long result = 0;
		curvalue = 0;
		for (int i = 0; i < r1.size();)
		{
			if (r1[i].type == -1)
			{
				curvalue = r1[i].digital;
				i++;
			}
			else if (r1[i].priority == 1)
			{
				curvalue = curvalue + r1[i + 1].digital;
				i += 2;
			}
			else if (r1[i].priority == 2)
			{
				curvalue = curvalue - r1[i + 1].digital;
				i += 2;
			}
			else
			{
				break;
			}
		}

		result = curvalue;
		return result;
	}
}

//ƒÊ≤®¿º±Ì¥Ô Ω
namespace calculatorRPN
{
	//¥ Àÿ
	struct morpheme
	{
		long digital;
		char ops;
		int type;
		int priority = -1;

		morpheme(int t, long d, char o, int p)
		{
			type = t;
			digital = d;
			ops = o;
			priority = p;
		}

		morpheme()
		{
		}
	};
	string skipspace(string s)
	{
		string ans;

		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			if (c != ' ') {
				ans.push_back(c);
			}
		}
		return ans;
	}
	void scanning(const string str, vector<morpheme>& v)
	{
		char morphemetype[] = { ')','+','-','*','/','(' };
		int priority[] = { 0,1,1,3,3,5 };
		int morphemetypelength = 6;

		long digit = 0;
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			char c = str[i];
			if (c == ' ')
			{
				continue;
			}
			bool flag = false;
			for (int j = 0; j < morphemetypelength; j++)
			{
				if (c == morphemetype[j])
				{
					v.push_back(morpheme(j, 0, c, priority[j]));
					flag = true;
				}
			}

			if (flag == false)
			{
				digit = digit * 10 + (int)c - 0x30;

				if (i == len - 1 || (str[i + 1] < '0' || str[i + 1] > '9'))
				{
					v.push_back(morpheme(-1, digit, '\0', -1));
					digit = 0;
				}
			}
		}
	}

	vector<morpheme> rpn(vector<morpheme>& v)
	{
		stack<morpheme> r;
		stack<morpheme> opera;
		for (int i = 0; i < v.size(); i++)
		{
			morpheme m = v[i];
			if (m.type == -1)
			{
				r.push(m);
			}
			else if (m.priority == 5)
			{
				opera.push(m);
			}
			else
			{
				while (!opera.empty() && opera.top().priority != 5 && opera.top().priority >= m.priority)
				{
					r.push(opera.top());
					opera.pop();
				}
				
				if (!opera.empty() && opera.top().priority == 5 && m.priority == 0)
				{
					opera.pop();
				}
				if(m.priority != 0)
				{
					opera.push(m);
				}
			}
		}

		while (!opera.empty())
		{
			r.push(opera.top());
			opera.pop();
		}

		vector<morpheme> vv(r.size());
		for (int i = r.size() - 1; i >= 0; i--)
		{
			vv[i] = r.top();
			r.pop();
		}
		
		return vv;
	}

	long calcu(vector<morpheme>& rpn)
	{
		stack<morpheme> s;
		for (int i = 0; i < rpn.size(); i++)
		{
			morpheme m = rpn[i];
			if (m.type == -1)
			{
				s.push(m);
			}
			else
			{
				long left, right;
				right = s.top().digital;
				s.pop();
				left = s.top().digital;
				s.pop();
				long value = 0;
				if (m.type == 1)
				{
					value = left + right;
				}
				else if (m.type == 2)
				{
					value = left - right;
				}
				else if (m.type == 3)
				{
					value = left * right;
				}
				else if (m.type == 4)
				{
					value = left / right;
				}
				s.push(morpheme(-1,value,'\0',-1));
			}
		}

		return s.top().digital;
	}
}
namespace calculatorstack
{
	const char operatorcharacter[] = { ')','-','+','*','/','(' };
	const int operatorcharacterlength = 6;
	struct element
	{
		int digital;
		char operatorcharacter;
		int type;

		element(int t, int d, char o)
		{
			type = t;
			digital = d;
			operatorcharacter = o;
		}

	};
	//’ª µœ÷
	float calcu_stack(const string str)
	{
		vector<element> vectorElement;
		int digit = -1;
		int len = str.length();
		int digitpm = 1;
		element epr(0, 0, '0');
		for (int i = 0; i < len; i++)
		{
			char c = str[i];
			for (int j = 0; j < operatorcharacterlength; j++)
			{
				if (c == operatorcharacter[j])
				{
					if (digit != -1)
					{
						vectorElement.push_back(element(2, digitpm * digit, '0'));
						digit = -1;
						digitpm = 1;
						epr = vectorElement.back();
					}

					if (digitpm == -1)
					{
						vectorElement.push_back(element(1, 0, '-'));
						digitpm = 1;
					}

					if (c == '-' && epr.type == 0)
					{
						digitpm = -1;
					}
					else if (c == '-' && epr.type == 1 && epr.operatorcharacter == '(')
					{
						digitpm = -1;
					}
					else
					{
						digitpm = 1;
						vectorElement.push_back(element(1, -1, c));
						epr = vectorElement.back();
					}
					break;
				}
			}

			if ((int)c >= 0x30 && (int)c <= 0x39)
			{
				if (digit == -1)
				{
					digit = (int)c - 0x30;
				}
				else
				{
					digit = digit * 10 + (int)c - 0x30;
				}
			}
		}
		if (digit != -1)
		{
			vectorElement.push_back(element(2, digitpm * digit, '0'));
		}
		for (unsigned int i = 0; i < vectorElement.size(); i++)
		{
			element e(vectorElement[i]);
			if (e.type == 1)
			{
				cout << "index:" << i << "	value:" << e.operatorcharacter << endl;
			}
			else
			{
				cout << "index:" << i << "	value:" << e.digital << endl;
			}
		}

		stack<float> stackDigital;
		stack<char> stackOperator;

		for (int i = 0; i < vectorElement.size(); i++)
		{
			element e = vectorElement[i];

			if (e.type == 2)
			{
				stackDigital.push(e.digital);
			}
			else
			{
				char c = e.operatorcharacter;
				if (c == ')' && stackOperator.top() == '(')
				{
					stackOperator.pop();
				}
				else
				{
					while (stackOperator.size() > 0)
					{
						char cpr = stackOperator.top();
						if (c == ')' && stackOperator.top() == '(')
						{
							stackOperator.pop();
							break;
						}
						int indexc, indexcpr;
						for (int j = 0; j < operatorcharacterlength; j++)
						{
							if (operatorcharacter[j] == c)
							{
								indexc = j;
							}
							if (operatorcharacter[j] == cpr)
							{
								indexcpr = j;
							}
						}

						bool flag = false;
						if (indexc == indexcpr && (indexcpr == 1 || indexcpr == 2 || indexcpr == 3 || indexcpr == 4))
						{
							flag = true;
						}
						else if ((indexc == 1 || indexc == 2) && (indexcpr == 1 || indexcpr == 2 || indexcpr == 3 || indexcpr == 4))
						{
							flag = true;
						}
						else if ((indexc == 3 || indexc == 4) && (indexcpr == 3 || indexcpr == 4))
						{
							flag = true;
						}
						else if (indexc == 0 && cpr != '(')
						{
							flag = true;
						}
						else if (indexc < indexcpr && cpr != '(')
						{
							flag = true;
						}

						if (flag == true)
						{
							float b = stackDigital.top();
							stackDigital.pop();
							float a = stackDigital.top();
							stackDigital.pop();

							char o = stackOperator.top();
							stackOperator.pop();

							float c = 0;
							if (o == '+')
							{
								c = a + b;
							}
							else if (o == '-')
							{
								c = a - b;
							}
							else if (o == '*')
							{
								c = a * b;
							}
							else if (o == '/')
							{
								c = a / b;
							}
							cout << "abc:" << a << o << b << "=" << c << endl;
							stackDigital.push(c);
						}
						else
						{
							break;
						}
					}

					if (c == ')')
					{
					}
					else
					{
						stackOperator.push(e.operatorcharacter);
					}
				}
			}
		}

		while (stackOperator.size() > 0)
		{

			float b = stackDigital.top();
			stackDigital.pop();

			float a = 0;
			if (stackDigital.size() == 0)
			{
				a = 0;
			}
			else
			{
				a = stackDigital.top();
				stackDigital.pop();
			}

			char o = stackOperator.top();
			stackOperator.pop();

			float c = 0;
			if (o == '+')
			{
				c = a + b;
			}
			else if (o == '-')
			{
				c = a - b;
			}
			else if (o == '*')
			{
				c = a * b;
			}
			else if (o == '/')
			{
				c = a / b;
			}
			cout << "abc:" << a << o << b << "=" << c << endl;
			stackDigital.push(c);
		}
		if (stackOperator.empty() && stackDigital.size() == 1)
		{
			return stackDigital.top();
		}
		else
		{
			cout << "error" << endl;
			return 0.0f;
		}
	}
}

//”Ô∑® ˜ µœ÷
namespace calculatorsyntaxtree
{

	//¥ Àÿ
	struct morpheme
	{
		long digital;
		char operatorcharacter;
		int type;
		int priority = -1;

		morpheme(int t, int d, char o,int p)
		{
			type = t;
			digital = d;
			operatorcharacter = o;
			priority = p;
		}

		morpheme()
		{
		}
	};

	struct SyntaxTreeNode
	{
		int index;
		//long value;
		SyntaxTreeNode * parent;
		SyntaxTreeNode * left;
		SyntaxTreeNode * right;

		SyntaxTreeNode(int idx)
		{
			index = idx;
		}
	};

	void scanning(const string str, vector<morpheme>& v)
	{
		char morphemetype[] = { ')','+','-','*','/','(' };
		int morphemetypelength = 6;

		long digit = 0;
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			char c = str[i];
			if (c == ' ')
			{
				continue;
			}
			bool flag = false;
			for (int j = 0; j < morphemetypelength; j++)
			{
				if (c == morphemetype[j])
				{
					v.push_back(morpheme(j, 0, c,j));
					flag = true;
				}
			}

			if (flag == false)
			{
				digit = digit * 10 + (int)c - 0x30;

				if (i == len - 1 || (str[i + 1] < '0' || str[i + 1] > '9'))
				{
					v.push_back(morpheme(-1, digit, '\0',-1));
					digit = 0;
				}
			}
		}
	}

	SyntaxTreeNode* syntaxtree(vector<morpheme>& v)
	{
		SyntaxTreeNode* root = new SyntaxTreeNode(-1);
		SyntaxTreeNode* pre = NULL;
		pre = root;

		for (int i = 0; i < v.size(); i++)
		{
			SyntaxTreeNode* node = new SyntaxTreeNode(i);

			int priority = v[i].priority;
			if (priority == -1)
			{
				pre->right = node;
				node->parent = pre;
				continue;
			}
			SyntaxTreeNode* smallnode = pre;
			while (smallnode->index != -1)
			{
				if (v[smallnode->index].priority == 5)
				{
					break;
				}
				if (v[smallnode->index].priority >= priority)
				{
					smallnode = smallnode->parent;
				}
				else
				{
					break;
				}
			}

			node->left = smallnode->right;
			smallnode->right = node;
			node->parent = smallnode;


			if (v[node->index].priority == 0 && smallnode->index != -1 && v[smallnode->index].priority == 5)
			{
				pre = smallnode->parent;
			}
			else
			{
				pre = node;
			}
		}

		return root;
	}

	int order(SyntaxTreeNode* node, vector<morpheme>& v)
	{
		int value;
		int priority = v[node->index].priority;
		if (priority == -1)
		{
			value = v[node->index].digital;
		}
		else if (priority == 0)
		{
			value = order(node->left, v);
		}
		else if (priority == 1)
		{
			value = order(node->left, v) + order(node->right, v);
		}
		else if (priority == 2)
		{
			value = order(node->left, v) - order(node->right, v);
		}
		else if (priority == 3)
		{
			value = order(node->left, v) * order(node->right, v);
		}
		else if (priority == 4)
		{
			value = order(node->left, v) / order(node->right, v);
		}
		else if (priority == 5)
		{
			value = order(node->right, v);
		}

		//node->value = value;
		return value;
	}
}