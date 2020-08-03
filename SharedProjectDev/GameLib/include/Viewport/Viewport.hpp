#pragma once
#include<utility>
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Math/Numbers.hpp"

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
			while (rot < 0.f)
				rot += GameLib::PI * 2.f;
			while (rot >= GameLib::PI * 2.f)
				rot -= GameLib::PI * 2.f;

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