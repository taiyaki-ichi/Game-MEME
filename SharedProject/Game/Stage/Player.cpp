#include"Player.hpp"
#include"Gravity.hpp"
#include"UtilityVectorFunction.hpp"
#include"GameLib/include/InputState/InputState.hpp"

#include<iostream>

namespace Game::Stage::Player
{

	Actor::Actor(GameLib::Actor* owner, std::vector<float>&& data)
		:GameLib::Actor{owner}
		, mAnimation{ 10 }
	{
		using namespace GameLib;

		Vector2 pos{ data[0],data[1] };

		mAnimation.AddAnimation({ "../Assets/Player/stay001.png" });
		mAnimation.AddAnimation({ "../Assets/Player/run001.png","../Assets/Player/run002.png" ,"../Assets/Player/run003.png","../Assets/Player/run002.png" });
		mAnimation.AddAnimation({ "../Assets/Player/up.png" });
		mAnimation.AddAnimation({ "../Assets/Player/down.png" });
		mAnimation.AddAnimation({ "../Assets/Player/death.png" });
		mAnimation.SetScale(0.1f);
		mAnimation.SetDrawOrder(50);
		mAnimation.SetPosition(pos);

		new Active(this, std::move(pos), &mAnimation);
	}

	void Actor::CustomizeUpdate()
	{

	}

	void Actor::SetAnamtion(const GameLib::Vector2& pos, float scale, float rot, int chanel)
	{
		mAnimation.Set(pos, scale, rot);
		if (chanel >= 0)
			mAnimation.SetChannel(chanel);
	}

	GameLib::Vector2 Actor::GetPositon()
	{
		return mAnimation.GetPosition();
	}


	Active::Active(Actor* player, GameLib::Vector2&& pos, GameLib::DrawAnimation* anim)
		:GameLib::Actor{player}
		, mCollider{ "Player" }
		, mPhysicsModel{ std::move(pos),GameLib::Vector2{0.f,0.f},0.1f,0.f }
		, mFlags{ 0 }
		, mJumpFlag{ 0 }
		, mAnimation{ anim }
	{
		using namespace GameLib;

		mCollider.Set(mPhysicsModel.mPosition, 250.f, 500.f, 0.1f, 0.f);
		mCollider.SetColor({ 255,0,0,255 });
		UpdateCollider();

		auto hitGround = [this](const GameLib::Collider& c) {
			auto adjust = GetParallelRectAdjustVec(mCollider, c, 0.5f);
			auto dir4Vec = Gravity::GetDir4Vec(adjust);

			mPhysicsModel.mPosition += adjust;

			if (adjust.x * mPhysicsModel.mVelocity.x < 0.f)
				mPhysicsModel.mVelocity.x = 0.f;
			else if (adjust.y * mPhysicsModel.mVelocity.y < 0.f)
				mPhysicsModel.mVelocity.y = 0.f;

			if (dir4Vec.mDir4 == Dir4::Up) {
				mFlags |= ON_GROUND_FLAG;
				mJumpFlag = 1;
			}

			if ((InputState::GetState(Key::A) == ButtonState::None &&
				InputState::GetState(Key::D) == ButtonState::None) ||
				(InputState::GetState(Key::A) == ButtonState::Held &&
					InputState::GetState(Key::D) == ButtonState::Held) ||
				(InputState::GetState(Key::A) == ButtonState::Held &&
					Gravity::GetDir4Size(mPhysicsModel.mVelocity, Dir4::Right) > 0.f) ||
				(InputState::GetState(Key::D) == ButtonState::Held &&
					Gravity::GetDir4Size(mPhysicsModel.mVelocity, Dir4::Left) > 0.f
					))

			{
				if (dir4Vec.mDir4 == Dir4::Up) {
					if (Gravity::GetGravityDir4() == Dir4::Up || Gravity::GetGravityDir4() == Dir4::Down)
						mPhysicsModel.Friction(0.8f, 1.f);
					else
						mPhysicsModel.Friction(1.f, 0.8f);
				}
			}

			UpdateCollider();
			mAnimation->SetPosition(mPhysicsModel.mPosition);
		};

		auto hitEnemyWeakness = [this](const GameLib::Collider& c) {
			float upSize = Gravity::GetDir4Size(mPhysicsModel.mVelocity, Dir4::Up);
			mPhysicsModel.mVelocity += Gravity::GetVector2(Dir4::Up, -upSize + 3.f);

			//4�t���[���̊Ԃ̓W�����v�ł���
			mJumpFlag = 4;
		};

		auto hitEnemyStrength = [this](const GameLib::Collider& c) {
			SetState(Actor::State::Dead);
			new Death(mOwner, mPhysicsModel, mAnimation);
		};

		mCollider.AddHitFunction("Ground", std::move(hitGround));
		mCollider.AddHitFunction("TripleWeakness", hitEnemyWeakness);
		mCollider.AddHitFunction("TripleStrength", hitEnemyStrength);
		mCollider.AddHitFunction("TogeStrength", hitEnemyStrength);

	}

	void Active::CustomizeUpdate()
	{

		auto power = GetPowerPerFrame();
		Gravity::UpdatePhysicsModel(mPhysicsModel, power, MAX_HORIZON_SPEED, MAX_VERTICAL_SPEED);
		UpdateCollider();
		UpdateAnimation(std::move(power));

		mFlags &= ~ON_GROUND_FLAG;

		//std::cout << "jumpFlag: " << mJumpFlag << "\n";

		if (mJumpFlag > 0)
			mJumpFlag--;


	}


	GameLib::Vector2 Active::GetPowerPerFrame()
	{
		using namespace GameLib;
		Vector2 power{ 0.f,0.f };

		//�d��
		if (~(mFlags & ON_GROUND_FLAG) &&
			Gravity::GetDir4Size(mPhysicsModel.mVelocity, Dir4::Up) > 0.f &&
			InputState::GetState(Key::Space) == ButtonState::Held)
			power += Gravity::GetGravityVector2() * JUMPING_GRAVITY_RATE;
		else
			power += Gravity::GetGravityVector2();

		//���R�̗�
		if (InputState::GetState(Key::A) == ButtonState::Pressed ||
			InputState::GetState(Key::A) == ButtonState::Held) {
			power += Gravity::GetVector2(Dir4::Left, RUN_POWER);
		}
		if (InputState::GetState(Key::D) == ButtonState::Pressed ||
			InputState::GetState(Key::D) == ButtonState::Held)
			power += Gravity::GetVector2(Dir4::Right, RUN_POWER);

		//�W�����v
		if (InputState::GetState(Key::Space) == ButtonState::Pressed &&
			(mJumpFlag > 0)) {

			auto v = Gravity::GetDir4Vec(mPhysicsModel.mVelocity);
			float rate = std::abs(v.mSize) / MAX_HORIZON_SPEED;
			power += Gravity::GetVector2(Dir4::Up, (JUMP_POWER_MAX - JUMP_POWER_MIN) * rate + JUMP_POWER_MIN);

			mJumpFlag = 0;
		}

		//std::cout << "power: "<<power.x << "," << power.y << "\n";
		return power;
	}
	void Active::UpdateAnimation(const GameLib::Vector2& power)
	{

		mAnimation->Update();

		mAnimation->SetPosition(mPhysicsModel.mPosition);
		mAnimation->SetRotation(mPhysicsModel.mRotation);

		float horizonPowerDir = Gravity::GetDir4Size(power, Dir4::Right);
		float verticalDir = Gravity::GetDir4Size(mPhysicsModel.mVelocity, Dir4::Up);
		if (!(mFlags & ON_GROUND_FLAG) && verticalDir < 0.f)
			mAnimation->SetChannel(3);
		else if (!(mFlags & ON_GROUND_FLAG) && verticalDir > 0.f)
			mAnimation->SetChannel(2);
		else if (horizonPowerDir == 0.f)
			mAnimation->SetChannel(0);
		else
			mAnimation->SetChannel(1);

		if (horizonPowerDir > 0.f)
			mAnimation->SetHorizontalFlip(false);
		else if (horizonPowerDir < 0.f)
			mAnimation->SetHorizontalFlip(true);

	}

	void Active::UpdateCollider()
	{
		mCollider.SetRotation(mPhysicsModel.mRotation);
		mCollider.SetPosition(mPhysicsModel.mPosition + Gravity::GetVector2(Dir4::Down, 12.f));
	}

	Death::Death(Actor* player, const PhysicsModel& model, GameLib::DrawAnimation* anim)
		:GameLib::Actor{player}
		, mCnt{ 0 }
		, mPosition{ model.mPosition }
		, mScale{ model.mScale }
		, mRotation{ model.mRotation }
		, mAnimation{ anim }
	{
		mAnimation->SetChannel(4);
	}

	void Death::CustomizeUpdate()
	{
		mCnt++;
		if (mCnt > DEATH_CNT)
			mOwner->SetState(Actor::State::Dead);

		mPosition += Gravity::GetVector2(Dir4::Up, 4.f);
		mScale *= 0.99f;
		mRotation += 0.3f;

		mAnimation->Set(mPosition, mScale, mRotation);

	}
}