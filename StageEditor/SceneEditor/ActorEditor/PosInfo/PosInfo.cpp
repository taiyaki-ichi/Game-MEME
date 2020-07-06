#include"PosInfo.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include<iostream>
namespace StageEditor
{
	PosInfo::PosInfo(GameLib::Actor* owner)
		:GameLib::Actor(owner)
		, mPosition{ 0.f,0.f }
		, mIsOK{ false }
	{
		
	}
	void PosInfo::CustomizeUpdate()
	{
		using namespace GameLib;

		if (!mIsOK)
		{
			//変換されている分を戻す
			mPosition = AffineInv(InputState::GetMousePos(), Viewport::GetPos(), Viewport::GetRotation(), Viewport::GetScale());
			if (GameLib::InputState::GetState(GameLib::MouseButton::Middle) == GameLib::ButtonState::Pressed)
				mIsOK = true;
		}
	}
	bool PosInfo::IsOK()
	{
		return mIsOK;
	}
	const GameLib::Vector2& PosInfo::GetPosition()
	{
		return mPosition;
	}
}