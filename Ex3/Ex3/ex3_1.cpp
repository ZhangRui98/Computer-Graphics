// Ex3_1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
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
	char lpszClassName[]="´°¿Ú";
	char lpszTitle[]="My_Windows";
	
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
	switch(message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
	default:
		return DefWindowProc(hwnd,message,wParam,lParam);
	}
	return 0;
}


