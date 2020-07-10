#pragma once
#include"ActorBase.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Game/Stage/PhysicsModel.hpp"
#include"Game/Dir4.hpp"
#include"State/StateManager.hpp"

namespace Game::Stage::Triple
{
	class Actor : public ActorBase
	{
		GameLib::DrawAnimation mAnimation;

		StateManager mStateManager;

	public:
		Actor(Scene* scene, std::vector<float>&& data);
		virtual ~Actor() = default;

		//�A�j���[�V�����̈ʒu�Ŕ��f
		bool UpdateOrNot() override;
		//StateManager�̍X�V
		void UpdateActor() override;

		void Active() override;
		void Pause() override;
	};


	class TripleActive : public StateBase
	{
		constexpr static float RUN_POWER = 0.2f;
		constexpr static float MAX_SPEED = 1.f;

		//�A�j���[�V�����ւ̎Q��
		GameLib::DrawAnimation* mAnimation;

		GameLib::Collider mBody;
		GameLib::Collider mWeakness;
		GameLib::Collider mStrength;

		PhysicsModel mPhysicsModel;
		Dir4 mDir4;

		bool mFlatDeathFlag;

	public:
		TripleActive(GameLib::Vector2&& pos, GameLib::DrawAnimation* anim);
		virtual ~TripleActive() = default;

		StateBase* Update() override;

		//�ύX�𔽉f
		void ReflectAnimation();
		void ReflectCollider();

		void Active() override;
		void Pause() override;

	};

	class FlatDeath : public StateBase
	{
		constexpr static float DEATH_TIME = 30;
		int mCnt;
	public:
		FlatDeath(GameLib::DrawAnimation* anim);
		virtual ~FlatDeath() = default;

		StateBase* Update() override;
		int GetFlag() override;

		void Active() override {};
		void Pause() override {};
	};

}