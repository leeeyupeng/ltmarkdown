#pragma once


#include<time.h>
#include <windows.h>
//控制cpu占用率
void TaskManager1()
{
	int millisec = 100;
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	SYSTEMTIME systemp;
	while (true)
	{
		GetLocalTime(&systemp);
		if (systemp.wMilliseconds >= sys.wMilliseconds + millisec)
		{
			Sleep(millisec);
			GetLocalTime(&sys);
		}
	}
}

void TaskManager2()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	while (true)
	{
		for (int i = 0; i < 9600000; i++)
		{
		}
		Sleep(10);
	}
}
void TaskManager3()
{
	int busytime = 50;
	int idletime = 50;
	DWORD startTime = 0;
	while (true)
	{
		startTime = GetTickCount();
		while ((GetTickCount() - startTime) < busytime)
		{
		}
		Sleep(idletime);
	}
}
