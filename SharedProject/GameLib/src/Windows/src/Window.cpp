#include"../Window.hpp"
#include<Windows.h>

namespace GameLib
{

    namespace {
        static float WINDOW_WIDTH = 0.f;
        static float WINDOW_HEIGHT = 0.f;
    }

    //�E�B���h�E�̔j�󃁃b�Z�������A�Œ���̃E�B���h�E�̋@�\�݂̂����Ŏ���
    LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
            break;

        }

        return 0;
    }


	bool CreateAppWindow(WINDOW_NAME_TYPE const* windowName, float windowWidth, float windowHeigth, HWND& hwnd)
	{

        HINSTANCE hInstance = GetModuleHandle(NULL);
        if (!hInstance)
            return false;
        
        
        // �V���v���E�B���h�E�N���X�ݒ�
        WNDCLASSEX wcex = {
            sizeof(WNDCLASSEX),	
            CS_HREDRAW | CS_VREDRAW,
            WndProc,
            0,								
            0,								
            hInstance,		
            LoadIcon(NULL, IDI_APPLICATION),
            LoadCursor(NULL, IDC_ARROW),	
            NULL,							
            NULL,							
            windowName,													
            NULL	
        };
        
        if (!RegisterClassEx(&wcex))
            return false;
       

        //�E�B���h�E�̐���
        hwnd = CreateWindowEx(
            0,
            windowName,
            windowName,
            (WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME) | WS_VISIBLE ,
            CW_USEDEFAULT,
            0,
            static_cast<int>(windowWidth),
            static_cast<int>(windowHeigth),
            NULL,
            NULL,
            hInstance, 
            NULL);

        if (!hwnd)
            return false;

        WINDOW_WIDTH = windowWidth;
        WINDOW_HEIGHT = windowHeigth;

        RECT rc1;
        RECT rc2;

        GetWindowRect(hwnd, &rc1);
        GetClientRect(hwnd, &rc2);
        windowWidth += ((rc1.right - rc1.left) - (rc2.right - rc2.left));
        windowHeigth += ((rc1.bottom - rc1.top) - (rc2.bottom - rc2.top));
        SetWindowPos(hwnd, NULL, 0, 0, windowWidth, windowHeigth, (SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_NOMOVE));
        
        ShowWindow(hwnd, SW_SHOW);
        UpdateWindow(hwnd);
       
		

        return true;
	}

    float GetWindowWidth()
    {
        return WINDOW_WIDTH;
    }

    float GetWindowHeigth()
    {
        return WINDOW_HEIGHT;
    }

 
}