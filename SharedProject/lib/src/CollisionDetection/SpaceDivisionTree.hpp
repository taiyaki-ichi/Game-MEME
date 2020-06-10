#pragma once
#include<list>

namespace GameLib
{

	class LinerObject;

	class SpaceDivisionTree
	{
		LinerObject** mSpeaceCellArray;
		int mAllSpeaceCellNum;

	public:
		SpaceDivisionTree();
		~SpaceDivisionTree();

		//�؂ɓo�^
		bool Resist(LinerObject* linerObj);

		//�؂𑀍삵�A�����蔻������s
		void SearchTree();

		//�؂����Z�b�g
		void Reset();

	private:
		//SearcheTree�ōċA�I�Ɏg�p
		std::list<LinerObject*> RecursionSearchTree(std::list<LinerObject*>&& collisionStack, int speaceCellNum);

		//���X�g�ɓo�^
		void ResistListTail(LinerObject* resistObj, LinerObject* listObj);

	};
}