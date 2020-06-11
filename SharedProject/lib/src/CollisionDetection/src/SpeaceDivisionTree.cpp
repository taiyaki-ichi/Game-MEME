#include"lib/src/CollisionDetection/SpaceDivisionTree.hpp"
#include"lib/src/CollisionDetection/LinerObject.hpp"
#include"lib/src/CollisionDetection/CollisionDetectionSettingImpl.hpp"
#include"lib/include/CollisionDetection/Collider.hpp"
#include"lib/src/CollisionDetection/MortonNumber.hpp"
#include"lib/include/Math/Vector2Func.hpp"
#include"lib/src/CollisionDetection/SpaceCell.hpp"

#include<iostream>

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
	{
		mAllSpaceCellNum = (CollisionDetectionSettingImpl::GetPowerOfFour(TREE_MAX_LEVEL+1) - 1) / 3;
		mSpaceCellArray = new SpaceCell * [mAllSpaceCellNum];
		mSpaceCellArray[0] = new SpaceCell(0);
		for (int i = 1; i < mAllSpaceCellNum; i++) {
			mSpaceCellArray[i] = nullptr;
		}
		
	}

	SpaceDivisionTree::~SpaceDivisionTree()
	{
		DeleteSpaceCell(0);
		delete mSpaceCellArray[0];
		delete[] mSpaceCellArray;
	
	}

	bool SpaceDivisionTree::Resist(LinerObject* linerObj)
	{
		linerObj->mNextObject = nullptr;
		linerObj->mNextObject = nullptr;

		auto collider = linerObj->GetCollider();
		float scale = collider->GetScale();
		float width = collider->GetWidth();
		float heigth = collider->GetHeigth();
		auto pos = collider->GetPosition();

		//squrt�g���Đ����ɂ�邩�H�H
		float halfUnitSize = (width * scale + heigth * scale) / 2.f;

		int spaceCellNum = GetMortonNumber(pos.x - halfUnitSize, pos.y + halfUnitSize, pos.x + halfUnitSize, pos.y - halfUnitSize);

		if (spaceCellNum < mAllSpaceCellNum)
		{
			//��ԃI�u�W�F�N�g���Ȃ��ꍇ�쐬
			if (!mSpaceCellArray[spaceCellNum])
				CreateNewSpaceCell(spaceCellNum);

			mSpaceCellArray[spaceCellNum]->Push(linerObj);

			return true;
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
		while (mSpaceCellArray[spaceNum] == nullptr)
		{
			mSpaceCellArray[spaceNum] = new SpaceCell(spaceNum);

			//�e��Ԃ�
			spaceNum = (spaceNum - 1) >> 2;
			if (spaceNum >= mAllSpaceCellNum)
				break;
		}
	}

	void SpaceDivisionTree::DeleteSpaceCell(int spaceNum)
	{
		for (int i = 0; i < 4; i++)
		{
			int childNum = spaceNum * 4 + 1 + i;
			if (childNum < mAllSpaceCellNum && !mSpaceCellArray[childNum]) {
				DeleteSpaceCell(childNum);
				delete mSpaceCellArray[childNum];
			}
		}

	}


	std::list<LinerObject*> SpaceDivisionTree::RecursionSearchTree(std::list<LinerObject*>&& collisionStack, int speaceCellNum)
	{
		LinerObject* linerObj1 = mSpaceCellArray[0]->GetFirstLinerObject();
		LinerObject* linerObj2 = nullptr;

		while (linerObj1)
		{
			//mSpeaceCellArray�ɘA�Ȃ���`���X�g�Ƃ̓����蔻��(linerObj1�ȍ~�̐��`���X�g)
			//���Ȃ킿�����������ꂽ��ԓ���Collider�Ƃ̓����蔻��
			linerObj2 = linerObj1->mNextObject;
			while (linerObj2)
			{
				DoCollisionDetection(linerObj1, linerObj2);
				linerObj2 = linerObj2->mNextObject;
			}

			//collisionStack�ɂ���Collider�Ƃ̓����蔻��A�܂�
			//linerObj1�������镪�����ꂽ��Ԃɂ܂�����悤�ȁA�܂�
			//linerObj1�������镪�����ꂽ��Ԃ��傫�ȕ�����Ԃɑ�����Collider�Ƃ̓����蔻��
			if (!collisionStack.empty())
			{
				for (auto linerObj : collisionStack)
				{
					DoCollisionDetection(linerObj1, linerObj);
				}
			}

			linerObj1 = linerObj1->mNextObject;
		}
		
		//speaceCellNum�̎q��Ԃ̏���
		//�q��ԂɈ�F�ɂ���speaceCellNum�Ԗڂ̋�Ԃ�LinerObject��CollisionStack�ɓ��ꂽ���ǂ���
		bool childFlag = false;
		//�q��Ԃ̃I�u�W�F�N�g�̐�
		unsigned int objNum = 0;
		unsigned int i;
		unsigned int nextSpaceCellNum;

		for (int i = 0; i < 4; i++)
		{
			nextSpaceCellNum = speaceCellNum * 4 + 1 + i;
			//
			if (nextSpaceCellNum < CollisionDetectionSetting::GetLevel()&&mSpaceCellArray[nextSpaceCellNum])
			{
				if (childFlag == false) {
					linerObj1 = mSpaceCellArray[speaceCellNum]->GetFirstLinerObject();
					while (linerObj1) {
						collisionStack.emplace_back(linerObj1);
						objNum++;
						linerObj1 = linerObj1->mNextObject;
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