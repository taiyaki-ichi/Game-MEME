#pragma once
#include"GameLib/include/Math/Vector2.hpp"

namespace Game::Stage
{
	//画面の中心からこの範囲内にposがあるかどうか
	bool IsInScope(const GameLib::Vector2& pos, float left, float right, float bottom, float top);
	bool IsInScope(const GameLib::Vector2& pos, float w, float h);
}