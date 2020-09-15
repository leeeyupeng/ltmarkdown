#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include "ChineseChess.h"
using namespace std;
int PIECEVALUEWEIGHT[2][9]{
	{0,90,40,50,10,10,1000,10,0},
	{0,-90,-40,-50,-10,-10,-1000,-10,0},
};

int PIECEWALKWEIGHT[2][9]{
	{0,5,10,10,10,10,100,10,0},
	{0,-5,-10,-10,-10,-10,-100,-10,0},
};
int PIECEATTACKWEIGHT[2][9]{
	{0,90,40,40,10,10,10000,10,0},
	{0,-90,-40,-40,-10,-10,-10000,-10,0},
};
int PIECEDEFENSEWEIGHT[2][9]{
	{0,90,40,40,10,10,0,10,0},
	{0,-90,-40,-40,-10,-10,0,-10,0},
};
int PIECEBEATTACKWEIGHT[2][9]{
	{0,1,1,1,1,1,1,1,0},
	{0,-1,-40,-40,-10,-10,-10000,-10,0},
};
int PIECEBEDEFENSEWEIGHT[2][9]{
	{0,90,40,40,10,10,0,10,0},
	{0,-90,-40,-40,-10,-10,0,-10,0},
};
struct step
{
	position start;
	position target;
	step(position s, position t) :start(s), target(t)
	{
	}
};
class ChineseChessAIMinMax
{
private:
	ChineseChess* m_cc;
	unsigned char m_board[ROW][COL];
	int m_level;
public:
	void LayoutBoard(ChineseChess& cc, unsigned char p,int level);
	bool MinMaxSearch(position& start, position& target);

private:
	int Evaluation();
	void CanWalk(int p, vector<step>& vstep);

	void _Evaluation_JU(position pos, int pieceweight[ROW][COL][6]);
	void _Evaluation_MA(position pos, int pieceweight[ROW][COL][6]);
	void _Evaluation_PAO(position pos, int pieceweight[ROW][COL][6]);
	void _Evaluation_XIANG(position pos, int pieceweight[ROW][COL][6]);
	void _Evaluation_SHI(position pos, int pieceweight[ROW][COL][6]);
	void _Evaluation_JIANG(position pos, int pieceweight[ROW][COL][6]);
	void _Evaluation_ZU(position pos, int pieceweight[ROW][COL][6]);

	void _CanWalk_JU(position pos, vector<step>& vstep);
	void _CanWalk_MA(position pos, vector<step>& vstep);
	void _CanWalk_PAO(position pos, vector<step>& vstep);
	void _CanWalk_XIANG(position pos, vector<step>& vstep);
	void _CanWalk_SHI(position pos, vector<step>& vstep);
	void _CanWalk_JIANG(position pos, vector<step>& vstep);
	void _CanWalk_ZU(position pos, vector<step>& vstep);

	int _Max(int depth, stack<step>& sta);
	int _Min(int depth, stack<step>& sta);
	int AlphaBeta(int depth, int p,int alpha, int beta, stack<step>& sta);
};
int ChineseChessAIMinMax::Evaluation()
{
	int pieceweight[ROW][COL][6];
	for (unsigned char i = 0; i < ROW; i++)
	{
		for (unsigned char j = 0; j < COL; j++)
		{
			unsigned char p = m_board[i][j] >> 0x7;
			unsigned char piece = m_board[i][j] & 0x0F;
			int weight[4];
			if (piece == JU)
			{
				_Evaluation_JU({i,j}, pieceweight);
			}
			else if (piece == MA)
			{
				_Evaluation_MA({ i,j }, pieceweight);
			}
			else if (piece == PAO)
			{
				_Evaluation_PAO({ i,j }, pieceweight);
			}
			else if (piece == XIANG)
			{
				_Evaluation_XIANG({ i,j }, pieceweight);
			}
			else if (piece == SHI)
			{
				_Evaluation_SHI({ i,j }, pieceweight);
			}
			else if (piece == JIANG)
			{
				_Evaluation_JIANG({ i,j }, pieceweight);
			}
			else if (piece == ZU)
			{
				_Evaluation_ZU({ i,j }, pieceweight);
			}
		}
	}

	int valueweight = 0;
	int walkweight = 0;
	int attackweight = 0;
	int defenseweight = 0;

	int evaluation = 0;

	for (unsigned char i = 0; i < ROW; i++)
	{
		for (unsigned char j = 0; j < COL; j++)
		{
		}
	}
	evaluation = valueweight + walkweight + attackweight + defenseweight;
	return evaluation;
}
void ChineseChessAIMinMax::_Evaluation_JU(position pos, int pieceweight[ROW][COL][6])
{
	unsigned char p = m_board[pos.x][pos.y] >> 0x7;
	unsigned char piece = m_board[pos.x][pos.y] & 0x0F;
	pieceweight[pos.x][pos.y][0] = PIECEVALUEWEIGHT[p][piece];
	int left = pos.x - 1;
	while (left >= 0)
	{
		if (m_board[left][pos.y] == NONE)
		{
			pieceweight[pos.x][pos.y][1] += PIECEWALKWEIGHT[p][piece];
			left--;
			continue;
		}
		else
		{
			unsigned char pleft = m_board[left][pos.y] >> 0x7;
			unsigned char pieceleft = m_board[left][pos.y] & 0x0F;
			if (pleft == p)
			{
				pieceweight[pos.x][pos.y][3] += PIECEDEFENSEWEIGHT[pleft][pieceleft];
				pieceweight[left][pos.y][5] += 1;
			}
			else
			{
				pieceweight[pos.x][pos.y][2] += PIECEATTACKWEIGHT[pleft][pieceleft];
				pieceweight[left][pos.y][4] += 1;
			}
			break;
		}
	}

	int right = pos.x + 1;
	while (right < COL)
	{
		if (m_board[right][pos.y] == NONE)
		{
			pieceweight[pos.x][pos.y][1] += PIECEWALKWEIGHT[p][piece];
			right++;
			continue;
		}
		else
		{
			unsigned char pright = m_board[right][pos.y] >> 0x7;
			unsigned char pieceright = m_board[right][pos.y] & 0x0F;
			if (pright == p)
			{
				pieceweight[pos.x][pos.y][3] += PIECEDEFENSEWEIGHT[pright][pieceright];
				pieceweight[right][pos.y][5] += 1;
			}
			else
			{
				pieceweight[pos.x][pos.y][2] += PIECEATTACKWEIGHT[pright][pieceright];
				pieceweight[right][pos.y][4] += 1;
			}
			break;
		}
	}

	int up = pos.y - 1;
	while (up >= 0)
	{
		if (m_board[pos.x][up] == NONE)
		{
			pieceweight[pos.x][pos.y][1] += PIECEWALKWEIGHT[p][piece];
			up--;
			continue;
		}
		else
		{
			unsigned char pup = m_board[pos.x][up] >> 0x7;
			unsigned char pieceup= m_board[pos.x][up] & 0x0F;
			if (pup == p)
			{
				pieceweight[pos.x][pos.y][3] += PIECEDEFENSEWEIGHT[pup][pieceup];
				pieceweight[pos.x][up][5] += 1;
			}
			else
			{
				pieceweight[pos.x][pos.y][2] += PIECEATTACKWEIGHT[pup][pieceup];
				pieceweight[pos.x][up][4] += 1;
			}
			break;
		}
	}

	int down = pos.y + 1;
	while (down < ROW)
	{
		if (m_board[pos.x][down] == NONE)
		{
			pieceweight[pos.x][pos.y][1] += PIECEWALKWEIGHT[p][piece];
			down++;
			continue;
		}
		else
		{
			unsigned char pdown = m_board[pos.x][down] >> 0x7;
			unsigned char piecedown = m_board[pos.x][down] & 0x0F;
			if (pdown == p)
			{
				pieceweight[pos.x][pos.y][3] += PIECEDEFENSEWEIGHT[pdown][piecedown];
				pieceweight[pos.x][down][5] += 1;
			}
			else
			{
				pieceweight[pos.x][pos.y][2] += PIECEATTACKWEIGHT[pdown][piecedown];
				pieceweight[pos.x][down][4] += 1;
			}
			break;
		}
	}
	return;
}

void ChineseChessAIMinMax::_Evaluation_MA(position pos, int pieceweight[ROW][COL][6])
{
	unsigned char p = m_board[pos.x][pos.y] >> 0x7;
	unsigned char piece = m_board[pos.x][pos.y] & 0x0F;
	pieceweight[pos.x][pos.y][0] = PIECEVALUEWEIGHT[p][piece];
	vector<position> v;
	if (pos.x - 2 >= 0)
	{
		if (pos.y + 1 < COL)
		{
			v.push_back({pos.x - 2,pos.y + 1});
		}
		if (pos.y - 1 >= 0)
		{
			v.push_back({ pos.x - 2,pos.y - 1 });
		}
	}
	if (pos.x + 2 < ROW)
	{
		if (pos.y + 1 < COL)
		{
			v.push_back({ pos.x + 2,pos.y + 1 });
		}
		if (pos.y - 1 >= 0)
		{
			v.push_back({ pos.x + 2,pos.y - 1 });
		}
	}

	if (pos.y - 2 >= 0)
	{
		if (pos.x + 1 < ROW)
		{
			v.push_back({ pos.x + 1,pos.y - 2 });
		}
		if (pos.x - 1 >= 0)
		{
			v.push_back({ pos.x - 1,pos.y - 2 });
		}
	}

	if (pos.y + 2 < COL)
	{
		if (pos.x + 1 < ROW)
		{
			v.push_back({ pos.x + 1,pos.y + 2 });
		}
		if (pos.x - 1 >= 0)
		{
			v.push_back({ pos.x - 1,pos.y + 2 });
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (m_cc->IsLegal(pos,v[i]))
		{
			unsigned char pi = m_board[v[i].x][v[i].y] >> 0x7;
			unsigned char piecei = m_board[v[i].x][v[i].y] & 0x0F;

			if (m_board[v[i].x][v[i].y] == NONE)
			{
				pieceweight[pos.x][pos.y][1] += PIECEWALKWEIGHT[p][piece];
			}
			else if (pi == p)
			{
				pieceweight[pos.x][pos.y][3] += PIECEDEFENSEWEIGHT[pi][piecei];
				pieceweight[v[i].x][v[i].y][5] += 1;
			}
			else
			{
				pieceweight[pos.x][pos.y][2] += PIECEATTACKWEIGHT[pi][piecei];
				pieceweight[v[i].x][v[i].y][4] += 1;
			}
		}
	}

	return;
}

void ChineseChessAIMinMax::_Evaluation_PAO(position pos, int pieceweight[ROW][COL][6])
{
	unsigned char p = m_board[pos.x][pos.y] >> 0x7;
	unsigned char piece = m_board[pos.x][pos.y] & 0x0F;

	pieceweight[pos.x][pos.y][0] = PIECEVALUEWEIGHT[p][piece];
	int left = pos.x - 1;
	while (left >= 0)
	{
		if (m_board[left][pos.y] == NONE)
		{
			pieceweight[pos.x][pos.y][1] += PIECEWALKWEIGHT[p][piece];
			left--;
			continue;
		}
		else
		{
			left--;
			while (left >= 0)
			{
				if (m_board[left][pos.y] != NONE)
				{
					unsigned char pleft = m_board[left][pos.y] >> 0x7;
					unsigned char pieceleft = m_board[left][pos.y] & 0x0F;
					if (pleft == p)
					{
						defense += PIECEDEFENSEWEIGHT[pleft][pieceleft];
					}
					else
					{
						attack += PIECEATTACKWEIGHT[pleft][pieceleft];
					}
					break;
				}
				else
				{
					left--;
				}
			}
			break;
		}
	}

	int right = pos.x + 1;
	while (right < COL)
	{
		if (m_board[right][pos.y] == NONE)
		{
			pieceweight[pos.x][pos.y][1] += PIECEWALKWEIGHT[p][piece];
			right++;
			continue;
		}
		else
		{
			right++;
			while (right < COL)
			{
				if (m_board[right][pos.y] != NONE)
				{
					unsigned char pright = m_board[right][pos.y] >> 0x7;
					unsigned char pieceright = m_board[right][pos.y] & 0x0F;
					if (pright == p)
					{
						defense += PIECEDEFENSEWEIGHT[pright][pieceright];
					}
					else
					{
						attack += PIECEATTACKWEIGHT[pright][pieceright];
					}
					break;
				}
				else
				{
					right++;
				}
			}
			break;
		}
	}

	int up = pos.y - 1;
	while (up >= 0)
	{
		if (m_board[pos.x][up] == NONE)
		{
			pieceweight[pos.x][pos.y][1] += PIECEWALKWEIGHT[p][piece];
			up--;
			continue;
		}
		else
		{
			up--;
			while (up >= 0)
			{
				if (m_board[pos.x][up] != NONE)
				{
					unsigned char pup = m_board[pos.x][up] >> 0x7;
					unsigned char pieceup = m_board[pos.x][up] & 0x0F;
					if (pup == p)
					{
						defense += PIECEDEFENSEWEIGHT[pup][pieceup];
					}
					else
					{
						attack += PIECEATTACKWEIGHT[pup][pieceup];
					}
					break;
				}
				else
				{
					up--;
				}
			}
			break;
		}
	}

	int down = pos.y + 1;
	while (down < ROW)
	{
		if (m_board[pos.x][down] == NONE)
		{
			pieceweight[pos.x][pos.y][1] += PIECEWALKWEIGHT[p][piece];
			down++;
			continue;
		}
		else
		{
			down++;
			while (down < ROW)
			{
				if (m_board[pos.x][down] != NONE)
				{
					unsigned char pdown = m_board[pos.x][down] >> 0x7;
					unsigned char piecedown = m_board[pos.x][down] & 0x0F;
					if (pdown == p)
					{
						defense += PIECEDEFENSEWEIGHT[pdown][piecedown];
					}
					else
					{
						attack += PIECEATTACKWEIGHT[pdown][piecedown];
					}
					break;
				}
				else
				{
					down++;
				}
			}
			break;
		}
	}
	return;
}
void ChineseChessAIMinMax::_Evaluation_XIANG(position pos, int weight[4])
{
	unsigned char p = m_board[pos.x][pos.y] >> 0x7;
	unsigned char piece = m_board[pos.x][pos.y] & 0x0F;
	vector<position> v;
	if (pos.x - 2 >= 0)
	{
		if (pos.y + 2 < COL)
		{
			v.push_back({ pos.x - 2,pos.y + 2 });
		}
		if (pos.y - 2 >= 0)
		{
			v.push_back({ pos.x - 2,pos.y - 2 });
		}
	}
	if (pos.x + 2 < ROW)
	{
		if (pos.y + 2 < COL)
		{
			v.push_back({ pos.x + 2,pos.y + 2 });
		}
		if (pos.y - 2 >= 0)
		{
			v.push_back({ pos.x + 2,pos.y - 2 });
		}
	}

	if (pos.y - 2 >= 0)
	{
		if (pos.x + 2 < ROW)
		{
			v.push_back({ pos.x + 2,pos.y - 2 });
		}
		if (pos.x - 2 >= 0)
		{
			v.push_back({ pos.x - 2,pos.y - 2 });
		}
	}

	if (pos.y + 2 < COL)
	{
		if (pos.x + 2 < ROW)
		{
			v.push_back({ pos.x + 2,pos.y + 2 });
		}
		if (pos.x - 2 >= 0)
		{
			v.push_back({ pos.x - 2,pos.y + 2 });
		}
	}

	int  walk = 0;
	int  attack = 0;
	int defense = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (m_cc->IsLegal(pos, v[i]))
		{
			unsigned char pi = m_board[v[i].x][v[i].y] >> 0x7;
			unsigned char piecei = m_board[v[i].x][v[i].y] & 0x0F;

			if (m_board[v[i].x][v[i].y] == NONE)
			{
				pieceweight[pos.x][pos.y][1] += PIECEWALKWEIGHT[p][piece];
			}
			else if (pi == p)
			{
				defense += PIECEDEFENSEWEIGHT[pi][piecei];
			}
			else
			{
				attack += PIECEATTACKWEIGHT[pi][piecei];
			}
		}
	}

	weight[0] = PIECEVALUEWEIGHT[p][piece];
	weight[1] = walk;
	weight[2] = attack;
	weight[3] = defense;
	return;
}

void ChineseChessAIMinMax::_Evaluation_SHI(position pos, int weight[4])
{
	unsigned char p = m_board[pos.x][pos.y] >> 0x7;
	unsigned char piece = m_board[pos.x][pos.y] & 0x0F;
	vector<position> v;
	if (pos.x - 1 >= 0)
	{
		if (pos.y + 1 < COL)
		{
			v.push_back({ pos.x - 1,pos.y + 1 });
		}
		if (pos.y - 1 >= 0)
		{
			v.push_back({ pos.x - 1,pos.y - 1 });
		}
	}
	if (pos.x + 1 < ROW)
	{
		if (pos.y + 1 < COL)
		{
			v.push_back({ pos.x + 1,pos.y + 1 });
		}
		if (pos.y - 1 >= 0)
		{
			v.push_back({ pos.x + 1,pos.y - 1 });
		}
	}

	if (pos.y - 1 >= 0)
	{
		if (pos.x + 1 < ROW)
		{
			v.push_back({ pos.x + 1,pos.y - 1 });
		}
		if (pos.x - 1 >= 0)
		{
			v.push_back({ pos.x - 1,pos.y - 1 });
		}
	}

	if (pos.y + 1 < COL)
	{
		if (pos.x + 1 < ROW)
		{
			v.push_back({ pos.x + 1,pos.y + 1 });
		}
		if (pos.x - 1 >= 0)
		{
			v.push_back({ pos.x - 1,pos.y + 1 });
		}
	}

	int  walk = 0;
	int  attack = 0;
	int defense = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (m_cc->IsLegal(pos, v[i]))
		{
			unsigned char pi = m_board[v[i].x][v[i].y] >> 0x7;
			unsigned char piecei = m_board[v[i].x][v[i].y] & 0x0F;

			if (m_board[v[i].x][v[i].y] == NONE)
			{
				pieceweight[pos.x][pos.y][1] += PIECEWALKWEIGHT[p][piece];
			}
			else if (pi == p)
			{
				defense += PIECEDEFENSEWEIGHT[pi][piecei];
			}
			else
			{
				attack += PIECEATTACKWEIGHT[pi][piecei];
			}
		}
	}

	weight[0] = PIECEVALUEWEIGHT[p][piece];
	weight[1] = walk;
	weight[2] = attack;
	weight[3] = defense;
	return;
}
void ChineseChessAIMinMax::_Evaluation_JIANG(position pos, int weight[4])
{
	unsigned char p = m_board[pos.x][pos.y] >> 0x7;
	unsigned char piece = m_board[pos.x][pos.y] & 0x0F;
	vector<position> v;

	if (pos.x + 1 < ROW)
	{
		v.push_back({ pos.x + 1,pos.y });
	}
	if (pos.x - 1 >= 0)
	{
		v.push_back({ pos.x - 1,pos.y });
	}

	if (pos.y - 1 >= 0)
	{
		v.push_back({ pos.x,pos.y - 1 });
	}

	if (pos.y + 1 < COL)
	{
		v.push_back({ pos.x,pos.y + 1 });
	}

	int  walk = 0;
	int  attack = 0;
	int defense = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (m_cc->IsLegal(pos, v[i]))
		{
			unsigned char pi = m_board[v[i].x][v[i].y] >> 0x7;
			unsigned char piecei = m_board[v[i].x][v[i].y] & 0x0F;

			if (m_board[v[i].x][v[i].y] == NONE)
			{
				pieceweight[pos.x][pos.y][1] += PIECEWALKWEIGHT[p][piece];
			}
			else if (pi == p)
			{
				defense += PIECEDEFENSEWEIGHT[pi][piecei];
			}
			else
			{
				attack += PIECEATTACKWEIGHT[pi][piecei];
			}
		}
	}

	weight[0] = PIECEVALUEWEIGHT[p][piece];
	weight[1] = walk;
	weight[2] = attack;
	weight[3] = defense;
	return;
}
void ChineseChessAIMinMax::_Evaluation_ZU(position pos, int weight[4])
{
	unsigned char p = m_board[pos.x][pos.y] >> 0x7;
	unsigned char piece = m_board[pos.x][pos.y] & 0x0F;
	vector<position> v;

	if (pos.x + 1 < ROW)
	{
		v.push_back({ pos.x + 1,pos.y});
	}

	if (pos.y - 1 >= 0)
	{
		v.push_back({ pos.x,pos.y - 1 });
	}

	if (pos.y + 1 < COL)
	{
		v.push_back({ pos.x,pos.y + 1 });
	}

	int  walk = 0;
	int  attack = 0;
	int defense = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (m_cc->IsLegal(pos, v[i]))
		{
			unsigned char pi = m_board[v[i].x][v[i].y] >> 0x7;
			unsigned char piecei = m_board[v[i].x][v[i].y] & 0x0F;

			if (m_board[v[i].x][v[i].y] == NONE)
			{
				pieceweight[pos.x][pos.y][1] += PIECEWALKWEIGHT[p][piece];
			}
			else if (pi == p)
			{
				defense += PIECEDEFENSEWEIGHT[pi][piecei];
			}
			else
			{
				attack += PIECEATTACKWEIGHT[pi][piecei];
			}
		}
	}

	weight[0] = PIECEVALUEWEIGHT[p][piece];
	weight[1] = walk;
	weight[2] = attack;
	weight[3] = defense;
	return;
}
void ChineseChessAIMinMax::CanWalk(int p, vector<step>& vstep)
{
	for (unsigned char i = 0; i < ROW; i++)
	{
		for (unsigned char j = 0; j < COL; j++)
		{
			unsigned char ptemp = m_board[i][j] >> 0x7;
			unsigned char piecetemp = m_board[i][j] & 0x0F;
			if (p == ptemp)
			{
				if (piecetemp == JU)
				{
					_CanWalk_JU({i,j},vstep);
				}
				else if (piecetemp == MA)
				{
					_CanWalk_MA({ i,j }, vstep);
				}
				else if (piecetemp == PAO)
				{
					_CanWalk_PAO({ i,j }, vstep);
				}
				else if (piecetemp == XIANG)
				{
					_CanWalk_XIANG({ i,j }, vstep);
				}
				else if (piecetemp == SHI)
				{
					_CanWalk_SHI({ i,j }, vstep);
				}
				else if (piecetemp == JIANG)
				{
					_CanWalk_JIANG({ i,j }, vstep);
				}
				else if (piecetemp == ZU)
				{
					_CanWalk_ZU({ i,j }, vstep);
				}
			}
		}
	}
}
void ChineseChessAIMinMax::_CanWalk_JU(position pos, vector<step>& vstep)
{
	unsigned char p = m_board[pos.x][pos.y] >> 0x7;
	unsigned char piece = m_board[pos.x][pos.y] & 0x0F;

	int left = pos.x - 1;
	while (left >= 0)
	{
		if (m_board[left][pos.y] == NONE)
		{
			vstep.push_back({ pos,{left,pos.y} });
			left--;
			continue;
		}
		else
		{
			unsigned char pleft = m_board[left][pos.y] >> 0x7;
			unsigned char pieceleft = m_board[left][pos.y] & 0x0F;
			if (pleft == p)
			{
			}
			else
			{
				vstep.push_back({ pos,{left,pos.y} });
			}
			break;
		}
	}

	int right = pos.x + 1;
	while (right < COL)
	{
		if (m_board[right][pos.y] == NONE)
		{
			vstep.push_back({ pos,{right,pos.y} });
			right++;
			continue;
		}
		else
		{
			unsigned char pright = m_board[right][pos.y] >> 0x7;
			unsigned char pieceright = m_board[right][pos.y] & 0x0F;
			if (pright == p)
			{
			}
			else
			{
				vstep.push_back({ pos,{right,pos.y} });
			}
			break;
		}
	}

	int up = pos.y - 1;
	while (up >= 0)
	{
		if (m_board[pos.x][up] == NONE)
		{
			vstep.push_back({ pos,{pos.x,up} });
			up--;
			continue;
		}
		else
		{
			unsigned char pup = m_board[pos.x][up] >> 0x7;
			unsigned char pieceup = m_board[pos.x][up] & 0x0F;
			if (pup == p)
			{
			}
			else
			{
				vstep.push_back({ pos,{pos.x,up} });
			}
			break;
		}
	}

	int down = pos.y + 1;
	while (down < ROW)
	{
		if (m_board[pos.x][down] == NONE)
		{
			vstep.push_back({ pos,{pos.x,down} });
			down++;
			continue;
		}
		else
		{
			unsigned char pdown = m_board[pos.x][down] >> 0x7;
			unsigned char piecedown = m_board[pos.x][down] & 0x0F;
			if (pdown == p)
			{
			}
			else
			{
				vstep.push_back({ pos,{pos.x,down} });
			}
			break;
		}
	}
}
void ChineseChessAIMinMax::_CanWalk_MA(position pos, vector<step>& vstep)
{
	unsigned char p = m_board[pos.x][pos.y] >> 0x7;
	unsigned char piece = m_board[pos.x][pos.y] & 0x0F;
	vector<position> v;
	if (pos.x - 2 >= 0)
	{
		if (pos.y + 1 < COL)
		{
			v.push_back({ pos.x - 2,pos.y + 1 });
		}
		if (pos.y - 1 >= 0)
		{
			v.push_back({ pos.x - 2,pos.y - 1 });
		}
	}
	if (pos.x + 2 < ROW)
	{
		if (pos.y + 1 < COL)
		{
			v.push_back({ pos.x + 2,pos.y + 1 });
		}
		if (pos.y - 1 >= 0)
		{
			v.push_back({ pos.x + 2,pos.y - 1 });
		}
	}

	if (pos.y - 2 >= 0)
	{
		if (pos.x + 1 < ROW)
		{
			v.push_back({ pos.x + 1,pos.y - 2 });
		}
		if (pos.x - 1 >= 0)
		{
			v.push_back({ pos.x - 1,pos.y - 2 });
		}
	}

	if (pos.y + 2 < COL)
	{
		if (pos.x + 1 < ROW)
		{
			v.push_back({ pos.x + 1,pos.y + 2 });
		}
		if (pos.x - 1 >= 0)
		{
			v.push_back({ pos.x - 1,pos.y + 2 });
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (m_cc->IsLegal(pos, v[i]))
		{
			unsigned char pi = m_board[v[i].x][v[i].y] >> 0x7;
			unsigned char piecei = m_board[v[i].x][v[i].y] & 0x0F;

			if (m_board[v[i].x][v[i].y] == NONE)
			{
				if (m_cc->IsLegal(pos, v[i]))
				{
					vstep.push_back({pos,v[i]});
				}
			}
			else if (pi == p)
			{
			}
			else
			{
				if (m_cc->IsLegal(pos, v[i]))
				{
					vstep.push_back({ pos,v[i] });
				}
			}
		}
	}
	return;
}
void ChineseChessAIMinMax::_CanWalk_PAO(position pos, vector<step>& vstep)
{
	unsigned char p = m_board[pos.x][pos.y] >> 0x7;
	unsigned char piece = m_board[pos.x][pos.y] & 0x0F;

	int left = pos.x - 1;
	while (left >= 0)
	{
		if (m_board[left][pos.y] == NONE)
		{
			vstep.push_back({ pos,{left,pos.y} });
			left--;
			continue;
		}
		else
		{
			left--;
			while (left >= 0)
			{
				if (m_board[left][pos.y] != NONE)
				{
					unsigned char pleft = m_board[left][pos.y] >> 0x7;
					unsigned char pieceleft = m_board[left][pos.y] & 0x0F;
					if (pleft == p)
					{
					}
					else
					{
						vstep.push_back({ pos,{left,pos.y} });
					}
					break;
				}
				else
				{
					left--;
				}
			}
			break;
		}
	}

	int right = pos.x + 1;
	while (right < COL)
	{
		if (m_board[right][pos.y] == NONE)
		{
			vstep.push_back({ pos,{right,pos.y} });
			right++;
			continue;
		}
		else
		{
			right++;
			while (right < COL)
			{
				if (m_board[right][pos.y] != NONE)
				{
					unsigned char pright = m_board[right][pos.y] >> 0x7;
					unsigned char pieceright = m_board[right][pos.y] & 0x0F;
					if (pright == p)
					{
					}
					else
					{
						vstep.push_back({ pos,{right,pos.y} });
					}
					break;
				}
				else
				{
					right++;
				}
			}
			break;
		}
	}

	int up = pos.y - 1;
	while (up >= 0)
	{
		if (m_board[pos.x][up] == NONE)
		{
			vstep.push_back({ pos,{pos.x,up} });
			up--;
			continue;
		}
		else
		{
			up--;
			while (up >= 0)
			{
				if (m_board[pos.x][up] != NONE)
				{
					unsigned char pup = m_board[pos.x][up] >> 0x7;
					unsigned char pieceup = m_board[pos.x][up] & 0x0F;
					if (pup == p)
					{
					}
					else
					{
						vstep.push_back({ pos,{pos.x,up} });
					}
					break;
				}
				else
				{
					up--;
				}
			}
			break;
		}
	}

	int down = pos.y + 1;
	while (down < ROW)
	{
		if (m_board[pos.x][down] == NONE)
		{
			vstep.push_back({ pos,{pos.x,down} });
			down++;
			continue;
		}
		else
		{
			down++;
			while (down < ROW)
			{
				if (m_board[pos.x][down] != NONE)
				{
					unsigned char pdown = m_board[pos.x][down] >> 0x7;
					unsigned char piecedown = m_board[pos.x][down] & 0x0F;
					if (pdown == p)
					{
					}
					else
					{
						vstep.push_back({ pos,{pos.x,down} });
					}
					break;
				}
				else
				{
					down++;
				}
			}
			break;
		}
	}

	return;
}
void ChineseChessAIMinMax::_CanWalk_XIANG(position pos, vector<step>& vstep)
{
	unsigned char p = m_board[pos.x][pos.y] >> 0x7;
	unsigned char piece = m_board[pos.x][pos.y] & 0x0F;
	vector<position> v;
	if (pos.x - 2 >= 0)
	{
		if (pos.y + 2 < COL)
		{
			v.push_back({ pos.x - 2,pos.y + 2 });
		}
		if (pos.y - 2 >= 0)
		{
			v.push_back({ pos.x - 2,pos.y - 2 });
		}
	}
	if (pos.x + 2 < ROW)
	{
		if (pos.y + 2 < COL)
		{
			v.push_back({ pos.x + 2,pos.y + 2 });
		}
		if (pos.y - 2 >= 0)
		{
			v.push_back({ pos.x + 2,pos.y - 2 });
		}
	}

	if (pos.y - 2 >= 0)
	{
		if (pos.x + 2 < ROW)
		{
			v.push_back({ pos.x + 2,pos.y - 2 });
		}
		if (pos.x - 2 >= 0)
		{
			v.push_back({ pos.x - 2,pos.y - 2 });
		}
	}

	if (pos.y + 2 < COL)
	{
		if (pos.x + 2 < ROW)
		{
			v.push_back({ pos.x + 2,pos.y + 2 });
		}
		if (pos.x - 2 >= 0)
		{
			v.push_back({ pos.x - 2,pos.y + 2 });
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (m_cc->IsLegal(pos, v[i]))
		{
			unsigned char pi = m_board[v[i].x][v[i].y] >> 0x7;
			unsigned char piecei = m_board[v[i].x][v[i].y] & 0x0F;

			if (m_board[v[i].x][v[i].y] == NONE)
			{
				if (m_cc->IsLegal(pos, v[i]))
				{
					vstep.push_back({ pos,v[i] });
				}
			}
			else if (pi == p)
			{
			}
			else
			{
				if (m_cc->IsLegal(pos, v[i]))
				{
					vstep.push_back({ pos,v[i] });
				}
			}
		}
	}
	return;
}

void ChineseChessAIMinMax::_CanWalk_SHI(position pos, vector<step>& vstep)
{
	unsigned char p = m_board[pos.x][pos.y] >> 0x7;
	unsigned char piece = m_board[pos.x][pos.y] & 0x0F;
	vector<position> v;
	if (pos.x - 1 >= 0)
	{
		if (pos.y + 1 < COL)
		{
			v.push_back({ pos.x - 1,pos.y + 1 });
		}
		if (pos.y - 1 >= 0)
		{
			v.push_back({ pos.x - 1,pos.y - 1 });
		}
	}
	if (pos.x + 1 < ROW)
	{
		if (pos.y + 1 < COL)
		{
			v.push_back({ pos.x + 1,pos.y + 1 });
		}
		if (pos.y - 1 >= 0)
		{
			v.push_back({ pos.x + 1,pos.y - 1 });
		}
	}

	if (pos.y - 1 >= 0)
	{
		if (pos.x + 1 < ROW)
		{
			v.push_back({ pos.x + 1,pos.y - 1 });
		}
		if (pos.x - 1 >= 0)
		{
			v.push_back({ pos.x - 1,pos.y - 1 });
		}
	}

	if (pos.y + 1 < COL)
	{
		if (pos.x + 1 < ROW)
		{
			v.push_back({ pos.x + 1,pos.y + 1 });
		}
		if (pos.x - 1 >= 0)
		{
			v.push_back({ pos.x - 1,pos.y + 1 });
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (m_cc->IsLegal(pos, v[i]))
		{
			unsigned char pi = m_board[v[i].x][v[i].y] >> 0x7;
			unsigned char piecei = m_board[v[i].x][v[i].y] & 0x0F;

			if (m_board[v[i].x][v[i].y] == NONE)
			{
				if (m_cc->IsLegal(pos, v[i]))
				{
					vstep.push_back({ pos,v[i] });
				}
			}
			else if (pi == p)
			{
			}
			else
			{
				if (m_cc->IsLegal(pos, v[i]))
				{
					vstep.push_back({ pos,v[i] });
				}
			}
		}
	}
	return;
}
void ChineseChessAIMinMax::_CanWalk_JIANG(position pos, vector<step>& vstep)
{
	unsigned char p = m_board[pos.x][pos.y] >> 0x7;
	unsigned char piece = m_board[pos.x][pos.y] & 0x0F;
	vector<position> v;

	if (pos.x + 1 < ROW)
	{
		v.push_back({ pos.x + 1,pos.y });
	}
	if (pos.x - 1 >= 0)
	{
		v.push_back({ pos.x - 1,pos.y });
	}

	if (pos.y - 1 >= 0)
	{
		v.push_back({ pos.x,pos.y - 1 });
	}

	if (pos.y + 1 < COL)
	{
		v.push_back({ pos.x,pos.y + 1 });
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (m_cc->IsLegal(pos, v[i]))
		{
			unsigned char pi = m_board[v[i].x][v[i].y] >> 0x7;
			unsigned char piecei = m_board[v[i].x][v[i].y] & 0x0F;

			if (m_board[v[i].x][v[i].y] == NONE)
			{
				if (m_cc->IsLegal(pos, v[i]))
				{
					vstep.push_back({ pos,v[i] });
				}
			}
			else if (pi == p)
			{
			}
			else
			{
				if (m_cc->IsLegal(pos, v[i]))
				{
					vstep.push_back({ pos,v[i] });
				}
			}
		}
	}
	return;
}
void ChineseChessAIMinMax::_CanWalk_ZU(position pos, vector<step>& vstep)
{
	unsigned char p = m_board[pos.x][pos.y] >> 0x7;
	unsigned char piece = m_board[pos.x][pos.y] & 0x0F;
	vector<position> v;

	if (pos.x + 1 < ROW)
	{
		v.push_back({ pos.x + 1,pos.y });
	}

	if (pos.y - 1 >= 0)
	{
		v.push_back({ pos.x,pos.y - 1 });
	}

	if (pos.y + 1 < COL)
	{
		v.push_back({ pos.x,pos.y + 1 });
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (m_cc->IsLegal(pos, v[i]))
		{
			unsigned char pi = m_board[v[i].x][v[i].y] >> 0x7;
			unsigned char piecei = m_board[v[i].x][v[i].y] & 0x0F;

			if (m_board[v[i].x][v[i].y] == NONE)
			{
				if (m_cc->IsLegal(pos, v[i]))
				{
					vstep.push_back({ pos,v[i] });
				}
			}
			else if (pi == p)
			{
			}
			else
			{
				if (m_cc->IsLegal(pos, v[i]))
				{
					vstep.push_back({ pos,v[i] });
				}
			}
		}
	}
	return;
}
void ChineseChessAIMinMax::LayoutBoard(ChineseChess& cc, unsigned char p,int level)
{
	m_cc = &cc;
	if (p == 0)
	{
		for (unsigned char i = 0; i < ROW; i++)
		{
			for (unsigned char j = 0; j < COL; j++)
			{
				m_board[i][j] = cc.Get({ i,j });
			}
		}
	}
	else
	{
		//for (unsigned char i = 0; i < 10; i++)
		//{
		//	for (unsigned char j = 0; j < 9; j++)
		//	{
		//		m_board[i][j] = cc.Get({ 10 - 1 - i,j });
		//	}
		//}
	}
	m_level = level;
}
bool ChineseChessAIMinMax::MinMaxSearch(position& start, position& target)
{
	stack<step> sta;
	_Max(m_level, sta);
	start = sta.top().start;
	target = sta.top().target;

	//stack<step> sta;
	//AlphaBeta(m_level,0,INT_MIN,INT_MAX, sta);
	//start = sta.top().start;
	//target = sta.top().target;
	
	return true;
}

int ChineseChessAIMinMax::_Max(int depth,stack<step>& sta)
{
	if (depth <= 0)
	{
		return Evaluation();
	}
	int best = INT_MIN;
	step beststep({ 0,0 }, { 0,0 });

	vector<step> vstep;
	CanWalk(0, vstep);
	for (int i = 0; i < vstep.size(); i++)
	{
		stack<step> statemp;

		int s = m_board[vstep[i].start.x][vstep[i].start.y];
		int t = m_board[vstep[i].target.x][vstep[i].target.y];

		m_board[vstep[i].start.x][vstep[i].start.y] = NONE;
		m_board[vstep[i].target.x][vstep[i].target.y] = s;

		int val = _Min(depth - 1, statemp);

		m_board[vstep[i].start.x][vstep[i].start.y] = s;
		m_board[vstep[i].target.x][vstep[i].target.y] = t;

		if (val > best)
		{
			best = val;
			beststep = vstep[i];
			sta = statemp;
		}
		else if (val == best && rand() % 2 == 0)
		{
			best = val;
			beststep = vstep[i];
			sta = statemp;
		}
		else
		{
		}
	}
	sta.push(beststep);
	return best;
}
int ChineseChessAIMinMax::_Min(int depth,stack<step>& sta)
{
	if (depth <= 0)
	{
		return Evaluation();
	}
	int best = INT_MAX;
	step beststep({ 0,0 }, {0,0});
	int stasize = sta.size();
	vector<step> vstep;
	CanWalk(1, vstep);
	for (int i = 0; i < vstep.size(); i++)
	{
		stack<step> statemp;

		int s = m_board[vstep[i].start.x][vstep[i].start.y];
		int t = m_board[vstep[i].target.x][vstep[i].target.y];

		m_board[vstep[i].start.x][vstep[i].start.y] = NONE;
		m_board[vstep[i].target.x][vstep[i].target.y] = s;

		int val = _Max(depth - 1, statemp);

		m_board[vstep[i].start.x][vstep[i].start.y] = s;
		m_board[vstep[i].target.x][vstep[i].target.y] = t;

		if (val < best)
		{
			best = val;
			beststep = vstep[i];
			sta = statemp;
		}
		else if (val == best && rand() % 2 == 0)
		{
			best = val;
			beststep = vstep[i];
			sta = statemp;
		}
		else
		{
		}
	}
	sta.push(beststep);
	return best;
}

int ChineseChessAIMinMax::AlphaBeta(int depth,int p , int alpha, int beta,  stack<step>& sta) {
	if (depth == 0) {
		return Evaluation();
	}

	int best = INT_MAX;
	step beststep({ 0,0 }, { 0,0 });
	int stasize = sta.size();
	vector<step> vstep;
	CanWalk(p, vstep);
	for (int i = 0; i < vstep.size(); i++)
	{
		int s = m_board[vstep[i].start.x][vstep[i].start.y];
		int t = m_board[vstep[i].target.x][vstep[i].target.y];

		m_board[vstep[i].start.x][vstep[i].start.y] = NONE;
		m_board[vstep[i].target.x][vstep[i].target.y] = s;

		int val = -AlphaBeta(depth - 1,(p + 1) % 2, -beta, -alpha,sta);

		m_board[vstep[i].start.x][vstep[i].start.y] = s;
		m_board[vstep[i].target.x][vstep[i].target.y] = t;

		if (val >= beta) {
			return beta;
		}
		if (val > alpha)
		{
			alpha = val;
			beststep = vstep[i];
		}
		else if (val == alpha && rand() % 2 == 0)
		{
			alpha = val;
			beststep = vstep[i];
		}
		else
		{
			while (sta.size() > stasize)
			{
				sta.pop();
			}
		}
	}
	sta.push(beststep);
	return alpha;
}