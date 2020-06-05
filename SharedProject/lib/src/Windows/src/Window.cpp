#include"../Window.hpp"
#include"WindowClassName.hpp"
#include<Windows.h>

namespace GameLib
{

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


	bool CreateAppWindow(std::string&& windowName, float windowWidth, float windowHeigth)
	{

		HWND hwnd;
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
            WINDOW_CLASS_NAME,													
            NULL	
        };
        
        if (!RegisterClassEx(&wcex))
            return false;
       

        //�E�B���h�E�̐���
        hwnd = CreateWindowEx(
            0,
            WINDOW_CLASS_NAME,
            TEXT(windowName.c_str()),
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
        
        ShowWindow(hwnd, SW_SHOW);
        UpdateWindow(hwnd);
       
		

        return true;
	}

 
}