//================================================
// Cross and Null
//================================================

#define STRICT
#include <windows.h>
#include "crossnull.h"
#include "resource.h"
#include "CrossNullField.h"

CCrossNullField field;
extern HINSTANCE hInst;

//----------------------------------
// Window procedure
//----------------------------------
LRESULT CALLBACK
WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{
	PAINTSTRUCT ps;
	static DLGPROC lpfnDlgProc;
	
	switch (msg) 
	{
		case WM_CREATE:
        {    field.setHdc(GetDC(hwnd));
             HICON hIcon,hIconSm;
             hIcon =(HICON) LoadImage(NULL, "Smile_2.ico", IMAGE_ICON, 32, 32,LR_LOADFROMFILE);
             if(hIcon)
             SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
             else
             MessageBox(hwnd, "Could not load large icon!", "Error", MB_OK | MB_ICONERROR);
             hIconSm =(HICON) LoadImage(NULL, "Smile.ico", IMAGE_ICON, 16, 16,LR_LOADFROMFILE);
             if(hIconSm)
              SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIconSm);
             else
              MessageBox(hwnd, "Could not load small icon!", "Error", MB_OK | MB_ICONERROR);
        }
        case WM_PAINT:
			BeginPaint(hwnd, &ps);
			field.repaint();
			EndPaint(hwnd, &ps);
			return 0;

		case WM_COMMAND: 
			if(wParam == IDB_BUTTON1) 
			{
				field.clearField();
			}
			if(wParam == IDB_BUTTON2) 
			{
				lpfnDlgProc = (DLGPROC)MakeProcInstance((FARPROC)DlgProc, hInst);
				DialogBox(hInst, MAKEINTRESOURCE(DLG_ABOUT), hwnd, lpfnDlgProc);
			}
			if(wParam == IDB_BUTTON3) 
			{
				PostQuitMessage(0);
			}
			return 0;
        case WM_LBUTTONDOWN:
			field.selectNumber(getCursorPosition(hwnd));
			return 0;
		case WM_RBUTTONDOWN:
			field.setNull(getCursorPosition(hwnd));
			return 0;
    
		case WM_DESTROY:
			field.releaseHdc(hwnd);
			PostQuitMessage(0);
			return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

BOOL CALLBACK
DlgProc(HWND hdlg, UINT msg, WPARAM wParam, LPARAM lParam) 
{
	switch(msg) 
	{
		case WM_INITDIALOG: 
			return TRUE;
   
		case WM_COMMAND: 
			switch(wParam)
			{
				case IDOK:
				case IDCANCEL: 
					EndDialog(hdlg, 0);
					return TRUE;
			}
	}
	return FALSE;
}

//calculate the cursor's position
POINT getCursorPosition(HWND hwnd) 
{
	RECT rc;
	POINT ptS, ptW;
	GetWindowRect(hwnd, &rc);
	GetCursorPos(&ptS);
	ptW.x = ptS.x - rc.left;
	ptW.y = ptS.y - rc.top - 20;
	return ptW;
}
