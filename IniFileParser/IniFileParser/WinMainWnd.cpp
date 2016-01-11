//!
//! @file WinMainWnd.cpp
//! @breaf Win32���C�����
//! @author �͍� ��
//! @date 2016/01/11
//!

#include <windowsx.h>
#include "WinMainWnd.h"

//!
//! �R���X�g���N�^
//!
WinMainWnd::WinMainWnd(void)
{
	this->mainWnd = NULL;
	this->instance = NULL;
}

//!
//! �f�X�g���N�^
//!
WinMainWnd::~WinMainWnd(void)
{
}

//!
//! �E�B���h�E����
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
//! �E�B���h�E�n���h���擾
//! @return �n���h��
//!
HWND
WinMainWnd::GetMainWindow(void)
{
	return this->mainWnd;
}

//!
//! �A�v���P�[�V�����C���X�^���X�擾
//! @return �A�v���P�[�V�����C���X�^���X
//!
HINSTANCE
WinMainWnd::GetAppInstance(void)
{
	return this->instance;
}

//!
//! ���b�Z�[�W���[�v
//! @param filtermin �������郁�b�Z�[�W�̉���
//! @param filtermax �������郁�b�Z�[�W�̏��
//! @return ���[�v�𔲂������̖߂�l
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
//! �o�^�p���b�Z�[�W�v���V�[�W��
//! @param hwnd �Ώۂ̃E�B���h�E
//! @param msg ���b�Z�[�WID
//! @param wp �p�����[�^
//! @param lp �p�����[�^
//! @return ��������
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
