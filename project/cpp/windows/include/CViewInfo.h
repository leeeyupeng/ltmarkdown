#include <windows.h>

#define IDM_EDIT_COPY 1003
#define IDM_EDIT_PASTE 1004

class CViewInfo
{
public:
	CViewInfo(HINSTANCE hInst);
	~CViewInfo();
	HWND CreateViewWindow(HWND hParentWnd);
private:
	HINSTANCE m_hInst;
	HWND m_hWndView;
};

static TCHAR szViewWndName[] = TEXT("View Window");
static CViewInfo *g_pSystemInfo;
static HMENU      ghChildWndMenu;
extern HMENU      ghMainFrameMenu;

CViewInfo::CViewInfo(HINSTANCE hInst)
{
	m_hWndView = NULL;
	m_hInst = hInst;
}

CViewInfo::~CViewInfo()
{
	m_hWndView = NULL;
}

LRESULT CALLBACK ViewWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_MDIACTIVATE:
	{
		HWND hWndClient = GetParent(hWnd);
		HWND hWndFrame = GetParent(hWndClient);

		HMENU hMenu = GetSubMenu(ghChildWndMenu, 0);
		if (lParam == (LPARAM)hWnd)
		{
			SendMessage(hWndClient, WM_MDISETMENU, (WPARAM)ghChildWndMenu, (LPARAM)hMenu);
			EnableMenuItem(ghChildWndMenu, IDM_EDIT_COPY, MF_GRAYED);
		}

		// Set the framewindow menu if losing focus
		if (lParam != (LPARAM)hWnd)
		{
			SendMessage(hWndClient, WM_MDISETMENU, (WPARAM)ghMainFrameMenu, (LPARAM)NULL);
		}

		// call DrawMenuBar after the menu items are set
		DrawMenuBar(hWndFrame);

		return 0;
	}

	case WM_CLOSE:
		delete g_pSystemInfo;
		break;

	case WM_DESTROY:
		return 0;
	}

	return DefMDIChildProc(hWnd, message, wParam, lParam); //Frame window calls DefFrameProc rather than DefWindowProc
}


HWND CViewInfo::CreateViewWindow(HWND hParentWnd)
{
	WNDCLASSEX wcDoc;
	wcDoc.cbSize = sizeof(WNDCLASSEX);
	wcDoc.style = CS_HREDRAW | CS_VREDRAW;
	wcDoc.lpfnWndProc = ViewWindowProc;
	wcDoc.cbClsExtra = 0;
	wcDoc.cbWndExtra = 0;
	wcDoc.hInstance = m_hInst;
	wcDoc.hIcon = NULL;
	wcDoc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcDoc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcDoc.lpszMenuName = NULL;
	wcDoc.lpszClassName = szViewWndName;
	wcDoc.hIconSm = NULL;

	if (!RegisterClassEx(&wcDoc))
	{
		DWORD dw_LastError = GetLastError();
		if (ERROR_CLASS_ALREADY_EXISTS != dw_LastError)
		{
			return 0;
		}
	}

	m_hWndView = CreateWindowEx(WS_EX_TOOLWINDOW, szViewWndName,
		TEXT("New view"), 0, CW_USEDEFAULT,
		CW_USEDEFAULT, 300, 200,
		hParentWnd, NULL, m_hInst, NULL);

	return m_hWndView;
}

HWND CreateDocView(HWND hParentWnd, HINSTANCE hInstance)
{
	HWND hView;

	g_pSystemInfo = new CViewInfo(hInstance);
	hView = g_pSystemInfo->CreateViewWindow(hParentWnd);
	if (hView == NULL)
	{
		delete g_pSystemInfo;
		g_pSystemInfo = NULL;
	}

	return hView;
}

void CreateChildWndMenu(void)
{
	//View²Ëµ¥
	ghChildWndMenu = CreateMenu();

	//±à¼­²Ëµ¥
	HMENU hEditMenu = CreateMenu();
	AppendMenu(hEditMenu, MF_STRING, IDM_EDIT_COPY, TEXT("&Copy"));
	AppendMenu(hEditMenu, MF_STRING, IDM_EDIT_PASTE, TEXT("&Paste"));
	AppendMenu(ghChildWndMenu, MF_POPUP, (UINT_PTR)hEditMenu, TEXT("&Edit"));
}