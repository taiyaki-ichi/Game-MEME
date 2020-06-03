#pragma once
#include<string>
#include<dinput.h>

namespace GameLib
{

	bool InitInput();
	void ShutdownInput();

	class Keyboard
	{
	public:
		Keyboard();
		~Keyboard();

		void Update();

		//キーの真偽のみ
		bool GetKeyValue(unsigned char key) const;
		//前のフレームと比較しての状態,0:何もなし　1:押された　2:押しっぱなし　3:離れた
		int GetKeyState(unsigned char key) const;

	private:
		unsigned char mCurrState[256];
		unsigned char mPrevState[256];
	};

	class Mouse
	{
	public:

		Mouse();
		~Mouse();

		void Update();

		float GetPositionX() const { return mMousePosX; }
		float GetPositionY() const{ return mMousePosX; }


		float GetRelativePosX() const { return mRelativeMousePosX; }
		float GetRelativePosY() const { return mRelativeMousePosY; }

		//0:左　1:右　2:中央
		bool GetMouseButtonValue(int mouseButton) const;
		//前のフレームと比較しての状態,0:何もなし　1:押された　2:押しっぱなし　3:離れた
		int GetMouseButtonState(int mouseButton) const;

	private:

		float mMousePosX;
		float mMousePosY;

		float mRelativeMousePosX;
		float mRelativeMousePosY;

		DIMOUSESTATE mCurrState;
		DIMOUSESTATE mPrevState;
	};

}