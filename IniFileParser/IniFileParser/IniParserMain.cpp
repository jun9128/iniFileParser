//!
//! @file IniParserMain.cpp
//! @breaf INI�t�@�C����̓��C������
//! @author �͍� ��
//! @date 2016/01/11 �쐬
//!
#include "IniParserMain.h"
#include <tchar.h>

//!
//! �R���X�g���N�^
//!
IniParserMain::IniParserMain(void)
{
}

//!
//! �f�X�g���N�^
//!
IniParserMain::~IniParserMain(void)
{
}

//!
//! �E�B���h�E�v���V�[�W��
//! @param hwnd �Ώۂ̃E�B���h�E
//! @param msg ���b�Z�[�WID
//! @param wp �p�����[�^
//! @param lp �p�����[�^
//! @return ��������
//!
LRESULT
IniParserMain::WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg) {
	case WM_CREATE:
		ShowWindow(hwnd, SW_SHOW);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wp, lp);
	}
	return 0;
}
