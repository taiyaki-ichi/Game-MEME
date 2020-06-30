#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"Game/Dir4.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"Game/Dir4Vec.hpp"
#include"Game/Stage/PhysicsModel.hpp"

namespace Game::Stage
{
	class GravityActor : public GameLib::Actor
	{
	protected:
		static float mGravity;
		static Dir4 mGravityDir4;

		GameLib::Vector2 GetGravityVector2();

		//�d�͂̕��������Ƃ����Ƃ��́A�傫��size�̌���dir�ȃx�N�g��
		GameLib::Vector2 GetVector2(const Dir4& dir, float size);

		//Vector2��Dir4Vec�Ɋۂߍ���
		Dir4Vec GetRoundedDir4Vec(const GameLib::Vector2& vec);

		//�x�N�g���̌���Dir4�̑傫��
		float GetDir4Size(const GameLib::Vector2& vec, const Dir4& dir);

		//Gravity�̊p�x
		float GetGravityRotation();

		//�����A���������̔��]
		GameLib::Vector2 GetVerticalFlippedVector2(const GameLib::Vector2& vec);
		GameLib::Vector2 GetHolizonalFlippedVector2(const GameLib::Vector2& vec);

		//�t���[��������̗͂̍��v��d�͂̕����𓥂܂��čX�V
		void UpdatePhysicsModel(PhysicsModel& model,const GameLib::Vector2& power, float horizonMaxSpeed = -1.f, float virticalMaxSpeed = -1.f);


	public:
		GravityActor(Actor* owner,int udpateOder=0)
			:Actor(owner,udpateOder)
		{}
		virtual ~GravityActor() = default;

		static const float GetGravity() noexcept {
			return mGravity;
		}
		static void SetGravity(float g) noexcept {
			mGravity = g;
		}
		static const Dir4& GetGravityDir4() noexcept {
			return mGravityDir4;
		}
		static void SetGraviyuDir4(Dir4&& d) noexcept {
			mGravityDir4 = std::move(d);
		}
		static void SeGravityDir4(const Dir4& g) noexcept {
			mGravityDir4 = g;
		}


	};
}