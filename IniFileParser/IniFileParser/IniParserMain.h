//!
//! @file IniParserMain.h
//! @breaf INI�t�@�C����̓��C��
//! @author �͍� ��
//! @date 2016/01/11 �쐬
//!

#pragma once

#include "WinMainWnd.h"

//!
//! INI�t�@�C����̓��C�������p�N���X
//!
class IniParserMain : public WinMainWnd
{
public:
	IniParserMain();
	~IniParserMain(void);

private:
	LRESULT WndProc(HWND, UINT, WPARAM, LPARAM);
};
