#pragma once
#include<Windows.h>
#include<string>

namespace GameLib
{
	//�E�B���h�E�̐���
	bool CreateAppWindow(wchar_t const* windowName, float windowWidth, float windowHeigth, HWND& hwnd);

	float GetWindowWidth();
	float GetWindowHeigth();
}