#pragma once
#include<utility>
#include"GameLib/include/Math/Vector2.hpp"

namespace GameLib
{

	//�����蔻����s���͈͂Ƃ��̒��S�̍��W
	class CollisionDetectionSetting
	{
	protected:
		//�Z�b�e�B���O�ł���l
		static float mWidth;
		static float mHeigth;
		static Vector2 mPos;


	public:

		static float GetWidth() noexcept {
			return mWidth;
		}
		static void SetWidth(float w) noexcept {
			mWidth = w;
		}
		static float GetHeight() noexcept {
			return mHeigth;
		}
		static void SetHeight(float h) noexcept {
			mHeigth = h;
		}
		static const Vector2& GetPos() noexcept {
			return mPos;
		}
		static void SetPos(const Vector2& pos) noexcept {
			mPos = pos;
		}
		static void SetPos(Vector2&& pos) noexcept {
			mPos = std::move(pos);
		}
		

	};

}