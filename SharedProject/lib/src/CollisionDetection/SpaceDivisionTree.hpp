#pragma once
#include<list>
#include"CollisionDetectionSettingImpl.hpp"

namespace GameLib
{

	class LinerObject;
	class SpaceCell;
		
	class SpaceDivisionTree
	{
		SpaceCell** mSpaceCellArray;
		int mAllSpaceCellNum;

	public:
		SpaceDivisionTree();
		~SpaceDivisionTree();

		//�؂ɓo�^
		bool Resist(LinerObject* linerObj);

		//�؂𑀍삵�A�����蔻������s
		void SearchTree();

		void CreateNewSpaceCell(int spaceNum);
		//spaceNum�����q��Ԃ�delete
		void DeleteSpaceCell(int spaceNum = 0);

	private:
		//SearcheTree�ōċA�I�Ɏg�p
		std::list<LinerObject*> RecursionSearchTree(std::list<LinerObject*>&& collisionStack, int speaceCellNum);

		

	};
}