#include"../Input.hpp"
#include"GameLib/src/Windows/Window.hpp"
#include<Windows.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

namespace GameLib
{

	namespace {

		LPDIRECTINPUT8 g_pInputInterface;
		LPDIRECTINPUTDEVICE8 g_pKeyDevice;
		LPDIRECTINPUTDEVICE8 g_MouseDevice;
		HWND g_hwnd;
	}

	bool CreateInputInterface();
	bool CreateKeyboardDevice(HWND hwnd);
	bool CreateMouseDevice(HWND hwnd);
	//!< 協調レベルの設定
	BOOL SetUpCooperativeLevel(LPDIRECTINPUTDEVICE8 device, HWND hwnd);
	//!< マウスの制御起動
	BOOL StartMouseControl();
	
	

	bool InitInput(HWND hwnd)
	{
		if (!CreateInputInterface())
			return false;

		if (!CreateKeyboardDevice(hwnd))
			return false;

		if (!CreateMouseDevice(hwnd))
			return false;

		g_hwnd = hwnd;

		return true;
		
	}

	bool CreateInputInterface()
	{
		// IDirectInput8インターフェイスの取得
		HRESULT hr = DirectInput8Create(
			GetModuleHandle(nullptr),
			DIRECTINPUT_VERSION,
			IID_IDirectInput8,
			(void**)&g_pInputInterface,
			NULL);
		if (FAILED(hr))
		{
			return false;
		}

		return true;
	}

	bool CreateKeyboardDevice(HWND hwnd)
	{
		HRESULT hr;
		// IDirectInputDevice8インターフェイスの取得
		hr = g_pInputInterface->CreateDevice(GUID_SysKeyboard, &g_pKeyDevice, NULL);
		if (FAILED(hr))
		{
			return false;
		}

		// デバイスのフォーマットの設定
		hr = g_pKeyDevice->SetDataFormat(&c_dfDIKeyboard);
		if (FAILED(hr))
		{
			return false;
		}

		// 協調モードの設定
		hr = g_pKeyDevice->SetCooperativeLevel(hwnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
		if (FAILED(hr))
		{
			return false;
		}

		// デバイスの取得開始
		g_pKeyDevice->Acquire();

		return true;
	}

	bool CreateMouseDevice(HWND hwnd)
	{
		g_MouseDevice = nullptr;

		// デバイス生成
		HRESULT hr = g_pInputInterface->CreateDevice(
			GUID_SysMouse,
			&g_MouseDevice,
			NULL);

		if (FAILED(hr))
		{
			return false;
		}

		// 入力フォーマットの指定
		hr = g_MouseDevice->SetDataFormat(&c_dfDIMouse);
		if (FAILED(hr))
		{
			return false;
		}

		// 協調レベルの設定
		if (SetUpCooperativeLevel(g_MouseDevice,hwnd) == false)
		{
			return false;
		}

		int count = 0;
		// 制御開始
		while (StartMouseControl() == false)
		{
			Sleep(100);
			count++;
			if (count >= 5)
			{
				break;
			}
		}

		return true;
	}

	void ShutdownInput()
	{
		g_pKeyDevice->Unacquire();
		g_pKeyDevice->Release();
		g_pInputInterface->Release();
	}


	BOOL SetUpCooperativeLevel(LPDIRECTINPUTDEVICE8 device, HWND hwnd)
	{
		// 協調モードの設定
		if (FAILED(device->SetCooperativeLevel(
			hwnd,
			DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)
		))
		{
			return false;
		}

		return true;
	}


	BOOL StartMouseControl()
	{
		// デバイスが生成されてない
		if (g_MouseDevice == nullptr)
		{
			return false;
		}
		// 制御開始
		if (FAILED(g_MouseDevice->Acquire()))
		{
			return false;
		}

		DIDEVCAPS cap;
		g_MouseDevice->GetCapabilities(&cap);
		// ポーリング判定
		if (cap.dwFlags & DIDC_POLLEDDATAFORMAT)
		{
			DWORD error = GetLastError();
			// ポーリング開始
			if (FAILED(g_MouseDevice->Poll()))
			{
				return false;
			}
		}

		return true;
	}

	KeyboardBase::KeyboardBase()
	{
		memset(mCurrState, 0, 256);
		memset(mPrevState, 0, 256);
	}

	KeyboardBase::~KeyboardBase()
	{
	}

	void KeyboardBase::Update()
	{
		memcpy(mPrevState, mCurrState, 256);
		if (g_pKeyDevice)
			g_pKeyDevice->GetDeviceState(256, mCurrState);
	}

	bool KeyboardBase::GetKeyValue(unsigned char key ) const
	{

		if (mCurrState[key] & 0x80)
			return true;
		else
			return false;
		
	}

	int KeyboardBase::GetKeyState(unsigned char key) const
	{
	
		if (mPrevState[key] & 0x80)
		{
			if (mCurrState[key] & 0x80)
				return 2;
			else
				return 3;
		}
		else
		{
			if (mCurrState[key] & 0x80)
				return 1;
			else
				return 0;
		}
		
	}

	MouseBase::MouseBase()
		:mMousePosX()
		,mMousePosY()
		,mRelativeMousePosX()
		,mRelativeMousePosY()
	{
		ZeroMemory(&mCurrState, sizeof(DIMOUSESTATE));
		ZeroMemory(&mPrevState, sizeof(DIMOUSESTATE));
	}

	MouseBase::~MouseBase()
	{
	}

	void MouseBase::Update()
	{
		if (g_MouseDevice == nullptr)
			return;

		// 更新前に最新マウス情報を保存する
		mPrevState = mCurrState;

		// マウスの状態を取得します
		HRESULT	hr = g_MouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), &mCurrState);
		if (FAILED(hr))
		{
			g_MouseDevice->Acquire();
			hr = g_MouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), &mCurrState);
		}
		POINT p;
		// マウス座標(スクリーン座標)を取得する
		GetCursorPos(&p);

		// スクリーン座標にクライアント座標に変換する
		ScreenToClient(g_hwnd, &p);

		mRelativeMousePosX = p.x - mMousePosX;
		mRelativeMousePosY = p.y - mMousePosY;

		mMousePosX = static_cast<float>(p.x);
		mMousePosY = static_cast<float>(p.y);
		
	}

	bool MouseBase::GetMouseButtonValue(int mouseButton) const
	{
		if (mouseButton < 0 || 2 < mouseButton)
			return false;

		if (mCurrState.rgbButtons[mouseButton] & 0x80)
			return true;
		else
			return false;
	}

	int MouseBase::GetMouseButtonState(int mouseButton) const
	{

		if (mPrevState.rgbButtons[mouseButton] & 0x80)
		{
			if (mCurrState.rgbButtons[mouseButton] & 0x80)
				return 2;
			else
				return 3;
		}
		else
		{
			if (mCurrState.rgbButtons[mouseButton] & 0x80)
				return 1;
			else
				return 0;
		}
	}


}