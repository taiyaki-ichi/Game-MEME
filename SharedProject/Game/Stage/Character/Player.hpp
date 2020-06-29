#pragma once
#include"GravityActor.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Game/Stage/PhysicsModel.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"Game/Stage/UtilityVectorFunction.hpp"
#include"GameLib/include/Math/Numbers.hpp"


namespace Game::Stage
{
	class Player : public GravityActor
	{
		constexpr static float MAX_SPEED = 5.5f;
		constexpr static  float JUMP_POWER_MAX = 9.f;
		constexpr static  float JUMP_POWER_MIN = 7.f;
		constexpr static  float RUN_POWER = 0.2f;

		GameLib::DrawAnimation mAnimation;
		GameLib::Collider mCollider;

		PhysicsModel mPhisicsModel;

		constexpr static char JUMP_FLAG_1 = 0b00000001;
		constexpr static char ON_GROUND_FLAG = 0b00000010;
		char mFlags;

	public:
		Player(Actor* owner, int updateOrder = 0);
		virtual ~Player() = default;
		void CustomizeUpdate() override;

	private:
		GameLib::Vector2 GetPowerPerFrame();
		void UpdateAnimation(const GameLib::Vector2& power);
		void UpdateCollider();

	};
}