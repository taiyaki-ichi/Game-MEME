#pragma once
#include<Windows.h>
#include<string>

namespace GameLib
{
	//ウィンドウの生成
	bool CreateAppWindow(char const* windowName, float windowWidth, float windowHeigth, HWND& hwnd);

	float GetWindowWidth();
	float GetWindowHeigth();
}