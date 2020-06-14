#pragma once
#include"lib/include/InputState/InputStateInfo.hpp"
#include"lib/include/Math/Vector2.hpp"

namespace GameLib
{
	class MouseBase;

	class Mouse
	{
		MouseBase* mInputMouse;

	public:
		Mouse();
		~Mouse();

		//���t���[���Ă΂��
		void Update();

		Vector2 GetMousePos();
		Vector2 GetRerativeMousePos();

		bool GetValue(MouseButton&& mouseButton);
		ButtonState GetState(MouseButton&& mouseButton);

	};
}