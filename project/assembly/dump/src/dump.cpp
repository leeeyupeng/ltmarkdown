#include <Windows.h>
#include <iostream>
#include <DbgHelp.h>
#include <tchar.h>
using namespace std;

#pragma comment(lib, "dbghelp.lib")

LONG WINAPI TopLevelExceptionFilter(struct _EXCEPTION_POINTERS *pExceptionInfo)
{
	cout << "Enter TopLevelExceptionFilter Function" << endl;
	HANDLE hFile = CreateFile(_T("project.dmp"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);  //创建dmp文件
	MINIDUMP_EXCEPTION_INFORMATION stExceptionParam;
	stExceptionParam.ThreadId = GetCurrentThreadId();
	stExceptionParam.ExceptionPointers = pExceptionInfo;
	stExceptionParam.ClientPointers = FALSE;
	MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, MiniDumpWithFullMemory, &stExceptionParam, NULL, NULL);  //写dmp文件
	CloseHandle(hFile);
	getchar();
	return EXCEPTION_EXECUTE_HANDLER;
}

int main()
{
	cout << "Enter Main Function" << endl;
	SetUnhandledExceptionFilter(TopLevelExceptionFilter);   //设置异常捕获函数 TopLevelExceptionFilter
	int *pValue = NULL;
	//int a = 1;
	//pValue = &a;
	//*pValue = 2;
	//cout<<*pValue<<endl;
	cout << "Invalid Access" << endl;
	*pValue = 1;    //写 0地址，程序崩溃
	cout << "Finish Main Function" << endl;
	getchar();

	return 0;
}