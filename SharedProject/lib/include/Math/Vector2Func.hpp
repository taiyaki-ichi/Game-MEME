#pragma once
#include"Vector2.hpp"
#include<cmath>
#include<utility>
#include<algorithm>


namespace GameLib
{

	//���_�𒆐S��rot����]
	inline Vector2 Rotation(Vector2&& vec, float rot) {

		if (rot == 0.f)
			return std::move(vec);

		float x = vec.x * std::cos(rot) - vec.y * std::sin(rot);
		float y = vec.x * std::sin(rot) + vec.y * std::cos(rot);

		return { x,y };
	}

	//center�ƒ��S��rot��]
	inline Vector2 Rotation(Vector2&& vec, float rot, const Vector2& center) {
		auto v = Rotation(vec - center, rot);
		return v + center;
	}
	inline Vector2 Rotation(const Vector2& vec, float rot, const Vector2& center) {
		auto v = Rotation(vec - center, rot);
		return v + center;
	}

	//�A�t�B���ϊ�
	inline Vector2 Affine(const Vector2& vec, Vector2&& unitVecX, Vector2&& unitVecY, const Vector2& origin) {
		float x = unitVecX.x * vec.x + unitVecY.x * vec.y + origin.x;
		float y = unitVecX.y * vec.x + unitVecY.y * vec.y + origin.y;
		return { x,y };
	}

	//���W�`�̒��S�Ɣ{���Ɗp�x����A�t�B���ϊ�
	inline Vector2 Affine(const Vector2& vec, const Vector2& center, float rot, float scale) {
		Vector2 unitVecX = Rotation({ 1.f,0.f }, rot) * scale;
		Vector2 unitVecY = Rotation({ 0.f,1.f }, rot) * scale;
		return Affine(vec, std::move(unitVecX), std::move(unitVecY), -center);
	}


	//�����v����4���̃x�N�g���݂�����
	inline std::vector<Vector2> GetCounterclockwise4Vec() {
		std::vector<Vector2> vecs = {
			{1.f,1.f},
			{-1.f,1.f},
			{-1.f,-1.f},
			{1.f,-1.f}
		};
		return vecs;
	}


	inline std::vector<Vector2> GetRectangleVectors(const Vector2& center,float width,float heigth,float rot) {
		auto vecs = GetCounterclockwise4Vec();
		std::vector<Vector2> result;
		std::transform(vecs.begin(), vecs.end(), std::back_inserter(result),
			[center, width, heigth, rot](const Vector2& vec) {return Rotation(Vector2{ vec.x * width / 2.f,vec.y * heigth / 2.f }, rot) + center; });

		return result;
	}
}