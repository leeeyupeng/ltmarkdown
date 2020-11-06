// chinesechess.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include "ChineseChess.h"
#include "ChineseChessAIMinMax.h"

using namespace std;
int main()
{
	cout << "中國象棋演示" << endl;
	//system("cls");
	ChineseChess cc;

	cc.BoardLayOut(INITIALLAYOUT);
	cc.BoardPrint();

	ChineseChessAIMinMax ai;

	int step[4];
	while (true)
	{
		while(true)
		{
			cout << "请走棋:";
			cin >> step[0] >> step[1] >> step[2] >> step[3];
			position start(step[0], step[1]);
			position target(step[2], step[3]);
			if (cc.IsLegal(start, target))
			{
				cc.StepPrint(start, target);
				cc.Step(start, target);
				cc.BoardPrint();
				break;
			}
			else
			{
				continue;
			}
		}

		cout << "电脑走棋:";
		system("PAUSE");
		while(true)
		{
			position aistart(0, 0);
			position aitarget(0, 0);
			ai.LayoutBoard(cc, 0,3);

			if (ai.MinMaxSearch(aistart, aitarget))
			{
				if (cc.IsLegal(aistart, aitarget))
				{
					cc.StepPrint(aistart, aitarget);
					cc.Step(aistart, aitarget);
					cc.BoardPrint();
					break;
				}
				else
				{
					cout << "电脑走棋失败" << endl;
					return 0;
					continue;
				}
			}
			else
			{
				cout << "电脑走棋失败" << endl;
				return 0;
				continue;
			}
		}
	}
	system("PAUSE");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
