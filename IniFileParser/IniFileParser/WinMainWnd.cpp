//!
//! @file WinMainWnd.cpp
//! @breaf Win32メイン画面
//! @author 河合 純
//! @date 2016/01/11
//!

#include <windowsx.h>
#include "WinMainWnd.h"

//!
//! コンストラクタ
//!
WinMainWnd::WinMainWnd(void)
{
	this->mainWnd = NULL;
	this->instance = NULL;
}

//!
//! デストラクタ
//!
WinMainWnd::~WinMainWnd(void)
{
}

//!
//! ウィンドウ生成
//!
BOOL
WinMainWnd::CreateMainWindow(HINSTANCE instance, LPCTSTR classname, LPCTSTR title, int width, int height)
{
	WNDCLASSEX wcex = {0};

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.lpfnWndProc = WinMainWnd::WndProcManager;
	wcex.hInstance = instance;
	wcex.lpszClassName = classname;
	wcex.lpszMenuName = NULL;
	wcex.style = CS_VREDRAW | CS_HREDRAW;
	wcex.hCursor = LoadCursor(instance, IDC_ARROW);
	wcex.hIcon = LoadIcon(instance, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(instance, IDI_APPLICATION);
	wcex.hbrBackground = GetStockBrush(GRAY_BRUSH);

	if (!RegisterClassEx(&wcex)) {
		return FALSE;
	}

	this->mainWnd = CreateWindow(classname, title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, instance, this);
	if (this->mainWnd == NULL) {
		return FALSE;
	}
	this->instance = instance;

	return TRUE;
}

//!
//! ウィンドウハンドル取得
//! @return ハンドル
//!
HWND
WinMainWnd::GetMainWindow(void)
{
	return this->mainWnd;
}

//!
//! アプリケーションインスタンス取得
//! @return アプリケーションインスタンス
//!
HINSTANCE
WinMainWnd::GetAppInstance(void)
{
	return this->instance;
}

//!
//! メッセージループ
//! @param filtermin 処理するメッセージの下限
//! @param filtermax 処理するメッセージの上限
//! @return ループを抜けた時の戻り値
//!
WPARAM
WinMainWnd::MainMessageLoop(UINT filtermin, UINT filtermax)
{
	MSG msg;

	while (GetMessage(&msg, NULL, filtermin, filtermax) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

//!
//! 登録用メッセージプロシージャ
//! @param hwnd 対象のウィンドウ
//! @param msg メッセージID
//! @param wp パラメータ
//! @param lp パラメータ
//! @return 処理結果
//!
LRESULT CALLBACK
WinMainWnd::WndProcManager(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	WinMainWnd *ptr;
	LRESULT result;

	ptr = (WinMainWnd *)GetWindowLong(hwnd, GWL_USERDATA);
	if (ptr == NULL) {
		if (msg == WM_CREATE) {
			ptr = (WinMainWnd *)(((LPCREATESTRUCT)lp)->lpCreateParams);
			if (ptr != NULL) {
				SetWindowLong(hwnd, GWL_USERDATA, (LONG_PTR)ptr);
			}
		}
	}
	
	if (ptr != NULL) {
		result = ptr->WndProc(hwnd, msg, wp, lp);
	} else {
		result = DefWindowProc(hwnd, msg, wp, lp);
	}
	return result;
}
