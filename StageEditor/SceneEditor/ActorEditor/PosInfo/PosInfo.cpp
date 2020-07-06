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
	PosInfo::PosInfo(GameLib::Actor* owner, GameLib::Vector2&& vec)
		:GameLib::Actor{owner}
		, mPosition{std::move(vec)}
		, mIsOK{true}
	{
	}
	void PosInfo::CustomizeUpdate()
	{
		using namespace GameLib;

		if (!mIsOK)
		{
			//�ϊ�����Ă��镪��߂�
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