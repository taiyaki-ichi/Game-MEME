#pragma once
#include<Windows.h>
#include<string>

namespace GameLib
{
#ifdef _M_X64
#define WINDOW_NAME_TYPE wchar_t
#else 
#define WINDOW_NAME_TYPE char
#endif

	//ウィンドウの生成
	bool CreateAppWindow(WINDOW_NAME_TYPE const* windowName, float windowWidth, float windowHeigth, HWND& hwnd);

	float GetWindowWidth();
	float GetWindowHeigth();
}