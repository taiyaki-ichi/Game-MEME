#pragma once
#include"Vector2.hpp"
#include<cmath>
#include<utility>

namespace GameLib
{

	//���_�𒆐S��rot����]
	Vector2&& Rotation(Vector2&& vec, float rot) {

		if (rot == 0.f)
			return std::move(vec);

		float x = vec.x * std::cos(-rot) - vec.y * std::sin(-rot);
		float y = vec.x * std::sin(-rot) + vec.y * std::cos(-rot);

		return { x,y };
	}

	//center�ƒ��S��rot��]
	Vector2&& Rotation(Vector2&& vec, float rot, const Vector2& center) {
		auto v = Rotation(vec - center, rot);
		return v + center;
	}
	Vector2&& Rotation(const Vector2& vec, float rot, const Vector2& center) {
		auto v = Rotation(vec - center, rot);
		return v + center;
	}

	//�A�t�B���ϊ�
	Vector2&& Affine(const Vector2& vec, Vector2&& unitVecX, Vector2&& unitVecY, const Vector2& origin) {
		float x = unitVecX.x * vec.x + unitVecY.x * vec.y + origin.x;
		float y = unitVecX.y * vec.x + unitVecY.y * vec.y + origin.y;
		return { x,y };
	}

	//���W�`�̒��S�Ɣ{���Ɗp�x����A�t�B���ϊ�
	Vector2&& Affine(const Vector2& vec, const Vector2& center, float rot, float scale) {
		Vector2 unitVecX = Rotation({ 1.f,0.f }, rot) * scale;
		Vector2 unitVecY = Rotation({ 0.f,1.f }, rot) * scale;
		return Affine(vec, std::move(unitVecX), std::move(unitVecY), -center);
	}


}