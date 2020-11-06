//#include <windows.h>
//#include <iostream>
//using namespace std;
//
//#define MAX_LOADSTRING 100
//
//// 全局变量: 
//HINSTANCE hInst;                                // 当前实例
//WCHAR* szTitle = TEXT("window窗體");                  // 标题栏文本
//WCHAR* szWindowClass = TEXT("WindowClass");            // 主窗口类名
//
//ATOM                MyRegisterClass(HINSTANCE hInstance);
//BOOL                InitInstance(HINSTANCE, int);
//LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//
////下面这一句很重要，如果希望不出现控制台黑窗口，就保留它；如果希望保留控制台黑窗口，就注释掉它
////#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
//
//int main()
//{
//	/*
//	HWND hWnd = ::GetConsoleWindow();
//	if (hWnd) {
//		cout << hWnd << endl;
//		::ShowWindow(hWnd, SW_HIDE);
//		::MessageBox(NULL, TEXT("这是一个在控制台应用程序下创建窗口的演示"), TEXT("MessageBox"), MB_OK);
//	}
//	*/
//	HINSTANCE hInstance = ::GetModuleHandle(NULL);
//	cout << hInstance << endl;
//
//	MyRegisterClass(hInstance);
//
//	// 执行应用程序初始化: 
//	if (!InitInstance(hInstance, SW_SHOW))
//	{
//		return FALSE;
//	}
//
//	//HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32TEST));
//
//	   
//	MSG msg;
//
//	// 主消息循环:
//	while (GetMessage(&msg, nullptr, 0, 0))
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//
//	return (int)msg.wParam;
//}
//
//
////
////  函数: MyRegisterClass()
////
////  目的: 注册窗口类。
////
//ATOM MyRegisterClass(HINSTANCE hInstance)
//{
//	WNDCLASSEXW wcex;
//
//	wcex.cbSize = sizeof(WNDCLASSEX);
//
//	wcex.style = CS_HREDRAW | CS_VREDRAW;
//	wcex.lpfnWndProc = WndProc;
//	wcex.cbClsExtra = 0;
//	wcex.cbWndExtra = 0;
//	wcex.hInstance = hInstance;
//	wcex.hIcon = LoadIcon(hInstance, NULL);
//	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
//	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wcex.lpszMenuName = NULL;
//	wcex.lpszClassName = szWindowClass;
//	wcex.hIconSm = LoadIcon(wcex.hInstance, NULL);
//
//	return RegisterClassExW(&wcex);
//}
//
////
////   函数: InitInstance(HINSTANCE, int)
////
////   目的: 保存实例句柄并创建主窗口
////
////   注释: 
////
////        在此函数中，我们在全局变量中保存实例句柄并
////        创建和显示主程序窗口。
////
//BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
//{
//	hInst = hInstance; // 将实例句柄存储在全局变量中
//
//	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
//
//	if (!hWnd)
//	{
//		return FALSE;
//	}
//
//	ShowWindow(hWnd, SW_SHOW);
//	UpdateWindow(hWnd);
//
//	return TRUE;
//}
//
////
////  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
////
////  目的:    处理主窗口的消息。
////
////  WM_COMMAND  - 处理应用程序菜单
////  WM_PAINT    - 绘制主窗口
////  WM_DESTROY  - 发送退出消息并返回
////
////
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	switch (message)
//	{
//	case WM_PAINT:
//	{
//		PAINTSTRUCT ps;
//		HDC hdc = BeginPaint(hWnd, &ps);
//		// TODO: 在此处添加使用 hdc 的任何绘图代码...
//		EndPaint(hWnd, &ps);
//	}
//	break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return DefWindowProc(hWnd, message, wParam, lParam);
//	}
//	return 0;
//}