#pragma once
#include"lib/include/CollisionDetection/Collider.hpp"

namespace GameLib
{

	//��ԃI�u�W�F�N�g�ɕR�Â���悤
	class LinerObject
	{
		Collider* mCollider;

	public:
		LinerObject(Collider* collidr)
			:mCollider(collidr)
			,mPreObject(nullptr)
			,mNextObject(nullptr)
		{}
		~LinerObject() = default;

		//�O�ƌ��
		LinerObject* mPreObject;
		LinerObject* mNextObject;

		Collider* GetCollider() const noexcept {
			return mCollider;
		}
	};

}