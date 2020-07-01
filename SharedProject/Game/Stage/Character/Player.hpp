#pragma once
#include"Game/Stage/GravityActor.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Game/Stage/PhysicsModel.hpp"


namespace Game::Stage
{
	/*
	class Player : public GravityActor
	{
		constexpr static float MAX_HORIZON_SPEED = 5.5f;
		constexpr static float MAX_VERTICAL_SPEED = 21.f;
		constexpr static float JUMP_POWER_MAX = 9.f;
		constexpr static float JUMP_POWER_MIN = 7.f;
		constexpr static float RUN_POWER = 0.2f;
		constexpr static float JUMPING_GRAVITY_RATE = 0.8f;

		GameLib::DrawAnimation mAnimation;
		GameLib::Collider mCollider;

		PhysicsModel mPhysicsModel;

		constexpr static char ON_GROUND_FLAG = 0b00000001;
		char mFlags;

		int mJumpFlag;

	public:
		Player(Actor* owner, int updateOrder = 0);
		virtual ~Player() = default;
		void CustomizeUpdate() override;

	private:
		GameLib::Vector2 GetPowerPerFrame();
		void UpdateAnimation(const GameLib::Vector2& power);
		void UpdateCollider();

	};

	*/
}


namespace Game::Stage::Player
{
	class Actor : public GameLib::Actor
	{
		GameLib::DrawAnimation mAnimation;

	public:
		Actor(GameLib::Actor* owner,GameLib::Vector2&& pos, int updateOrder = 0);
		virtual ~Actor() = default;

		void CustomizeUpdate() override;

		void SetAnamtion(const GameLib::Vector2& pos, float scale, float rot, int channel = -1);

	};

	class Active : public GravityActor
	{
		constexpr static float MAX_HORIZON_SPEED = 5.5f;
		constexpr static float MAX_VERTICAL_SPEED = 21.f;
		constexpr static float JUMP_POWER_MAX = 9.f;
		constexpr static float JUMP_POWER_MIN = 7.f;
		constexpr static float RUN_POWER = 0.2f;
		constexpr static float JUMPING_GRAVITY_RATE = 0.85f;

		GameLib::Collider mCollider;
		PhysicsModel mPhysicsModel;

		constexpr static char ON_GROUND_FLAG = 0b00000001;
		char mFlags;

		int mJumpFlag;

		//�A�j���[�V�����ւ̎Q��
		GameLib::DrawAnimation* mAnimation;

	public:
		Active(Actor* player, GameLib::Vector2&& pos,GameLib::DrawAnimation* anim);
		virtual ~Active() = default;

		void CustomizeUpdate() override;

	private:
		GameLib::Vector2 GetPowerPerFrame();
		void UpdateAnimation(const GameLib::Vector2& power);
		void UpdateCollider();
	};



}