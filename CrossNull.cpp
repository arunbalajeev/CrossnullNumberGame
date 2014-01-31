//================================================
// Cross and Null
//================================================

#define STRICT
#include <windows.h>
#include "crossnull.h"
#include "resource.h"
#include "CrossNullField.h"

char const szMainClassName[]    = "CrossAppClass";
char const szMainWindowTitle[]  = "Cross and Null";

HINSTANCE hInst;

// =====================================
// WinMain function
// =====================================
int PASCAL
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)  
{
	MSG  msg;
	HWND hwnd;
	hInst = hInstance;
	HBITMAP hBmp   = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP_BACK));
	HBRUSH hBrush  = CreatePatternBrush(hBmp);
    HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON));
    HICON hIconSm = (HICON)LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(IDI_MYICON), IMAGE_ICON, 16, 16, 0);
    CCrossNullField::setBmpC(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPC)));
	CCrossNullField::setBmpN(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPN)));
	CCrossNullField::setBmpE(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPE)));
    CCrossNullField::setBmpONE(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPONE)));
	CCrossNullField::setBmpTWO(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPTWO)));
	CCrossNullField::setBmpTHREE(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPTHREE)));
    CCrossNullField::setBmpFOUR(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPFOUR)));
	CCrossNullField::setBmpFIVE(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPFIVE)));
	CCrossNullField::setBmpSIX(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPSIX)));
    CCrossNullField::setBmpSEVEN(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPSEVEN)));
	CCrossNullField::setBmpEIGHT(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPEIGHT)));
	CCrossNullField::setBmpNINE(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPNINE)));
	CCrossNullField::setBmpZERO(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPZERO)));
	CCrossNullField::setBmpONEC(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPONEC)));
	CCrossNullField::setBmpTWOC(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPTWOC)));
	CCrossNullField::setBmpTHREEC(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPTHREEC)));
    CCrossNullField::setBmpFOURC(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPFOURC)));
	CCrossNullField::setBmpFIVEC(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPFIVEC)));
	CCrossNullField::setBmpSIXC(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPSIXC)));
    CCrossNullField::setBmpSEVENC(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPSEVENC)));
	CCrossNullField::setBmpEIGHTC(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPEIGHTC)));
	CCrossNullField::setBmpNINEC(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPNINEC)));
	CCrossNullField::setBmpZEROC(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAPZEROC)));

	if(!Register(hInstance, hBrush))
		return FALSE;

	hwnd = CreateWindow(
		szMainClassName,     // the window class name
		szMainWindowTitle,   // the window title
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		140, 80, 550, 500,
		0,                   // the parent window identifier
		0,                   // the menu identifier
		hInstance,           // the application identifier
		NULL);               
	
	if(!hwnd)
		return FALSE;

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
    CreateWindow("button", "Begin",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		110, 420,
		90, 30,
		hwnd,
		(HMENU) IDB_BUTTON1,
		hInstance, NULL);
	CreateWindow("button", "About",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		230, 420,
		90, 30,
		hwnd,
		(HMENU) IDB_BUTTON2,
		hInstance, NULL);
	CreateWindow("button", "Cancel",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		350, 420,
		90, 30,
		hwnd,
		(HMENU) IDB_BUTTON3,
		hInstance, NULL);

	while(GetMessage(&msg, 0, 0, 0)) 
	{
		DispatchMessage(&msg);
	}

	DeleteObject(hBmp);
	DeleteObject(hBrush);
	CCrossNullField::deleteBmpC(); 
	CCrossNullField::deleteBmpN();
	CCrossNullField::deleteBmpE();
	CCrossNullField::deleteBmpONE(); 
	CCrossNullField::deleteBmpTWO();
	CCrossNullField::deleteBmpTHREE();
	CCrossNullField::deleteBmpFOUR(); 
	CCrossNullField::deleteBmpFIVE();
	CCrossNullField::deleteBmpSIX();
	CCrossNullField::deleteBmpSEVEN(); 
	CCrossNullField::deleteBmpEIGHT();
	CCrossNullField::deleteBmpNINE();
	CCrossNullField::deleteBmpZERO();
	CCrossNullField::deleteBmpONEC(); 
	CCrossNullField::deleteBmpTWOC();
	CCrossNullField::deleteBmpTHREEC();
	CCrossNullField::deleteBmpFOURC(); 
	CCrossNullField::deleteBmpFIVEC();
	CCrossNullField::deleteBmpSIXC();
	CCrossNullField::deleteBmpSEVENC(); 
	CCrossNullField::deleteBmpEIGHTC();
	CCrossNullField::deleteBmpNINEC();
	CCrossNullField::deleteBmpZEROC();

	return msg.wParam;
}

BOOL Register(HINSTANCE hInstance, HBRUSH hBrush) 
{
	ATOM aWndClass;             
	WNDCLASS wc;                
	memset(&wc, 0, sizeof(wc));
	wc.style = 0;
	wc.lpfnWndProc   = (WNDPROC) WndProc;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	wc.hIcon         = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = hBrush;
	wc.lpszMenuName  = (LPSTR)NULL;
	wc.lpszClassName = (LPSTR)szMainClassName;
	aWndClass = RegisterClass(&wc);

	if(aWndClass == 0) 
		return FALSE;

	return TRUE;
}





