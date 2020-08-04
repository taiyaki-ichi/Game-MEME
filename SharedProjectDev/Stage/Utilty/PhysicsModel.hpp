#pragma once
#include<utility>
#include"GameLib/include/Math/Vector2.hpp"


namespace Stage
{
	struct PhysicsModel 
	{
		GameLib::Vector2 mPosition;
		GameLib::Vector2 mVelocity;
		float mScale;
		float mRotation;

		PhysicsModel(GameLib::Vector2&& pos = { 0.f,0.f }, GameLib::Vector2&& velocity = { 0.f,0.f }, float scale = 1.f, float rot = 0.f)
			:mPosition(std::move(pos))
			, mVelocity(std::move(velocity))
			, mScale(scale)
			, mRotation(rot)
		{}
		PhysicsModel(const GameLib::Vector2& pos = { 0.f,0.f }, GameLib::Vector2&& velocity = { 0.f,0.f }, float scale = 1.f, float rot = 0.f)
			:mPosition(std::move(pos))
			, mVelocity(std::move(velocity))
			, mScale(scale)
			, mRotation(rot)
		{}
		virtual ~PhysicsModel() = default;

		//�͂��瑬�x�ƈʒu�̍X�V,maxSpeed��<0.f�̎�����
		void Update(const GameLib::Vector2 & power = { 0.f,0.f }, float maxSpeedX = -1.f, float maxSpeedY = -1.f) {
			mVelocity += power;

			if (maxSpeedX > 0.f && std::abs(mVelocity.x) > maxSpeedX)
				mVelocity.x = (mVelocity.x < 0.f) ? -maxSpeedX : maxSpeedX;
			if (maxSpeedY > 0.f && std::abs(mVelocity.y) > maxSpeedY)
				mVelocity.y = (mVelocity.y < 0.f) ? -maxSpeedY : maxSpeedY;

			mPosition += mVelocity;
		}

		//���C�݂�����
		void Friction(float xRate, float yRate) {
			mVelocity.x *= xRate;
			mVelocity.y *= yRate;
		}
	};
}