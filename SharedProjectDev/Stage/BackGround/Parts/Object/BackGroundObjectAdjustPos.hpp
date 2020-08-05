#pragma once
#include"GameLib/include/Math/Vector2.hpp"
#include<utility>
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"Stage/WindowSize.hpp"

namespace Stage::BackGround
{

	//margin�͒��S����̕��A�z�����甽�Α��Ɉړ��A�}�C�i�X�ňړ����Ȃ�
	inline GameLib::Vector2 AdjustPos(GameLib::Vector2&& vec, float marginX, float marginY) {

		float x = WindowSize::WIDTH / 2.f + marginX;
		float y = WindowSize::HEIGHT / 2.f + marginY;
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

	//ViewPort�̉e�����l������o�[�W����
	//rate��ViewPort�̈ړ��ʂ�����Z���銄��
	inline GameLib::Vector2 AdjustPos(const GameLib::Vector2& vec, float marginX, float marginY, float rateX, float rateY) 
	{

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

	inline GameLib::Vector2 AdjustPos(const GameLib::Vector2& vec, float marginX, float marginY, float rate) 
	{
		return AdjustPos(vec, marginX, marginY, rate, rate);
	}
}