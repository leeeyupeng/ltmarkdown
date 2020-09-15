#pragma once
#include <vector>
#include <map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>
using namespace std;
struct  Node;
struct Edge;
struct Node
{
public:
	int index = 0;
	char c = '\0';
	bool isStar = false;
	bool isQuestion = false;

	vector<Edge> m_vectorEdge;
	set<char> m_mapEdge;
	bool isSuccess = false;
};
struct Edge
{
public:
	char c = '\0';
	bool isAll;
	Node* m_nextNode;

	map<int, int> m_map;
	map<int, int> m_map2;

	bool Condition(vector<Node*>& nodes,Node* node,char cc)
	{
		if (m_map.empty())
		{
			if (isAll)
			{
				return true;
			}
			if (c == cc)
			{
				return true;
			}
		}
		else
		{
			map<int, int>::iterator iter;
			iter = m_map.begin();
			while (iter != m_map.end()) {
				if (nodes[iter->first]->c != nodes[iter->second]->c)
				{
					return false;
				}
				iter++;
			}
			if (isAll)
			{
				return true;
			}
			if (c == cc)
			{
				return true;
			}
		}

		return false;
	}
	void Exe(vector<Node*>& nodes, Node* node, char cc)
	{
		map<int, int>::iterator iter;
		iter = m_map2.begin();
		while (iter != m_map2.end()) {
			nodes[iter->first]->c = nodes[iter->second]->c;
			iter++;
		}
	}
};
class FiniteAutomata
{
public:
	Node* m_root;
	vector<Node*> m_vNode;

	stack<char> m_stack;
	FiniteAutomata(const string& pattern)
	{
		m_root = new Node();
		m_vNode.push_back(m_root);

		Node* node = NULL;
		for (int i = 0; i < pattern.size(); i++)
		{
			if (pattern[i] == '*')
			{
				m_vNode.back()->isStar = true;
				continue;
			}
			node = new Node();
			node->index = m_vNode.size();
			node->c = pattern[i];
			//if (i + 1 < pattern.size() && pattern[i + 1] == '*')
			//{
			//	node->isStar = true;
			//}
			if (pattern[i] == '?')
			{
				node->isQuestion = true;
			}			
			//m_vNode.back()->m_mapEdge.insert({ pattern[i] });
			m_vNode.back()->m_vectorEdge.push_back({ pattern[i],node->isQuestion,node });
			m_vNode.push_back(node);
		}

		if (node != NULL)
		{
			node->isSuccess = true;
		}

		for (int i = 0; i < m_vNode.size(); i++)
		{
			vector<Edge> v;
			Node* inode = m_vNode[i];
			for (int j = i; j >= 0; j--)
			{
				Node* jnode = m_vNode[j];
				if (jnode->c != '?' && jnode->isStar == false && inode->m_mapEdge.find(jnode->c)!= inode->m_mapEdge.end())
				{
					continue;
				}

				int offset = (i - j) + 1;
				if (m_vNode[j]->isStar)
				{
					//if (inode->m_mapEdge.find(jnode->c) != inode->m_mapEdge.end())
					//{
					//	continue;
					//}
					//if (flag == true)
					{
						m_vNode[i]->m_mapEdge.insert({ jnode->c });
						m_vNode[i]->m_vectorEdge.push_back({ jnode->c,jnode->isStar || jnode->isQuestion,jnode });
					}

					if (m_vNode[j]->isStar)
					{
						break;
					}
				}
				else
				{
					bool flag = true;
					for (int k = i; k - offset >= 0; k--)
					{
						if (m_vNode[k]->isStar)
						{
							break;
						}
						if (m_vNode[k - offset]->isStar)
						{
							break;
						}
						else if (m_vNode[k - offset]->isQuestion)
						{
							//m_vNode[k - offset]->c = m_vNode[k]->c;
						}
						else if (m_vNode[k]->isQuestion)
						{
							
						}
						else if (m_vNode[k]->c != m_vNode[k - offset]->c)
						{
							flag = false;
							break;
						}
					}

					if (flag == true)
					{
						//m_vNode[i]->m_mapEdge.insert({ jnode->c, });
						m_vNode[i]->m_vectorEdge.push_back({ jnode->c,jnode->isStar || jnode->isQuestion,jnode });

						map<int, int> map1;
						map<int, int> map2;
						for (int k = i; k - offset >= 0; k--)
						{
							if (m_vNode[k - offset]->isStar)
							{
								break;
							}
							else if (m_vNode[k - offset]->isQuestion)
							{
								map2.insert({ k - offset,k });
							}
							else if (m_vNode[k]->isQuestion)
							{
								map1.insert({k,k-offset});
							}
						}

						m_vNode[i]->m_vectorEdge.back().m_map = map1;
						m_vNode[i]->m_vectorEdge.back().m_map2 = map2;

						if (map1.empty() && map2.empty())
						{
							m_vNode[i]->m_mapEdge.insert({ jnode->c });
						}

						//m_vNode[i]->m_mapEdge[jnode->c].m_map = map1;
						//m_vNode[i]->m_mapEdge[jnode->c].m_map2 = map2;
					}

					if (m_vNode[j]->isStar)
					{
						break;
					}
				}
			}

			//for (int j = v.size() - 1; j >= 0; j--)
			//{
			//	m_vNode[i]->m_vectorEdge.push_back(v[j]);
			//}
		}
	}

	Node* Transition(Node* node, char c)
	{
		for (int i = 0; i < node->m_vectorEdge.size(); i++)
		{
			if (node->m_vectorEdge[i].Condition(m_vNode, node, c))
			{
				node->m_vectorEdge[i].Exe(m_vNode, node, c);
				if (node->m_vectorEdge[i].m_nextNode->isQuestion)
				{
					node->m_vectorEdge[i].m_nextNode->c = c;
				}
				return node->m_vectorEdge[i].m_nextNode;
			}
		}

		//for(map<char,Edge>::iterator iter = node->m_mapEdge.begin();iter != node->m_mapEdge.end(); iter ++)
		//{
		//	if (iter->second.Condition(m_vNode,node,c))
		//	{
		//		iter->second.Exe(m_vNode, node, c);
		//		if (iter->second.m_nextNode->isQuestion)
		//		{
		//			iter->second.m_nextNode->c = c;
		//		}
		//		return iter->second.m_nextNode;
		//	}
		//}
		return NULL;
	}

	bool Pattern(const string& s)
	{
		if (m_vNode.size() == 1 && m_root->isStar == true)
		{
			return true;
		}
		Node* node = m_root;
		for (int i = 0; i < s.size(); i++)
		{
			node = Transition(node,s[i]);

			if (node == NULL)
			{
				return false;
			}
		}
		return node->isSuccess;
	}
};