//!
//! @file WinMainWnd.h
//! @breaf Win32メイン画面の基底クラス
//! @author 河合 純
//! @date 2016/01/11 作成
//!
#pragma once

#include <Windows.h>

//!
//! Win32メイン画面ベースクラス
//!
class WinMainWnd
{
private:
	HWND mainWnd;           //!< メイン画面
	HINSTANCE instance;     //!< アプリケーションインスタンス

public:
	WinMainWnd(void);
	virtual ~WinMainWnd(void);

	BOOL CreateMainWindow(HINSTANCE, LPCTSTR, LPCTSTR, int, int);
	HWND GetMainWindow(void);
	HINSTANCE GetAppInstance(void);

	WPARAM MainMessageLoop(UINT, UINT);

private:
	static LRESULT CALLBACK WndProcManager(HWND, UINT, WPARAM, LPARAM);

protected:
	virtual LRESULT WndProc(HWND, UINT, WPARAM, LPARAM) = 0;
};
