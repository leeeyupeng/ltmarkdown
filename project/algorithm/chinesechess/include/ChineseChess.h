#pragma once
#include <iostream>
#include <sstream>
#ifdef WIN32
	#include <windows.h>
#else
#endif
#include <string>
using namespace std;
#define ROW 10
#define COL 9
enum PIECE {
	NONE = 0,JU = 1,MA = 2,PAO = 3,XIANG=4,SHI=5,JIANG=6,ZU=7,MAX=8
};
string PIECENAME[2][9] = {
	{"　","车","马","炮","象","士","将","卒"},
	{"　","车","马","炮","象","士","帅","卒"},
};
unsigned char INITIALLAYOUT[ROW][COL] = {
	{JU,	MA,		XIANG,	SHI,	JIANG,	SHI,	XIANG,	MA,		JU},
	{NONE,	NONE,	NONE,	NONE,	NONE,	NONE,	NONE,	NONE,	NONE},
	{NONE,	PAO,	NONE,	NONE,	NONE,	NONE,	NONE,	PAO,	NONE},
	{ZU,	NONE,	ZU,		NONE,	ZU,		NONE,	ZU,		NONE,	ZU},
	{NONE,	NONE,	NONE,	NONE,	NONE,	NONE,	NONE,	NONE,	NONE},

	{NONE,	NONE,	NONE,	NONE,	NONE,	NONE,	NONE,	NONE,	NONE},
	{ZU|0x80,	NONE,	ZU | 0x80,		NONE,	ZU | 0x80,		NONE,	ZU | 0x80,		NONE,	ZU | 0x80},
	{NONE,	PAO | 0x80,	NONE,	NONE,	NONE,	NONE,	NONE,	PAO | 0x80,	NONE},
	{NONE,	NONE,	NONE,	NONE,	NONE,	NONE,	NONE,	NONE,	NONE},
	{JU | 0x80,	MA | 0x80,		XIANG | 0x80,	SHI | 0x80,	JIANG | 0x80,	SHI | 0x80,	XIANG | 0x80,	MA | 0x80,		JU | 0x80},
};

struct position
{
	unsigned char x;
	unsigned char y;
	//position(unsigned char xx, unsigned char yy):x(xx),y(yy)
	//{
	//}
	position(int xx, int yy) :x((unsigned char)xx), y((unsigned char)yy)
	{
	}

	string toString()
	{
		stringstream s;
		s << "(" << (int)x << "," << (int)y << ")";
		return s.str();
	}
};
class ChineseChess
{
private:
	unsigned char m_board[ROW][COL];
	position m_jiang[2] = { {0,0},{0,0} };
public:
	unsigned char Get(position pos) { return m_board[pos.x][pos.y]; }
	bool Step(position start, position target);
	void BoardLayOut(unsigned char layout[ROW][COL]);
	void BoardPrint();
	void StepPrint(position start, position target);
	bool IsLegal(position start, position target);
private:
	bool _IsLegalMove(position start, position target);
	bool _IsLegalMove_JU(position start, position target);
	bool _IsLegalMove_MA(position start, position target);
	bool _IsLegalMove_PAO(position start, position target);
	bool _IsLegalMove_XIANG(position start, position target);
	bool _IsLegalMove_SHI(position start, position target);
	bool _IsLegalMove_JIANG(position start, position target);
	bool _IsLegalMove_ZU(position start, position target);
};
bool ChineseChess::IsLegal(position start, position target)
{
	unsigned char p = m_board[start.x][start.y] >> 0x7;
	unsigned char piece = m_board[start.x][start.y] & 0x0F;


	bool bMove = _IsLegalMove(start,target);
	
	if (bMove == false)
	{
		return false;
	}
	//移动导致将照面
	if (m_jiang[0].y == m_jiang[1].y && start.y == m_jiang[0].y && start.y != target.y)
	{
		unsigned char y = m_jiang[0].y;
		unsigned char k = m_jiang[0].x < m_jiang[1].x ? 1 : -1;
		unsigned char i = m_jiang[0].x + k;
		bool bShow = true;
		while (i != m_jiang[1].x)
		{
			if (m_board[i][y] != NONE && i != start.x)
			{
				bShow = false;
			}
			i += k;
		}

		if (bShow)
		{
			return false;
		}
	}
	//移动导致对手将军

	return true;
}

bool ChineseChess::_IsLegalMove(position start, position target)
{
	unsigned char p = m_board[start.x][start.y] >> 0x7;
	unsigned char piece = m_board[start.x][start.y] & 0x0F;
	bool bMove = false;
	if (piece == JU)
	{
		bMove = _IsLegalMove_JU(start,target);
	}
	else if (piece == MA)
	{
		bMove = _IsLegalMove_MA(start, target);
	}
	else if (piece == PAO)
	{
		bMove = _IsLegalMove_PAO(start, target);
	}
	else if (piece == XIANG)
	{
		bMove = _IsLegalMove_XIANG(start, target);
	}
	else if (piece == SHI)
	{
		bMove = _IsLegalMove_SHI(start, target);
	}
	else if (piece == JIANG)
	{
		bMove = _IsLegalMove_JIANG(start, target);
	}
	else if (piece == ZU)
	{
		bMove = _IsLegalMove_ZU(start, target);
	}

	return bMove;
}
bool ChineseChess::_IsLegalMove_JU(position start, position target)
{
	unsigned char p = m_board[start.x][start.y] >> 0x7;
	unsigned char piece = m_board[start.x][start.y] & 0x0F;

	if (start.x == target.x)
	{
		unsigned char k = target.y > start.y ? 1 : -1;
		unsigned char i = start.y + k;
		while (i != target.y)
		{
			if (m_board[start.x][i] != NONE)
			{
				return false;
			}
			i += k;
		}
		return true;
	}
	else if (start.y == target.y)
	{
		unsigned char k = target.x > start.x ? 1 : -1;
		unsigned char i = start.x + k;
		while (i != target.x)
		{
			if (m_board[i][start.y] != NONE)
			{
				return false;
			}
			i += k;
		}
		return true;
	}
	return false;
}
bool ChineseChess::_IsLegalMove_MA(position start, position target)
{
	unsigned char p = m_board[start.x][start.y] >> 0x7;
	unsigned char piece = m_board[start.x][start.y] & 0x0F;
	if (abs((target.x - start.x) * (target.y - start.y)) == 2)
	{
		position leg((target.x + start.x) / 2, (target.y + start.y) / 2);
		if (m_board[leg.x][leg.y] == NONE)
		{
			return true;
		}
	}
	return false;
}

bool ChineseChess::_IsLegalMove_PAO(position start, position target)
{
	unsigned char p = m_board[start.x][start.y] >> 0x7;
	unsigned char piece = m_board[start.x][start.y] & 0x0F;
	if (m_board[target.x][target.y] == NONE)
	{
		return _IsLegalMove_JU(start,target);
	}
	else
	{
		int separate = 0;
		if (start.x == target.x)
		{
			unsigned char k = target.y > start.y ? 1 : -1;
			unsigned char i = start.y + k;

			while (i != target.y)
			{
				separate += m_board[start.x][i] != NONE ? 1 : 0;
				i += k;
			}

		}
		else if (start.y == target.y)
		{
			unsigned char k = target.x > start.x ? 1 : -1;
			unsigned char i = start.x + k;
			while (i != target.x)
			{
				separate += m_board[i][start.y] != NONE ? 1 : 0;
				i += k;
			}
		}

		if (separate == 1)
		{
			return true;
		}
		return false;
	}
}
bool ChineseChess::_IsLegalMove_XIANG(position start, position target)
{
	unsigned char p = m_board[start.x][start.y] >> 0x7;
	unsigned char piece = m_board[start.x][start.y] & 0x0F;
	if (p == 0?(target.x < 5):!(target.x < 5))
	{
		if (abs(target.x - start.x) == 2 && abs(target.y - start.y) == 2)
		{
			position eye((target.x + start.x) / 2, (target.y + start.y) / 2);
			if (m_board[eye.x][eye.y] == NONE)
			{
				return true;
			}
		}
	}
	return false;
}
bool ChineseChess::_IsLegalMove_SHI(position start, position target)
{
	unsigned char p = m_board[start.x][start.y] >> 0x7;
	unsigned char piece = m_board[start.x][start.y] & 0x0F;
	if (p == 0 ? (target.x < 3 && target.y >= 3 && target.y <= 5) : (target.x >= 7 && target.y >= 3 && target.y <= 5))
	{
		if (abs((target.x - start.x) * (target.y - start.y)) == 1)
		{
			if (p == 0)
			{
				if ((target.x == 1 && target.y == 4) || (target.x != 1 && (target.y != 4)))
				{
					return true;
				}
			}
			else if(p == 1)
			{
				if ((target.x == 8 && target.y == 4) || (target.x != 8 && (target.y != 4)))
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool ChineseChess::_IsLegalMove_JIANG(position start, position target)
{
	unsigned char p = m_board[start.x][start.y] >> 0x7;
	unsigned char piece = m_board[start.x][start.y] & 0x0F;
	if (p == 0 ? (target.x < 3 && target.y >= 3 && target.y <= 5) : (target.x >= 7 && target.y >= 3 && target.y <= 5))
	{
		if (((target.x - start.x) * (target.y - start.y) == 0) && abs((target.x - start.x) + (target.y - start.y)) == 1)
		{
			return true;
		}
	}
	return false;
}
bool ChineseChess::_IsLegalMove_ZU(position start, position target)
{
	unsigned char p = m_board[start.x][start.y] >> 0x7;
	unsigned char piece = m_board[start.x][start.y] & 0x0F;

	if (p == 0)
	{
		if (start.x <= 4)
		{
			if (target.x - start.x == 1 && start.y == target.y)
			{
				return true;
			}
		}
		else
		{
			if (((target.x - start.x) * (target.y - start.y) == 0) && abs((target.x - start.x) + (target.y - start.y)) == 1)
			{
				if (target.x >= start.x)
				{
					return true;
				}
			}
		}
	}
	else if (p == 1)
	{
		if (start.x >= 5)
		{
			if (target.x - start.x == -1 && start.y == target.y)
			{
				return true;
			}
		}
		else
		{
			if (((target.x - start.x) * (target.y - start.y) == 0) && abs((target.x - start.x) + (target.y - start.y)) == 1)
			{
				if (target.x <= start.x)
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool ChineseChess::Step(position start, position target)
{
	unsigned char p = m_board[start.x][start.y] >> 0x7;
	unsigned char piece = m_board[start.x][start.y] & 0x0F;
	if (m_board[start.x][start.y] != NONE)
	{
		if (IsLegal(start, target))
		{
			m_board[target.x][target.y] = m_board[start.x][start.y];
			m_board[start.x][start.y] = NONE;
			return true;
		}
		else
		{
			cout << "Error :IsLegal(start, target)" << endl;
		}
	}
	else
	{
		cout << "Error:(m_board[start.x][start.y] >> 0x7) == p" << endl;
	}
	return false;
}
void ChineseChess::BoardLayOut(unsigned char layout[ROW][COL])
{
	for (unsigned char i = 0; i < ROW; i++)
	{
		for (unsigned char j = 0; j < COL; j++)
		{
			m_board[i][j] = layout[i][j];
			if ((m_board[i][j] & 0x0F) == JIANG)
			{
				m_jiang[m_board[i][j] >> 0x7] = { i,j };
			}
		}
	}
}
void ChineseChess::BoardPrint()
{
	cout << endl;
	//移動光標
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hout, &bInfo);

	cout << "\n\
　　　　　　　　　中国象棋\n\
\n\
１０　｜－｜－｜－｜－｜－｜－｜－｜－｜\n\
　　　｜  ｜  ｜  ｜  ｜  ｜  ｜  ｜  ｜\n\
　９　｜－｜－｜－｜－｜－｜－｜－｜－｜\n\
　　　｜  ｜  ｜  ｜  ｜  ｜  ｜  ｜  ｜\n\
　８　｜－｜－｜－｜－｜－｜－｜－｜－｜\n\
　　　｜  ｜  ｜  ｜  ｜  ｜  ｜  ｜  ｜\n\
　７　｜－｜－｜－｜－｜－｜－｜－｜－｜\n\
　　　｜  ｜  ｜  ｜  ｜  ｜  ｜  ｜  ｜\n\
　６　｜－｜－｜－｜－｜－｜－｜－｜－｜\n\
　　　｜  　　　楚河　　　汉界　　　　｜\n\
　５　｜－｜－｜－｜－｜－｜－｜－｜－｜\n\
　　　｜  ｜  ｜  ｜  ｜  ｜  ｜  ｜  ｜\n\
　４　｜－｜－｜－｜－｜－｜－｜－｜－｜\n\
　　　｜  ｜  ｜  ｜  ｜  ｜  ｜  ｜  ｜\n\
　３　｜－｜－｜－｜－｜－｜－｜－｜－｜\n\
　　　｜  ｜  ｜  ｜  ｜  ｜  ｜  ｜  ｜\n\
　２　｜－｜－｜－｜－｜－｜－｜－｜－｜\n\
　　　｜  ｜  ｜  ｜  ｜  ｜  ｜  ｜  ｜\n\
　１　｜－｜－｜－｜－｜－｜－｜－｜－｜\n\
　　　ａ　ｂ　ｃ　ｄ　ｅ　ｆ　ｇ　ｈ　ｉ\n\
	\n";

	//光標
	COORD coord;
	coord.X = bInfo.dwCursorPosition.X;
	coord.Y = bInfo.dwCursorPosition.Y;

	CONSOLE_SCREEN_BUFFER_INFO bLastInfo;
	GetConsoleScreenBufferInfo(hout, &bLastInfo);
	SetConsoleCursorPosition(hout, coord);


	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (m_board[i][j] != NONE)
			{
				unsigned char t = m_board[i][j] & 0x80;
				if ((m_board[i][j] & 0x80) == 0x80)
				{
					SetConsoleTextAttribute(hout, 0x4);
				}
				else
				{
					SetConsoleTextAttribute(hout, 0xF);
				}
				coord.X = bInfo.dwCursorPosition.X + 6 + j * 4;
				coord.Y = bInfo.dwCursorPosition.Y + 3 + i * 2;
				SetConsoleCursorPosition(hout, coord);
				cout << PIECENAME[m_board[i][j] >> 0x7][m_board[i][j] & 0x0F];
			}
		}
	}

	coord.X = bLastInfo.dwCursorPosition.X;
	coord.Y = bLastInfo.dwCursorPosition.Y;
	SetConsoleCursorPosition(hout, coord);
	SetConsoleTextAttribute(hout, 0xF);
}

void ChineseChess::StepPrint(position start, position target)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	if ((m_board[start.x][start.y] & 0x80) == 0x80)
	{
		SetConsoleTextAttribute(hout, 0x4);
	}
	else
	{
		SetConsoleTextAttribute(hout, 0xF);
	}
	cout <<PIECENAME[m_board[start.x][start.y] >> 0x7][m_board[start.x][start.y] & 0x0F]<<":";
	SetConsoleTextAttribute(hout, 0xF);
	cout << start.toString() << "-" << target.toString() << endl;
}