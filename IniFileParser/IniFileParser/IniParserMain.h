//!
//! @file IniParserMain.h
//! @breaf INIファイル解析メイン
//! @author 河合 純
//! @date 2016/01/11 作成
//!

#pragma once

#include "WinMainWnd.h"

//!
//! INIファイル解析メイン処理用クラス
//!
class IniParserMain : public WinMainWnd
{
public:
	IniParserMain();
	~IniParserMain(void);

private:
	LRESULT WndProc(HWND, UINT, WPARAM, LPARAM);
};
