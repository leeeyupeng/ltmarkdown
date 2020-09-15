#include <windows.h>

#include "CViewInfo.h"

#define CLIENT_WND_BGROUND

#define IDM_FIRSTCHILD 1001
#define IDM_FILE_NEW   1002

HINSTANCE g_hInst;
TCHAR     szMDIMainFrame[] = TEXT("MDI Main Frame");
TCHAR     gszAppName[] = TEXT("MDI Demo");
HWND      ghWndMDIClient;
HWND      ghWndMainFrame;
HMENU     ghMainFrameMenu;

void CreateChildWndMenu(void);
HWND CreateDocView(HWND hParentWnd, HINSTANCE hInstance);
static LRESULT CALLBACK MainFrameProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

#ifdef CLIENT_WND_BGROUND
static WNDPROC pfOrigClientWndProc;
LRESULT CALLBACK ClientWndSubClassProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_ERASEBKGND:
	{
		RECT rect;
		HDC hDC = (HDC)wParam;
		GetClientRect(hwnd, &rect);
		HBRUSH hbr = CreateSolidBrush(RGB(125, 150, 125));
		HBRUSH holdbr = (HBRUSH)SelectObject(hDC, hbr);
		FillRect(hDC, &rect, hbr);
		SelectObject(hDC, holdbr);
		DeleteObject(hbr);
	}
	return TRUE;
	default:
		break;
	}

	return CallWindowProc(pfOrigClientWndProc, hwnd, uMsg, wParam, lParam);
}
#endif

HMENU CreateMainFrameMenu(void)
{
	//主框架菜单
	HMENU hMenu = CreateMenu();

	//文件菜单
	HMENU hFileMenu = CreateMenu();
	AppendMenu(hFileMenu, MF_STRING, IDM_FILE_NEW, TEXT("&New"));
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, TEXT("&File"));

	return hMenu;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	MSG msg;
	WNDCLASSEX wndclass = { 0 };

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = MainFrameProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = NULL;
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszClassName = szMDIMainFrame;
	if (!RegisterClassEx(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"), gszAppName, MB_ICONERROR);
		return 0;
	}
	g_hInst = hInstance;

	ghMainFrameMenu = CreateMainFrameMenu();
	CreateChildWndMenu();

	//Create the main MDI frame window
	ghWndMainFrame = CreateWindow(szMDIMainFrame,
		gszAppName,
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
		CW_USEDEFAULT,    // allows system choose an x position
		CW_USEDEFAULT,    // allows system choose a y position
		400,
		300,
		NULL,        // handle to parent window
		ghMainFrameMenu,// handle to menu
		hInstance,    // handle to the instance of module
		NULL);        // Long pointer to a value to be passed to the window through the 
	ShowWindow(ghWndMainFrame, SW_SHOW);
	UpdateWindow(ghWndMainFrame);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK MainFrameProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		CLIENTCREATESTRUCT ccs;
		ccs.hWindowMenu = NULL;
		ccs.idFirstChild = IDM_FIRSTCHILD;
		ghWndMDIClient = CreateWindow(TEXT("MDICLIENT"), NULL,
			WS_CHILD | WS_CLIPCHILDREN | WS_VISIBLE,
			0, 0, 0, 0, hWnd, NULL,
			g_hInst, (void *)&ccs);
#ifdef CLIENT_WND_BGROUND
		pfOrigClientWndProc = (WNDPROC)SetWindowLong(ghWndMDIClient, GWL_WNDPROC, (LONG)ClientWndSubClassProc);
#endif
	}
	return 0;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDM_FILE_NEW:
			CreateDocView(ghWndMDIClient, g_hInst);
			return 0;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefFrameProc(hWnd, ghWndMDIClient, message, wParam, lParam);
}