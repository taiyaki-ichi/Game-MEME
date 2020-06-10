#pragma once

namespace GameLib
{
	class Collider;
	class Cell;

	//��ԃI�u�W�F�N�g�ɕR�Â���悤
	class LinerObject
	{
		Collider* mCollider;

	public:
		LinerObject(Collider* collidr)
			:mCollider(collidr)
		{}
		~LinerObject() = default;

		//�O�ƌ��
		LinerObject* mPreObject;
		LinerObject* mNextObject;

		//����������
		Cell* mCell;

		Collider* GetCollider() const noexcept {
			return mCollider;
		}
	};

}