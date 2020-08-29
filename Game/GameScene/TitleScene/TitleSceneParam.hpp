#pragma once
#include"GameLib/include/Math/Vector2.hpp"

namespace Game
{
	namespace TitleSceneParam
	{
		constexpr float BUTTON_WIDTH = 200.f;
		constexpr float BUTTON_HEIGHT = 200.f;
		constexpr float BUTTON_FLAME_WIDTH = 10.f;

		const GameLib::Vector2 A_BUTTON_ADJUST = { -150.f,-120.f };
		const GameLib::Vector2 D_BUTTON_ADJUST = { 150.f,-120.f };

		//Buttonの位置からの距離
		const GameLib::Vector2 BUTTON_STRING_TAG_ADJUST{ 0.f,120.f };

		constexpr float KAKKO_ADJUST = 20.f;

	}
}