#pragma once
#include"Stage/WindowSize.hpp"

namespace Game
{
	namespace RectCurtainParam
	{
		constexpr float SPEED = 20.f;

		//少し足さないと足りない
		constexpr float MAX_HEIGHT = Stage::WindowSize::HEIGHT + 50.f;
	}
}