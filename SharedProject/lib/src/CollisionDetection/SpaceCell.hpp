#pragma once
#include<optional>

namespace GameLib
{
	class LinerObject;
	class SpaceCell
	{
		std::optional<LinerObject*> mFirstLinerObject;
		int mThisSpaceNumber;

	public:
		SpaceCell(int spaceNum);
		~SpaceCell();


		//���̕�����ԂɃI�u�W�F�N�g��ǉ�
		bool Push(LinerObject* obj);

		const std::optional<LinerObject*>& GetFirstLinerObject() const noexcept;

	};
}