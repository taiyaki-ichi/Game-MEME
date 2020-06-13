#include"lib/src/CollisionDetection/SpaceDivisionTree.hpp"
#include"lib/src/CollisionDetection/LinerObject.hpp"
#include"lib/src/CollisionDetection/CollisionDetectionSettingImpl.hpp"
#include"lib/include/CollisionDetection/Collider.hpp"
#include"lib/src/CollisionDetection/MortonNumber.hpp"
#include"lib/include/Math/Vector2Func.hpp"
#include"lib/src/CollisionDetection/SpaceCell.hpp"

#include<iostream>
#include "..\SpaceDivisionTree.hpp"

namespace GameLib
{

	//RecursionSearchTree���Ŏg�p�A�����蔻����s���������Ă���Ȃ�Actor�ɒʒm
	void DoCollisionDetection(LinerObject* obj1, LinerObject* obj2)
	{
		auto collider1 = obj1->GetCollider();
		auto collider2 = obj2->GetCollider();

		float s1 = collider1->GetScale();
		float s2 = collider2->GetScale();

		auto vecs1 = GetRectangleVectors(collider1->GetPosition(), collider1->GetWidth() * s1, collider1->GetWidth() * s1, collider1->GetRotation());
		auto vecs2 = GetRectangleVectors(collider2->GetPosition(), collider2->GetWidth() * s2, collider2->GetWidth() * s2, collider2->GetRotation());

		if (CollisionDetection(std::move(vecs1), std::move(vecs2)))
		{
			collider1->HitCollider(*collider2);
			collider2->HitCollider(*collider1);
		}
	}


	SpaceDivisionTree::SpaceDivisionTree()
		:mSpaceCellArray()
	{
		mSpaceCellArray[0] = SpaceCell(0);
		for (int i = 1; i < MAX_SPACECELL_NUM; i++) {
			mSpaceCellArray[i] = std::nullopt;
		}
		
	}

	SpaceDivisionTree::~SpaceDivisionTree()
	{
	}

	bool SpaceDivisionTree::Resist(LinerObject* linerObj)
	{
		linerObj->mNextObject = std::nullopt;
		linerObj->mPreObject = std::nullopt;

		auto collider = linerObj->GetCollider();
		float scale = collider->GetScale();
		float width = collider->GetWidth();
		float heigth = collider->GetHeigth();
		auto pos = collider->GetPosition();

		//squrt�g���Đ����ɂ�邩�H�H
		float halfUnitSize = (width * scale + heigth * scale) / 2.f;

		int spaceCellNum = GetMortonNumber(pos.x - halfUnitSize, pos.y - halfUnitSize, pos.x + halfUnitSize, pos.y + halfUnitSize);
		if (spaceCellNum < CollisionDetectionSettingImpl::GetNowLevelCellNum())
		{
			//��ԃI�u�W�F�N�g���Ȃ��ꍇ�쐬
			if (!mSpaceCellArray[spaceCellNum])
				CreateNewSpaceCell(spaceCellNum);

			return mSpaceCellArray[spaceCellNum].value().Push(linerObj);
		}

		return false;
	}

	void SpaceDivisionTree::SearchTree()
	{		
		std::list<LinerObject*> collisionStack;
		RecursionSearchTree(std::move(collisionStack), 0);
	}

	void SpaceDivisionTree::CreateNewSpaceCell(int spaceNum)
	{
		while (!mSpaceCellArray[spaceNum])
		{
			mSpaceCellArray[spaceNum] = SpaceCell(spaceNum);

			//�e��Ԃ�
			spaceNum = (spaceNum - 1) >> 2;
			if (spaceNum >=CollisionDetectionSettingImpl::GetNowLevelCellNum());
				break;
		}
	}

	void SpaceDivisionTree::DeleteSpaceCell(int spaceNum)
	{
		
		/*
		for (int i = 0; i < 4; i++)
		{
			int childNum = spaceNum * 4 + 1 + i;
			if (childNum < MAX_SPACECELL_NUM && mSpaceCellArray[childNum]) {
				DeleteSpaceCell(childNum);
				delete mSpaceCellArray[childNum].value();
				mSpaceCellArray[childNum] = std::nullopt;
				std::cout << "a";
			}
		}
		*/
		for(int i=1;i< MAX_SPACECELL_NUM;i++)
			if (mSpaceCellArray[i]) 
				mSpaceCellArray[i] = std::nullopt;

	}

	int SpaceDivisionTree::GetCellNum()
	{
		int sum = 0;
		for (int i = 0; i < CollisionDetectionSettingImpl::GetNowLevelCellNum(); i++) 
			if (mSpaceCellArray[i])
				sum++;

		return sum;
	}


	std::list<LinerObject*> SpaceDivisionTree::RecursionSearchTree(std::list<LinerObject*>&& collisionStack, int speaceCellNum)
	{
		std::optional<LinerObject*> linerObj1 = mSpaceCellArray[0].value().GetFirstLinerObject();
		std::optional<LinerObject*> linerObj2 = std::nullopt;

		while (linerObj1)
		{
			//mSpeaceCellArray�ɘA�Ȃ���`���X�g�Ƃ̓����蔻��(linerObj1�ȍ~�̐��`���X�g)
			//���Ȃ킿�����������ꂽ��ԓ���Collider�Ƃ̓����蔻��
			linerObj2 = linerObj1.value()->mNextObject;
			while (linerObj2)
			{
				DoCollisionDetection(linerObj1.value(), linerObj2.value());
				linerObj2 = linerObj2.value()->mNextObject;
				//std::cout << "a";
				
			}

			//collisionStack�ɂ���Collider�Ƃ̓����蔻��A�܂�
			//linerObj1�������镪�����ꂽ��Ԃɂ܂�����悤�ȁA�܂�
			//linerObj1�������镪�����ꂽ��Ԃ��傫�ȕ�����Ԃɑ�����Collider�Ƃ̓����蔻��
			if (!collisionStack.empty())
			{
				for (auto linerObj : collisionStack)
				{
					DoCollisionDetection(linerObj1.value(), linerObj);
				}
			}

			linerObj1 = linerObj1.value()->mNextObject;
		}
		//speaceCellNum�̎q��Ԃ̏���
		//�q��ԂɈ�F�ɂ���speaceCellNum�Ԗڂ̋�Ԃ�LinerObject��CollisionStack�ɓ��ꂽ���ǂ���
		bool childFlag = false;
		//�q��Ԃ̃I�u�W�F�N�g�̐�
		unsigned int objNum = 0;
		//unsigned int i;
		unsigned int nextSpaceCellNum;
		int levelNum = CollisionDetectionSettingImpl::GetNowLevelCellNum();
		for (int i = 0; i < 4; i++)
		{
			nextSpaceCellNum = speaceCellNum * 4 + 1 + i;
			if (nextSpaceCellNum < levelNum&&mSpaceCellArray[nextSpaceCellNum])
			{
				if (childFlag == false) {
					linerObj1 = mSpaceCellArray[speaceCellNum].value().GetFirstLinerObject();
					while (linerObj1) {
						collisionStack.emplace_back(linerObj1.value());
						objNum++;
						linerObj1 = linerObj1.value()->mNextObject;
					}
				}

				childFlag = true;
				collisionStack = RecursionSearchTree(std::move(collisionStack), nextSpaceCellNum);
			}
		}

		//���̊֐��ɖ߂��Ă����炱���Œǉ��������폜
		if (childFlag)
			for (int i = 0; i < objNum; i++)
				collisionStack.pop_back();

		return std::move(collisionStack);
	}





}