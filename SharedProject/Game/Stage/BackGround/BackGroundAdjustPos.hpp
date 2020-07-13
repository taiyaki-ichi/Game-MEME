#pragma once
#include"GameLib/include/Math/Vector2.hpp"
#include"Game/Window.hpp"
#include<utility>
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

namespace Game::Stage::BackGround
{
	constexpr static float RANGE_LEFT = -WINDOW_WIDTH / 2.f - 50.f;
	constexpr static float RANGE_RIGHT = WINDOW_WIDTH / 2.f + 50.f;
	constexpr static float RANGE_BOTTOM = -WINDOW_HEIGHT / 2.f - 50.f;
	constexpr static float RANGE_TOP = WINDOW_HEIGHT / 2.f + 50.f;

	//rate��ViewPort�̈ړ��ʂ�����Z���銄��
	//margin���}�C�i�X�̏ꍇ���[�v���Ȃ�
	inline GameLib::Vector2 AdjustPos(GameLib::Vector2&& vec, float marginX, float marginY) {

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
		return std::move(vec);
	}


	inline GameLib::Vector2 AdjustPos(const GameLib::Vector2& vec, float marginX, float marginY, float rateX, float rateY) {
		
		

		//std::cout << "pos: " << result.x << "," << result.y << "\n";

		auto viewPortPos = GameLib::Viewport::GetPos();

		//Gravity�̕����ˑ��ł͂Ȃ�ViewPort�̕����ˑ��ɕύX����
		viewPortPos = GameLib::Vector2::Rotation(viewPortPos, GameLib::Viewport::GetRotation());

		auto result = vec + GameLib::Vector2{ viewPortPos.x * rateX,viewPortPos.y * rateY };
		result -= viewPortPos;
		result = AdjustPos(std::move(result), marginX, marginY);
		result += viewPortPos;

		return result;


	}

	//ViewPort�̉e�����l������o�[�W����
	inline GameLib::Vector2 AdjustPos(const GameLib::Vector2& vec, float marginX, float marginY, float rate) {

		
		return AdjustPos(vec, marginX, marginY, rate, rate);
	}
}