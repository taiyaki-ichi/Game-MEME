#pragma once
#include<utility>
#include"GameLib/include/Math/Vector2.hpp"

namespace GameLib
{
	class Viewport
	{
		//�J�����̈ʒu
		static Vector2 mPos;
		//�p�x
		static float mRotation;
		//����
		static float mScale;

	public:
		static void SetPos(const Vector2& pos) noexcept {
			mPos = pos;
		}
		static void SetPos(Vector2&& pos) noexcept {
			mPos = std::move(pos);
		}
		static const Vector2& GetPos() noexcept {
			return mPos;
		}

		static void SetRotation(float rot) noexcept {
			mRotation = rot;
		}

		static float GetRotation() noexcept {
			return mRotation;
		}

		static void SetScale(float s) noexcept {
			mScale = s;
		}
		static float GetScale() noexcept {
			return mScale;
		}

	};
}