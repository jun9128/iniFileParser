//!
//! @file main.cpp
//! @breaf INI�t�@�C�����
//! @author �͍� ��
//! @date 2016/01/11 �쐬

#include <Windows.h>
#include "IniParserMain.h"

#define CLASS_NAME TEXT("INIPARSER")
#define APP_NAME TEXT("INI file parser")

int WINAPI
WinMain(HINSTANCE instance, HINSTANCE prev_instance, LPSTR cmdline, int cmdshow)
{
	IniParserMain *parser;
	TCHAR classname[16] = CLASS_NAME;
	BOOL ret;

	parser = new IniParserMain();
	if (!parser) {
		return 0;
	}

	ret = parser->CreateMainWindow(instance, classname, APP_NAME, 640, 480);
	if (!ret) {
		return 0;
	}

	return parser->MainMessageLoop(0, 0);
}
