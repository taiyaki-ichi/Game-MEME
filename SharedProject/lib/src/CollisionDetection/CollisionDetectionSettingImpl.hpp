#pragma once
#include"lib/include/CollisionDetection/CollisionDetectionSetting.hpp"
#include"SpaceDivisionTree.hpp"

namespace GameLib
{

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

			mUnitWidth = (mRight - mLeft) / (1 << TREE_LEVEL);
			mUnitHeigth = (mBottom - mTop) / (1 << TREE_LEVEL);

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