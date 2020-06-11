#pragma once

namespace GameLib
{
	class LinerObject;

	class SpaceCell
	{
		LinerObject* mFirstLinerObject;
		int mThisSpaceNumber;

	public:
		SpaceCell(int spaceNum);
		~SpaceCell();


		//���̕�����ԂɃI�u�W�F�N�g��ǉ�
		bool Push(LinerObject* obj);

		LinerObject* GetFirstLinerObject() const noexcept {
			return mFirstLinerObject;
		}
	};
}