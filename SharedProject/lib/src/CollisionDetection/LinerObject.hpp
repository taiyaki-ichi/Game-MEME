#pragma once
#include"lib/include/CollisionDetection/Collider.hpp"
#include<optional>

namespace GameLib
{

	//��ԃI�u�W�F�N�g�ɕR�Â���悤
	class LinerObject
	{
		Collider* mCollider;

	public:
		LinerObject(Collider* collidr)
			:mCollider(collidr)
			,mPreObject(std::nullopt)
			,mNextObject(std::nullopt)
		{}
		~LinerObject() = default;

		//�O�ƌ��
		std::optional<LinerObject*> mPreObject;
		std::optional<LinerObject*> mNextObject;

		Collider* GetCollider() const noexcept {
			return mCollider;
		}
	};

}