// Ex4_1.cpp : Defines the entry point for the application.
//


#include "stdlib.h"
#include "string.h"
#include "stdafx.h"
#include "windows.h"
long WINAPI WndProc(HWND,UINT,WPARAM,LPARAM);
int InitWindowsClass(HINSTANCE hInstance);
bool InitWindows(HINSTANCE hInstance,int nCmdShow);
HWND hWndMain;
int WINAPI WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpszCmdLine,
                     int       nCmdShow)
{

	MSG Message;
	if(!InitWindowsClass(hInstance))
		return FALSE;
	if(!InitWindows(hInstance,nCmdShow))
		return FALSE;

while(GetMessage(&Message,NULL,0,0))
{
	TranslateMessage(&Message);
	DispatchMessage(&Message);
}
return Message.wParam;
}


LRESULT CALLBACK WndProc(
						 HWND hWnd,
						 UINT iMessage,
						 WPARAM wParam,
						 LPARAM lParam
						 )
{	
	HDC hDC;
	HBRUSH hBrush;
	HPEN hPen;
	PAINTSTRUCT PtStr;

	
	switch(iMessage)
	{
	case WM_PAINT:
		hDC=BeginPaint(hWnd,&PtStr);
		SetMapMode(hDC,MM_ANISOTROPIC);
		hPen=(HPEN)GetStockObject(BLACK_PEN);

		hBrush=(HBRUSH)GetStockObject(DKGRAY_BRUSH);

		SelectObject(hDC,hBrush);
		SelectObject(hDC,hPen);
		RoundRect(hDC,50,120,100,200,15,15);
		hBrush=(HBRUSH)GetStockObject(LTGRAY_BRUSH);
		Ellipse(hDC,150,50,200,150);
		hBrush=(HBRUSH)GetStockObject(HOLLOW_BRUSH);
		SelectObject(hDC,hBrush);
		Pie(hDC,250,50,300,100,250,50,300,50);
		EndPaint(hWnd,&PtStr);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd,iMessage,wParam,lParam);
	}
	return 0;
}
bool InitWindows(HINSTANCE hInstance,int nCmdShow)
{	
	HWND hWnd;
	hWnd=CreateWindow(
					"WinFill",
					"Ìî³äÊ¾Àý³ÌÐò",
					WS_OVERLAPPEDWINDOW,
					CW_USEDEFAULT,
					0,
					CW_USEDEFAULT,
					0,
					NULL,
					NULL,
					hInstance,
					NULL
				  );
	if(!hWnd)
		return FALSE;
	hWndMain=hWnd;
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}

int InitWindowsClass(HINSTANCE hInstance)
{
	WNDCLASS wndclass;
	wndclass.style=CS_HREDRAW|CS_VREDRAW;
	wndclass.lpfnWndProc=WndProc;
	wndclass.cbClsExtra=0;
	wndclass.cbWndExtra=0;
	wndclass.hInstance=hInstance;
	wndclass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);
	wndclass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName=NULL;
	wndclass.lpszClassName="WinFill";
	return RegisterClass(&wndclass);

}


