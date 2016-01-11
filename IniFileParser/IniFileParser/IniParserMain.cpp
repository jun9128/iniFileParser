//!
//! @file IniParserMain.cpp
//! @breaf INIファイル解析メイン処理
//! @author 河合 純
//! @date 2016/01/11 作成
//!
#include "IniParserMain.h"
#include <tchar.h>

//!
//! コンストラクタ
//!
IniParserMain::IniParserMain(void)
{
}

//!
//! デストラクタ
//!
IniParserMain::~IniParserMain(void)
{
}

//!
//! ウィンドウプロシージャ
//! @param hwnd 対象のウィンドウ
//! @param msg メッセージID
//! @param wp パラメータ
//! @param lp パラメータ
//! @return 処理結果
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
