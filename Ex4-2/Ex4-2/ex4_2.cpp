// Ex4_2.cpp : Defines the entry point for the application.
//

#include "string.h"
#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "windows.h"
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
int WINAPI WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInst,
                     LPSTR     lpszCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	HWND hwnd;
	MSG Msg;
	WNDCLASS wndclass;
	char lpszClassName[]="Ó³ÏñÄ£Ê½";
	char lpszTitle[]="My_Mm_mode";
	
	wndclass.style=0;
	wndclass.lpfnWndProc=WndProc;
	wndclass.cbClsExtra=0;
	wndclass.cbWndExtra=0;
	wndclass.hInstance=hInstance;
	wndclass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);
	wndclass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName=NULL;
	wndclass.lpszClassName=lpszClassName;

if (!RegisterClass(&wndclass))
{
	MessageBeep(0);
	return FALSE;
}
hwnd=CreateWindow(
					lpszClassName,
					lpszTitle,
					WS_OVERLAPPEDWINDOW,
					CW_USEDEFAULT,
					CW_USEDEFAULT,
					CW_USEDEFAULT,
					CW_USEDEFAULT,
					NULL,
					NULL,
					hInstance,
					NULL
				  );
ShowWindow(hwnd,nCmdShow);
UpdateWindow(hwnd);
while(GetMessage(&Msg,NULL,0,0))
{
	TranslateMessage(&Msg);
	DispatchMessage(&Msg);
}
return Msg.wParam;
}


LRESULT CALLBACK WndProc(
						 HWND hwnd,
						 UINT message,
						 WPARAM wParam,
						 LPARAM lParam
						 )
{
	HDC hDC;
	PAINTSTRUCT ps;
	HBRUSH hB1,hB2;
	int nMode=1;

	switch(message)
	{
	case WM_CREATE:
		nMode=MM_TEXT;
	case WM_LBUTTONDOWN:
		nMode=MM_ISOTROPIC;
		InvalidateRect(hwnd,NULL,1);
		break;
	case WM_RBUTTONDOWN:
		nMode=MM_ANISOTROPIC;
		InvalidateRect(hwnd,NULL,1);
		break;
	case WM_PAINT:
		hDC=BeginPaint(hwnd,&ps);
		SetMapMode(hDC,nMode);
		SetWindowExtEx(hDC,150,150,NULL);
		SetViewportExtEx(hDC,150,100,NULL);
		SetViewportOrgEx(hDC,150,60,NULL);
		hB1=(HBRUSH)GetStockObject(WHITE_BRUSH);
		hB2=(HBRUSH)GetStockObject(BLACK_BRUSH);
		SelectObject(hDC,hB1);
		RoundRect(hDC,0,0,150,150,30,30);
		SelectObject(hDC,hB2);
		Ellipse(hDC,0,10,150,140);
		EndPaint(hwnd,&ps);
		break;
	case WM_DESTROY:
		DeleteObject(hB1);
		DeleteObject(hB2);
		PostQuitMessage(0);
	default:
		return DefWindowProc(hwnd,message,wParam,lParam);
	}
	return 0;
}



