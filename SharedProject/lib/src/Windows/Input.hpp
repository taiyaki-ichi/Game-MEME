#pragma once
#include<string>
#include<dinput.h>

namespace GameLib
{

	bool InitInput();
	void ShutdownInput();

	class KeyboardBase
	{
	public:
		KeyboardBase();
		~KeyboardBase();

		void Update();

		//�L�[�̐^�U�̂�
		bool GetKeyValue(unsigned char key) const;
		//�O�̃t���[���Ɣ�r���Ă̏��,0:�����Ȃ��@1:�����ꂽ�@2:�������ςȂ��@3:���ꂽ
		int GetKeyState(unsigned char key) const;

	private:
		unsigned char mCurrState[256];
		unsigned char mPrevState[256];
	};

	class MouseBase
	{
	public:

		MouseBase();
		~MouseBase();

		void Update();

		float GetPositionX() const { return mMousePosX; }
		float GetPositionY() const{ return mMousePosY; }


		float GetRelativePosX() const { return mRelativeMousePosX; }
		float GetRelativePosY() const { return mRelativeMousePosY; }

		//0:���@1:�E�@2:����
		bool GetMouseButtonValue(int mouseButton) const;
		//�O�̃t���[���Ɣ�r���Ă̏��,0:�����Ȃ��@1:�����ꂽ�@2:�������ςȂ��@3:���ꂽ
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