#pragma once
#include"lib/include/CollisionDetection/CollisionDetectionSetting.hpp"
#include"SpaceDivisionTree.hpp"

namespace GameLib
{
	constexpr int POWER_OF_FOUR[11] = { 1,4,16,64,256,1024,4096,16384,65536,262144,1048576 };
	constexpr int MAX_SPACECELL_NUM = (POWER_OF_FOUR[LEVEL + 1] - 1) / 3;

	class CollisionDetectionSettingImpl : public CollisionDetectionSetting
	{
	private:
		//�����蔻����s���O�Ɉꊇ�Ōv�Z
		//��ԕ��������ۂ̍ŏ��̃^�e���R
		static float mUnitWidth;
		static float mUnitHeigth;

		static float mLeft;
		static float mRight;
		static float mTop;
		static float mBottom;


	public:
		//�����蔻��̍s���O�ɌĂяo���Ă��ꂼ��̒l���v�Z���Ă���
		static void ColcMembers() {
			mLeft = mPos.x - mWidth / 2.f;
			mRight = mPos.x + mWidth / 2.f;
			mTop = mPos.y - mHeigth / 2.f;
			mBottom = mPos.y + mHeigth / 2.f;

			mUnitWidth = (mRight - mLeft) / (1 << LEVEL);
			mUnitHeigth = (mBottom - mTop) / (1 << LEVEL);

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

	};

}