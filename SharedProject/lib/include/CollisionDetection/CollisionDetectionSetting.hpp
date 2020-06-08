#pragma once
#include<utility>
#include"lib/include/Math/Vector2.hpp"

namespace GameLib
{	
	constexpr unsigned int TREE_MAX_LEVEL = 9;

	//�����蔻����s���͈͂Ƃ��̒��S�̍��W
	class CollisionDetectionSetting
	{
	private:
		//�Z�b�e�B���O�ł���l
		static float mWidth;
		static float mHeigth;
		static Vector2 mPos;
		//�ő�l�͂�9��10�w�̋�Ԃɕ����ł���
		static unsigned int mLevel;


		//�����蔻����s���O�Ɉꊇ�Ōv�Z
		//��ԕ��������ۂ̍ŏ��̃^�e���R
		static float mUnitWidth;
		static float mUnitHeigth;

		static float mLeft;
		static float mRight;
		static float mTop;
		static float mBottom;

		static const int mPow[10];

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
		static void SetHeigth(float h) noexcept {
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
		static unsigned int GetLevel()noexcept {
			return mLevel;
		}
		static void SetLevel(unsigned int l)noexcept {
			if (l < 0)
				mLevel = 0;
			else if (TREE_MAX_LEVEL < l)
				mLevel = TREE_MAX_LEVEL;
			else
				mLevel = l;

		}


		//�����蔻��̍s���O�ɌĂяo���Ă��ꂼ��̒l���v�Z���Ă���
		static void ColcMembers() {
			mLeft = mPos.x - mWidth / 2.f;
			mRight = mPos.x + mWidth / 2.f;
			mTop = mPos.y - mHeigth / 2.f;
			mBottom = mPos.y + mHeigth / 2.f;
			
			mUnitWidth = (mRight - mLeft) / (1 << mLevel);
			mUnitHeigth = (mBottom - mTop) / (1 << mLevel);
		}

		static float GetLeft() noexcept {
			return mLeft;
		}
		static float GetTop() noexcept {
			return mTop;
		}
		static float GetUnitWidth() noexcept {
			return mUnitWidth;
		}
		static float GetUnitHeigth() noexcept {
			return mUnitHeigth;
		}

		static int GetPowerOfFour(int num) {
			return mPow[num];
		}

	};

}