//!
//! @file WinMainWnd.h
//! @breaf Win32���C����ʂ̊��N���X
//! @author �͍� ��
//! @date 2016/01/11 �쐬
//!
#pragma once

#include <Windows.h>

//!
//! Win32���C����ʃx�[�X�N���X
//!
class WinMainWnd
{
private:
	HWND mainWnd;           //!< ���C�����
	HINSTANCE instance;     //!< �A�v���P�[�V�����C���X�^���X

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
