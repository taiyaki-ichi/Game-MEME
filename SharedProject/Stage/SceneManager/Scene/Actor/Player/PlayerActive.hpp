#pragma once
#include"PlayerStateBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Stage/Utilty/PhysicsModel.hpp"

namespace GameLib
{
	class DrawAnimation;
}

namespace Stage
{
	class Life;
	class ItemNum;
}

namespace Stage::PlayerState
{

	class Active : public StateBase
	{
		GameLib::Collider mCollider;
		PhysicsModel mPhysicsModel;

		//���t���[���̊Ԃ̓W�����v���\�ɂ��邽�߂̃t���O
		int mJumpFlag;

		//�A�j���[�V�����ւ̎Q��
		GameLib::DrawAnimation* mAnimation;

		int mInvincibleCnt;

		Stage::Life* mLife;
		Stage::ItemNum* mItemNum;

	public:
		Active(GameLib::DrawAnimation* anim,Stage::Life* life,Stage::ItemNum* itemNum);
		virtual ~Active() = default;

		Stage::StateBase<char>* Update() override;

		//Stage�̍Œ���Player��ActivePause�𗘗p���邱�ƂȂ��ˁH�H
		void BeginWorking() override {};
		void BeginToRest() override {};

		void SetPosition(const GameLib::Vector2 & pos) override;

		void ResetPotentialPower() override;

	private:
		//physicsModel�Ɋ�Â���Collider���X�V
		void AdjustCollider();

		//���̃t���[���ł̗͂̍��v���擾
		GameLib::Vector2 GetPowerPerFrame();

		//Anim�̍X�V�A�t���[�����ɌĂяo��
		//�p���[�������Ɍ�����ς���
		void UpdateAnimation(GameLib::Vector2 && power);

		//�����������ǂ���
		void CheckFallDeath();

		//�_���[�W���󂯂���
		void SufferDamage();
	};
}