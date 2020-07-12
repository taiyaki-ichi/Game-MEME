#pragma once
#include"GameLib/include/Math/Vector2.hpp"
#include"Game/Window.hpp"
#include<utility>
#include"GameLib/include/Viewport/Viewport.hpp"

namespace Game::Stage::BackGround
{
	constexpr static float RANGE_LEFT = -WINDOW_WIDTH / 2.f - 50.f;
	constexpr static float RANGE_RIGHT = WINDOW_WIDTH / 2.f + 50.f;
	constexpr static float RANGE_BOTTOM = -WINDOW_HEIGHT / 2.f - 50.f;
	constexpr static float RANGE_TOP = WINDOW_HEIGHT / 2.f + 50.f;

	//rate��ViewPort�̈ړ��ʂ�����Z���銄��
	//margin���}�C�i�X�̏ꍇ���[�v���Ȃ�
	inline GameLib::Vector2 AdjustPos(GameLib::Vector2&& vec,float marginX,float marginY) {

		float x = WINDOW_WIDTH / 2.f + marginX;
		float y = WINDOW_HEIGHT / 2.f + marginY;
		if (marginX >= 0.f) {
			while (vec.x < -x)
				vec.x += x * 2.f;
			while (vec.x >= x)
				vec.x -= x * 2.f;
		}
		if (marginY >= 0.f) {
			while (vec.y < y)
				vec.y += y * 2.f;
			while (vec.y >= y)
				vec.y -= y * 2.f;
		}
		/*
		while (vec.x < RANGE_LEFT)
			vec.x += (RANGE_RIGHT - RANGE_LEFT);
		while (vec.x >= RANGE_RIGHT)
			vec.x -= (RANGE_RIGHT - RANGE_LEFT);
		while (vec.y < RANGE_BOTTOM)
			vec.y += (RANGE_TOP - RANGE_BOTTOM);
		while (vec.y >= RANGE_TOP)
			vec.y -= (RANGE_TOP - RANGE_BOTTOM);
			*/
		return std::move(vec);
	}


	inline GameLib::Vector2 AdjustPos(const GameLib::Vector2& vec, float marginX, float marginY, float rateX, float rateY) {
		
		auto viewPortPos = GameLib::Viewport::GetPos();

		auto result = vec + GameLib::Vector2{ viewPortPos.x * rateX,viewPortPos.y * rateY };
		result -= viewPortPos;
		result = AdjustPos(std::move(result), marginX, marginY);
		result += viewPortPos;

		return result;
	}

	//ViewPort�̉e�����l������o�[�W����
	inline GameLib::Vector2 AdjustPos(const GameLib::Vector2& vec, float marginX, float marginY, float rate) {

		/*
		auto result = vec + GameLib::Viewport::GetPos() * rate;
		result -= GameLib::Viewport::GetPos();
		result = AdjustPos(std::move(result));
		result += GameLib::Viewport::GetPos();

		return result;
		*/
		return AdjustPos(vec, marginX, marginY, rate, rate);
	}
}