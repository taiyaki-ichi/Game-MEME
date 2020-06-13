#pragma once
#include<list>
#include<array>
#include<optional>
#include"CollisionDetectionSettingImpl.hpp"
#include"SpaceCell.hpp"

namespace GameLib
{

	class LinerObject;
	class SpaceCell;
		
	class SpaceDivisionTree
	{
		std::array<std::optional<SpaceCell>, MAX_SPACECELL_NUM> mSpaceCellArray;

	public:
		SpaceDivisionTree();
		~SpaceDivisionTree();

		//�؂ɓo�^
		bool Resist(LinerObject* linerObj);

		//�؂𑀍삵�A�����蔻������s
		void SearchTree();

		void CreateNewSpaceCell(int spaceNum);
		//spaceNum�����q��Ԃ�delete
		void DeleteSpaceCell(int spaceNum);

		//
		int GetCellNum();

	private:
		//SearcheTree�ōċA�I�Ɏg�p
		std::list<LinerObject*> RecursionSearchTree(std::list<LinerObject*>&& collisionStack, int speaceCellNum);

		

	};
}